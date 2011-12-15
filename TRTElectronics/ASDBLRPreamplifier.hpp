#ifndef _TRTElectronics_ASDBLRPreamplifier_
#define _TRTElectronics_ASDBLRPreamplifier_
#include "Signals/Signal.hpp"

namespace TRT
{

class ASDBLRPreamplifier:public Signals::Signal
{
  protected:
  void Apply(Signal& ASource);
  public:
  std::vector<double> FStateInputCoefficients;
  std::vector<double> FStateInputDiffCoefficients;
  std::vector<double> FStateDecayCoefficients;
  std::vector<double> FOutStateCoefficients;
  std::vector<double> FOutStateDiffCoefficients;
  std::vector<double> FOutOutCoefficients;
  double              FDelay;
  ASDBLRPreamplifier(double ASignalBinTime):Signal(ASignalBinTime){};
  void SaveCoefficientsToStream(Tools::ASCIIOutStream& AStream);
  void Debug(std::string AIndent="");
};

}

#endif
