#pragma once

using namespace System;

#include "../AudioEngine/AudioEngine.h"

namespace AudioEngineWrapper
{
	//TODO #8
	//Create an enum for the strategy type
	

	public ref class AudioEngineService
	{
		//TODO #9
		//Create a wrapper over AudioEngine Cpp functions

	internal:
		std::vector<float> GetLastBuffer();

	private:
		//TODO #10
		//Declare a pointer to an instance of the Audio Engine class
	};
}
