#include "pch.h"
#include "FftProcessor.h"
#include "../AudioEngine/fft.hpp"
#include "Utils.h"
#include "../AudioEngine/FFTProcessor.h"

array<double>^ AudioEngineWrapper::FftProcessor::GetMagnitude(SignalGenerator^ generator)
{
    const auto data = generator->GetBuffer();
    const char* error;

    array<double>^ result = gcnew array<double>(data.size() / 2);
    if (!AudioEngine::FFTProcessor::GetFFTMagnitudeWithBuffer(data, result, error))
    {
        throw gcnew System::Exception(gcnew System::String(error));
    }

    return result;
}
