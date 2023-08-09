#include "pch.h"

#include "AudioEngineWrapper.h"
#include <exception>
#include "Utils.h"

using namespace System::Diagnostics;

AudioEngineWrapper::AudioEngineService::AudioEngineService(size_t sampleRate, size_t maxBufferSize)
{
    try {
        engine = new AudioEngine::FancyAudioEngine(sampleRate, maxBufferSize);
    }
    catch(std::exception e)
    {
        Debug::Assert(false, gcnew System::String(e.what()));
    }
}

void AudioEngineWrapper::AudioEngineService::Start(AudioStrategyType strategyType)
{
    try
    {
        engine->Start((AudioEngine::AudioStrategyType)strategyType);
    }
    catch (const std::exception e)
    {
        Debug::Assert(false, gcnew System::String(e.what()));

    }
}

void AudioEngineWrapper::AudioEngineService::Stop()
{
    engine->Stop();
}

void AudioEngineWrapper::AudioEngineService::ClearBuffer()
{
    engine->ClearBuffer();
}

array<double>^ AudioEngineWrapper::AudioEngineService::GetBuffer()
{
    const auto& buffer = engine->GetBufferData();
    // TODO: insert return statement here
    return Utils::ConvertToMananged<float, double>(buffer, buffer.size());
}


std::vector<float> AudioEngineWrapper::AudioEngineService::GetLastBuffer()
{
    const auto& buffer = engine->GetBufferData();
    return buffer;
}
