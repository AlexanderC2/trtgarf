#include "Signals/HighPass.hpp"
#include <iostream>

namespace Signals
{

void HighPass::Debug(std::string AIndent)
{
  std::cout<<AIndent<<"HighPass:"<<std::endl;
  for(unsigned int i=0;i<FDeltaCoefficients.size();++i)
  {
    std::cout<<AIndent<<" Delta["<<i<<"]:"<<FDeltaCoefficients[i]<<std::endl;
  }
  for(unsigned int i=0;i<FDecayCoefficients.size();++i)
  {
    std::cout<<AIndent<<" Decay["<<i<<"]:"<<FDecayCoefficients[i]<<std::endl;
  }
}

void HighPass::SaveCoefficientsToStream(Tools::ASCIIOutStream& AStream)
{
  AStream<<"DeltaCoefficients"<<FDeltaCoefficients
         <<"DecayCoefficients"<<FDecayCoefficients
         <<"Delay"<<FDelay;
}

void HighPass::Apply(Signal& ASource)
{
  AdjustSignalEnviroment(ASource);

  unsigned int DelayBins = FDelay/GetSignalBinTime()+1;

  for(unsigned int i=0;i<DelayBins;++i)
  {
    SetSignalBin(i,0);
  }

  double OutVoltage = 0;
  double SignalBins = GetSignalBins();

  for(unsigned int i=DelayBins;i<SignalBins;++i)
  {
    OutVoltage+=CalcPoly(FDeltaCoefficients,ASource.GetSignalBin(i-DelayBins)-OutVoltage)
               -CalcPoly(FDecayCoefficients,OutVoltage);
    SetSignalBin(i,OutVoltage);
  }

}

}
