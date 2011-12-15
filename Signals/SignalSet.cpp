#include "Signals/SignalSet.hpp"
#include <iostream>

namespace Signals
{

unsigned int SignalSet::GetGroupCount()
{
  return FSignalSet.size();
}

std::string& SignalSet::GetDescription()
{
  return FDescription;
}

Tools::ASCIIOutStream& operator<<(Tools::ASCIIOutStream& AStream,
                                  SignalSet& ASignalSet)
{
  AStream<<"SignalSetDescription"<<ASignalSet.FDescription
         <<"Groups"<<(unsigned int)ASignalSet.FSignalSet.size();
  for(unsigned int i=0;i<ASignalSet.FSignalSet.size();++i)
  {
    std::map<std::string,Signal>& group = ASignalSet.FSignalSet[i];
    AStream<<"GroupSize"<<(unsigned int)group.size();
    for(std::map<std::string,Signal>::iterator p=group.begin();p!=group.end();++p)
    {
      std::string str = p->first;
      AStream<<"SignalName"<<str
             <<"SignalContent"<<p->second;
    }
  }
  return AStream;
}

Tools::ASCIIInStream& operator>>(Tools::ASCIIInStream& AStream,
                                 SignalSet& ASignalSet)
{
  unsigned int SignalSetSize;
  AStream>>"SignalSetDescription">>ASignalSet.FDescription
         >>"Groups">>SignalSetSize;
  ASignalSet.FSignalSet.resize(SignalSetSize);
  for(unsigned int i=0;i<SignalSetSize;++i)
  {
    unsigned int GroupSize;
    std::map<std::string,Signal>& group=ASignalSet.FSignalSet[i];
    AStream>>"GroupSize">>GroupSize;
    for(unsigned int n=0;n<GroupSize;++n)
    {
      std::string str;
      Signal      signal;
      AStream>>"SignalName">>str
             >>"SignalContent">>signal;

      group[str] = signal;
    }
  }
  return AStream;
}

SignalSet::SignalSet(std::string ADescription)
{
  FDescription = ADescription;
}

unsigned int SignalSet::SetSignal(int AIndex,std::string AId,Signal& ASignal)
{
  if(AIndex<0)
  {
    std::map<std::string,Signal> group;
    group[AId] = ASignal;
    FSignalSet.push_back(group);
    return FSignalSet.size()-1;
  }
  else
  {
    if((unsigned int)AIndex>=FSignalSet.size()) throw Tools::MsgException("SignalSet::SetSignal : Access out of bounds");
    std::map<std::string,Signal>& group=FSignalSet[AIndex];
    group[AId] = ASignal;
    return AIndex;
  }
}

Signal& SignalSet::GetSignal(int AIndex,std::string AId)
{
  if((AIndex<0) && ((unsigned int)AIndex>=FSignalSet.size())) throw Tools::MsgException("SignalSet::GetSignal : Access out of bounds");
  std::map<std::string,Signal>& group=FSignalSet[AIndex];
  return group[AId];
}

}
