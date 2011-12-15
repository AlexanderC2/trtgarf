#include "Signals/LowPass.hpp"
#include <iostream>

namespace Signals
{

void LowPass::Debug(std::string AIndent)
{
  std::cout<<AIndent<<"LowPass:"<<std::endl;
  for(unsigned int i=0;i<FDiffCoefficients.size();++i)
  {
    std::cout<<AIndent<<" Diff["<<i<<"]:"<<FDiffCoefficients[i]<<std::endl;
  }
  for(unsigned int i=0;i<FDecayCoefficients.size();++i)
  {
    std::cout<<AIndent<<" Decay["<<i<<"]:"<<FDecayCoefficients[i]<<std::endl;
  }
  std::cout<<" Delay:"<<FDelay<<std::endl;
}

void LowPass::SaveCoefficientsToStream(Tools::ASCIIOutStream& AStream)
{
  AStream<<"DiffCoefficients"<<FDiffCoefficients
         <<"DecayCoeffcients"<<FDecayCoefficients
         <<"Delay"<<FDelay;
}

void LowPass::Apply(Signal& ASource)
{
  AdjustSignalEnviroment(ASource);

  unsigned int DelayBins = FDelay/GetSignalBinTime()+1;
  
  for(unsigned int i=0;i<DelayBins;++i)
  {
    SetSignalBin(i,0);
  }
  
  unsigned int SignalBins = GetSignalBins();
  double OutVoltage  = 0;
  
  for(unsigned int i=DelayBins;i<SignalBins-1;++i)
  {
    double Diff   = ASource.GetSignalBin(i-DelayBins+1)-ASource.GetSignalBin(i-DelayBins);

    OutVoltage += CalcPoly(FDiffCoefficients,Diff)
                 -CalcPoly(FDecayCoefficients,OutVoltage);

    SetSignalBin(i,OutVoltage);
  }
}

}
