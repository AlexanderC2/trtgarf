#ifndef _Signals_LowPass_
#define _Signals_LowPass_
#include "Signals/Signal.hpp"

namespace Signals
{

class LowPass:public Signal
{
  protected:
  void Apply(Signal& ASource);
  public:
  std::vector<double> FDiffCoefficients;
  std::vector<double> FDecayCoefficients;
  double FDelay;
  LowPass(double ASignalBinTime):Signal(ASignalBinTime){};
  void SaveCoefficientsToStream(Tools::ASCIIOutStream& AStream);
  void Debug(std::string AIndent="");
};

}

#endif
