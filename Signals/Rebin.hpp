#ifndef _Signals_Rebin_
#define _Signals_Rebin_
#include "Signals/Signal.hpp"

namespace Signals
{

class Rebin:public Signal
{
  protected:
  virtual void Apply(Signal& ASource);
  public:
  Rebin(double ASignalBinTime):Signal(ASignalBinTime){};
};

}
#endif
