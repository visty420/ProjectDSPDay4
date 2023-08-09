#include "LoopbackStrategy.h"

bool AudioEngine::LoopbackStrategy::Init(const AudioParameters& params)
{
    
}

bool AudioEngine::LoopbackStrategy::Uninit()
{
    
}

void AudioEngine::LoopbackStrategy::OnCallback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
    deviceConfig = ma_device_config_init(ma_device_type_playback);
    deviceConfig.playback.format = decoder.outputFormat;
    deviceConfig.playback.channels = decoder.outputChannels;
    deviceConfig.sampleRate = decoder.outputSampleRate;
    deviceConfig.dataCallback = data_callback;
    deviceConfig.pUserData = &decoder;

}

const void* AudioEngine::LoopbackStrategy::ChooseData(const void* input, const void* output)
{
    
}
