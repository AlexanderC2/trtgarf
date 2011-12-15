#include "Signals/Scale.hpp"
#include <iostream>

namespace Signals
{

void Scale::Debug(std::string AIndent)
{
  std::cout<<AIndent<<"Scale:"<<std::endl;
  for(unsigned int i=0;i<FScaleCoefficients.size();++i)
  {
    std::cout<<AIndent<<" Scale["<<i<<"]:"<<FScaleCoefficients[i]<<std::endl;
  }
}

void Scale::SaveCoefficientsToStream(Tools::ASCIIOutStream& AStream)
{
  AStream<<"ScaleCoefficients"<<FScaleCoefficients;
}

void Scale::Apply(Signal& ASource)
{
  AdjustSignalEnviroment(ASource);

  unsigned int SignalBins=GetSignalBins();
  for(unsigned int i=0;i<SignalBins;++i)
  {
    SetSignalBin(i,CalcPoly(FScaleCoefficients,ASource.GetSignalBin(i)));
  }
}

}
