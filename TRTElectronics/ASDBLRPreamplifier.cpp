#include "TRTElectronics/ASDBLRPreamplifier.hpp"
#include <iostream>

namespace TRT
{

void ASDBLRPreamplifier::Debug(std::string AIndent)
{
  std::cout<<AIndent<<"ASDBLRPreamplifier:"<<std::endl;
  for(unsigned int i=0;i<FStateInputCoefficients.size();++i)
  {
    std::cout<<AIndent<<" StateInput["<<i<<"]:"<<FStateInputCoefficients[i]<<std::endl;
  }
  for(unsigned int i=0;i<FStateInputDiffCoefficients.size();++i)
  {
    std::cout<<AIndent<<" StateDiff["<<i<<"]:"<<FStateInputDiffCoefficients[i]<<std::endl;
  }
  for(unsigned int i=0;i<FStateDecayCoefficients.size();++i)
  {
    std::cout<<AIndent<<" StateDecay["<<i<<"]:"<<FStateDecayCoefficients[i]<<std::endl;
  }
  for(unsigned int i=0;i<FOutStateCoefficients.size();++i)
  {
    std::cout<<AIndent<<" OutState["<<i<<"]:"<<FOutStateCoefficients[i]<<std::endl;
  }
  for(unsigned int i=0;i<FOutStateDiffCoefficients.size();++i)
  {
    std::cout<<AIndent<<" OutStateDiff["<<i<<"]:"<<FOutStateDiffCoefficients[i]<<std::endl;
  }
  for(unsigned int i=0;i<FOutOutCoefficients.size();++i)
  {
    std::cout<<AIndent<<" OutOut["<<i<<"]:"<<FOutOutCoefficients[i]<<std::endl;
  }
  std::cout<<AIndent<<" Delay:"<<FDelay<<std::endl;
}

void ASDBLRPreamplifier::SaveCoefficientsToStream(Tools::ASCIIOutStream& AStream)
{
  AStream<<"StateInputCoefficients"<<FStateInputCoefficients
         <<"StateInputDiffCoefficients"<<FStateInputDiffCoefficients
         <<"StateDecayCoefficients"<<FStateDecayCoefficients
         <<"OutStateCoefficients"<<FOutStateCoefficients
         <<"OutStateDiffCoefficients"<<FOutStateDiffCoefficients
         <<"OutOutCoefficients"<<FOutOutCoefficients
         <<"Delay"<<FDelay;
}

void ASDBLRPreamplifier::Apply(Signal& ASource)
{
  AdjustSignalEnviroment(ASource);

  unsigned int DelayBins=FDelay/GetSignalBinTime()+1;

  for(unsigned int i=0;i<DelayBins;++i)
  {
    SetSignalBin(i,0);
  }

  double State       = 0;
  double State2      = 0;
  double OutVoltage  = 0;
  unsigned int SignalBins = GetSignalBins();

  for(unsigned int i=DelayBins;i<SignalBins;++i)
  {
    double Input      = ASource.GetSignalBin(i-DelayBins);
    double PrevState2 = State2;
    double Decay      = CalcPoly(FStateDecayCoefficients,State);
    State          += CalcPoly(FStateInputCoefficients,Input)+Decay;
    State2         += CalcPoly(FStateInputDiffCoefficients,Input-State2);
    OutVoltage     += CalcPoly(FOutStateCoefficients,Decay)
                    + CalcPoly(FOutStateDiffCoefficients,State2-PrevState2)
                    + CalcPoly(FOutOutCoefficients,OutVoltage);

    SetSignalBin(i,OutVoltage);
  }
}

}
