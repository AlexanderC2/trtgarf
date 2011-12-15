#ifndef _TRTElectronics_IntPoleZero_
#define _TRTElectronics_IntPoleZero_

#include "Signals/Signal.hpp"

namespace TRT
{

class IntPoleZero:public Signals::Signal
{
  protected:
  void Apply(Signal& ASignal);
  public:
  std::vector<double> FDelta1Coefficients;
  std::vector<double> FDecay1Coefficients;
  std::vector<double> FDelta2Coefficients;
  std::vector<double> FDecay2Coefficients;
  std::vector<double> FWeight2Coefficients;
  double FDelay;
  IntPoleZero(double ASignalBinTime):Signal(ASignalBinTime){};
  void SaveCoefficientsToStream(Tools::ASCIIOutStream& AStream);
  void Debug(std::string AIndent="");
};

}

#endif
