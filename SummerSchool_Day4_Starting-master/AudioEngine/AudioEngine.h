#pragma once

#include <vector>
#include "ImportExport.h"
#include "miniaudio.h"
#include <memory>
#include <limits>
#include "AudioLock.h"
#include "IAudioStrategy.h"

namespace AudioEngine
{
	enum class AudioStreategyType
	{
		Duplex = 0,
		Loopback,
	};

	class AUDIOENGINE_API FancyAudioEngine
	{
	public:

		//TODO #6
		//Add constructor
		//Add Start and Stop methods

		void ClearBuffer();

		const std::vector<float>& GetBufferData() noexcept;

	private:
		ma_device* m_device;
		std::vector<std::vector<float>> m_buffers;

		size_t m_maxBufferSize;
		size_t m_sampleRate;

		void callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);
		friend void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);

		std::unique_ptr<IAudioStrategy> m_strategy;

		AudioLock m_mutex;
	};
}

