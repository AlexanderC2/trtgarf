#ifndef _Signals_Scale_
#define _Signals_Scale_
#include "Signals/Signal.hpp"

namespace Signals
{

class Scale:public Signal
{
  protected:
  void Apply(Signal& ASource);
  public:
  std::vector<double> FScaleCoefficients;
  Scale(double ASignalBinTime):Signal(ASignalBinTime){};
  void SaveCoefficientsToStream(Tools::ASCIIOutStream& AStream);
  void Debug(std::string AIndent="");
};

}

#endif
