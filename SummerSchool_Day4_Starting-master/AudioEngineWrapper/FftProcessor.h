#pragma once

#include "SignalGeneratorWrapper.h"

namespace AudioEngineWrapper
{
  public ref class FftProcessor
  {
  public:

    array<double>^ GetMagnitude(SignalGenerator^ generator);
  };
}

