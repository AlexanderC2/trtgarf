#ifndef _Signals_Discriminate_
#define _Signals_Discriminate_
#include "Signals/Signal.hpp"

namespace Signals
{

class Discriminate:public Signal
{
  private:
  double FThreshold;
  protected:
  virtual void Apply(Signal& ASource);
  public:
  Discriminate(double ASignalBinTime,double AThreshold);
};

}
#endif
