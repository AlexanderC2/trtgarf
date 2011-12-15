#include "Signals/Discriminate.hpp"

namespace Signals
{

void Discriminate::Apply(Signal& ASource)
{
  AdjustSignalEnviroment(ASource);
  for(unsigned int i=0;i<GetSignalBins();++i)
  {
    if(ASource.GetSignalBin(i)>=FThreshold)
    {
      SetSignalBin(i,1);
    }
    else
    {
      SetSignalBin(i,0);
    }
  }
}

Discriminate::Discriminate(double ASignalBinTime,double AThreshold):Signal(ASignalBinTime)
{
  FThreshold=AThreshold;
}

}
