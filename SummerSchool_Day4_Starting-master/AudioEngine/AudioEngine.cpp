#include "pch.h"

#include <exception>
#include "AudioEngine.h"
#include <stdio.h>
#include <mutex>

namespace AudioEngine
{
	FancyAudioEngine* _instance = nullptr;

	void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
	{
		_instance->callback(pDevice, pOutput, pInput, frameCount);
	}

	void FancyAudioEngine::ClearBuffer()
	{
		m_mutex.Lock();

		if (m_buffers.size() > 0)
		{
			m_buffers.erase(m_buffers.begin());
		}

		m_mutex.Unlock();
	}

	const std::vector<float>& FancyAudioEngine::GetBufferData() noexcept
	{
		m_mutex.Lock();

		if (m_buffers.size() == 0)
		{
			m_buffers.emplace_back();
		}

		auto& result = m_buffers.front();

		if (result.size() < m_maxBufferSize)
		{
			result.resize(m_maxBufferSize);
		}

		m_mutex.Unlock();

		return result;
	}

	void FancyAudioEngine::callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
	{
		//TODO #7
		//Call the OnCallback method of the current strategy to process audio data with the given frame count and device parameters

		if (m_buffers.size() == 0)
		{
			m_buffers.emplace_back();
			m_buffers.back().reserve(m_maxBufferSize);
		}

		float* buffer = (float*)pOutput;
		//float* input = (float*)m_strategy->ChooseData(pInput, pOutput);

		for (size_t i = 0; i < frameCount; i++)
		{
			m_mutex.Lock();
			if (m_buffers.back().size() >= m_maxBufferSize)
			{
				m_buffers.emplace_back();
				m_buffers.back().reserve(m_maxBufferSize);
			}
			auto& currentBuffer = m_buffers.back();
			currentBuffer.push_back(buffer[i]); //change with input
			m_mutex.Unlock();
		}
	}
}