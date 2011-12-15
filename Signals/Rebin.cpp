#include "Signals/Rebin.hpp"
#include <math.h>

namespace Signals
{

void Rebin::Apply(Signal& ASource)
{
  double fRebinFactor = GetSignalBinTime()/ASource.GetSignalBinTime();
  unsigned int RebinFactor = floor(fRebinFactor);
  if(RebinFactor==0) throw Tools::MsgException("Rebin::Apply : Rebin factor of 0.");
  if(RebinFactor-RebinFactor>0.000001) throw Tools::MsgException("Rebin::Apply : Cannot rebin fractional, require bintimeout*n=bintimein");
  SetSignalBins(ASource.GetSignalBins()/RebinFactor);
  for(unsigned int i=0;i<GetSignalBins();++i)
  {
    double  Sum   = 0;
    unsigned int Index = i*RebinFactor;
    for(unsigned int n=0;n<RebinFactor;++n)
    {
      Sum+=ASource.GetSignalBin(Index+n);
    }
    SetSignalBin(i,Sum);
  }
}

}
