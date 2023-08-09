#pragma once

using namespace System;

#include "../AudioEngine/AudioEngine.h"
#include "../AudioEngine/AudioEngine.h"

namespace AudioEngineWrapper
{
	//TODO #8
	public enum class AudioStrategyType {
		Duplex = 0,
	};
	

	public ref class AudioEngineService
	{
		//TODO #9
		//Create a wrapper over AudioEngine Cpp functions

	public:
		AudioEngineService(size_t sampleRate, size_t maxBufferSize);

		void Start(AudioStrategyType strategyType);

		void Stop();

		void ClearBuffer();

		array<double>^ GetBuffer();

	internal:
		std::vector<float> GetLastBuffer();

	private:
		//TODO #10
		//Declare a pointer to an instance of the Audio Engine class
		AudioEngine::FancyAudioEngine* engine;
	};
}
