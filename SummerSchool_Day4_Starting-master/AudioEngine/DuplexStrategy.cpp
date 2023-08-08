#include "DuplexStrategy.h"
#include <cstring>

namespace AudioEngine
{
	bool DuplexStrategy::Init(const AudioParameters& params)
	{
		//TODO #2
		//Initialize the duplex audio device with the given parameters and start it
		//Check for initialization errors
		return true;
	}

	bool DuplexStrategy::Uninit()
	{
		//TODO #3 
		//Uninit the device

		return true;
	}

	void DuplexStrategy::OnCallback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
	{
		//TODO #4
		//Copy input audio data directly to the output buffer using the specified frame count and format.
	}

	const void* DuplexStrategy::ChooseData(const void* input, const  void* output)
	{
		//TODO #5
		//Choose data by returning the input

		return nullptr;
	}
}
