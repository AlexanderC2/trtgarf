#include "TRTElectronics/ASDBLRDiscriminator.hpp"
#include <iostream>

namespace TRT
{

void ASDBLRDiscriminator::Debug(std::string AIndent)
{
  std::cout<<AIndent<<"ASDBLRDiscriminator:"<<std::endl;
  std::cout<<AIndent<<" Threshold         : "<<FThreshold<<std::endl;
  std::cout<<AIndent<<" DCHysteresis      : "<<FDCHysteresis<<std::endl;
  std::cout<<AIndent<<" ACHysteresis      : "<<FACHysteresis<<std::endl;
  std::cout<<AIndent<<" ACHysteresisDecay : "<<FACHysteresisDecay<<std::endl;
  std::cout<<AIndent<<" Delay             : "<<FDelay<<std::endl;
}

void ASDBLRDiscriminator::SaveCoefficientsToStream(Tools::ASCIIOutStream& AStream)
{
  AStream<<"Threshold"<<FThreshold
         <<"DCHysteresis"<<FDCHysteresis
         <<"ACHysteresis"<<FACHysteresis
         <<"ACHysteresisDecay"<<FACHysteresisDecay
         <<"Delay"<<FDelay;
}

void ASDBLRDiscriminator::Apply(Signal& ASource)
{
  AdjustSignalEnviroment(ASource);

  unsigned int DelayBins=FDelay/GetSignalBinTime()+1;

  for(unsigned int i=0;i<GetSignalBins();++i)
  {
    SetSignalBin(i,0);
  }

  double isabove   = 0;
  double abovetime = 0;
  for(unsigned int i=DelayBins;i<GetSignalBins();++i)
  {
    double value = ASource.GetSignalBin(i-DelayBins);
    if(!isabove)
    {
      if(value>=FThreshold)
      {
        isabove   = 1;
        abovetime = 0;
      }
    }
    else
    {
      if(abovetime>=FACHysteresisDecay)
      {
        if(value<FThreshold-FDCHysteresis) isabove = 0;
      }
    }
    SetSignalBin(i,isabove);
    abovetime  += isabove;
  }
}

}
