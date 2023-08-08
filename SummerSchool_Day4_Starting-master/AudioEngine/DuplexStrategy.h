#pragma once

#include "IAudioStrategy.h"
#include <memory>

namespace AudioEngine
{
	class DuplexStrategy
	{
	public:
		virtual bool Init(const AudioParameters& params);
		virtual bool Uninit();
		virtual void OnCallback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);
		virtual const void* ChooseData(const void* input, const void* output);

	private:
		std::unique_ptr<ma_device> m_device;
	};
}

