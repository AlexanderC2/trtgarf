#ifndef _TRTElectronics_Shaper_
#define _TRTElectronics_Shaper_
#include "Signals/Signal.hpp"
#include "Signals/HighPass.hpp"
#include "Signals/LowPass.hpp"
#include "Signals/Scale.hpp"
#include "TRTElectronics/IntPoleZero.hpp"
#include <iostream>

namespace TRT
{

class ASDBLRShaper:public Signals::Signal
{
  protected:

  void Apply(Signal& ASource);

  public:
  // Integrator, Stage 1
  std::vector<double>& F1ScaleCoefficients;
  std::vector<double>& F1DeltaCoefficients;
  std::vector<double>& F1DecayCoefficients;
  // Pole Zero Network, Stage 2
  // Sub1:Pole Zero part
  std::vector<double>& F2Delta1Coefficients;
  std::vector<double>& F2Decay1Coefficients;
  std::vector<double>& F2Delta2Coefficients;
  std::vector<double>& F2Decay2Coefficients;
  std::vector<double>& F2Weight2Coefficients;
  // Sub2:Differentiazor part
  std::vector<double>& F2ScaleCoefficients;
  std::vector<double>& F2DiffCoefficients;
  std::vector<double>& F2DecayCoefficients;
  double& FDelay;

  Signals::Scale     F1Scale;
  Signals::HighPass  F1HighPass;
  IntPoleZero        F2PoleZero;
  Signals::Scale     F2Scale;
  Signals::LowPass   F2LowPass;

  ASDBLRShaper(double ASignalBinTime);

  void SaveCoefficientsToStream(Tools::ASCIIOutStream& AStream);
  void Debug(std::string AIndent="");
};

}

#endif
