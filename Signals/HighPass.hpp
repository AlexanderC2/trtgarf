#ifndef _Signals_HighPass_
#define _Signals_HighPass_
#include "Signals/Signal.hpp"
#include "Tools/Stream.hpp"

namespace Signals
{

class HighPass:public Signal
{
  protected:
  virtual void Apply(Signal& ASource);
  public:
  // These coefficients are standard RC integrator coefficients
  std::vector<double> FDeltaCoefficients;
  // These are extra coefficients which add "decay"
  std::vector<double> FDecayCoefficients;
  // Delay in signal time unis
  double FDelay;
  HighPass(double ASignalBinTime):Signal(ASignalBinTime){};
  void SaveCoefficientsToStream(Tools::ASCIIOutStream& AStream);
  void Debug(std::string AIndent="");
};

}

#endif
