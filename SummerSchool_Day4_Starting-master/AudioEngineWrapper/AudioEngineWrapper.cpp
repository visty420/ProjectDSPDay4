#include "pch.h"

#include "AudioEngineWrapper.h"
#include <exception>
#include "Utils.h"

using namespace System::Diagnostics;

std::vector<float> AudioEngineWrapper::AudioEngineService::GetLastBuffer()
{
    return std::vector<float>();
}
