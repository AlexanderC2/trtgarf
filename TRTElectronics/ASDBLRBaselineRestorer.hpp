#ifndef _TRTElectronics_ASDBLRBaselineRestorer_
#define _TRTElectronics_ASDBLRBaselineRestorer_
#include "Signals/Signal.hpp"

namespace TRT
{

class ASDBLRBaselineRestorer : public Signals::Signal
{
  protected:
  void Apply(Signal& ASource);
  public:
  std::vector<double> FTopStateCoefficients;
  std::vector<double> FTopDiffCoefficients;
  std::vector<double> FBottomStateCoefficients;
  std::vector<double> FBottomDiffCoefficients;
  double FDelay;
  ASDBLRBaselineRestorer(double ASignalBinTime):Signal(ASignalBinTime){};
  void SaveCoefficientsToStream(Tools::ASCIIOutStream& AStream);
  void Debug(std::string AIndent="");
};

}
#endif
