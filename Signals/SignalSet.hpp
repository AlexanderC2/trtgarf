#ifndef _Signals_SignalSet_
#define _Signals_SignalSet_
#include "Signals/Signal.hpp"
#include <list>
#include <map>

namespace Signals
{

//*****************************************************************************
// SignalSet
//  Stores a list of groups of signals
//  Groups are accessed by an integer (index)
//  Signals in the groups are accessed by name
//*****************************************************************************
class SignalSet
{
  private:
  std::vector< std::map<std::string,Signal> >FSignalSet;
  std::string FDescription;
  public:
  // An Index of -1 means : Add a new group
  unsigned int GetGroupCount();
  unsigned int SetSignal(int AIndex,std::string AId,Signal& ASignal);
  Signal& GetSignal(int AIndex,std::string AId);
  SignalSet(std::string ADescription);
  std::string& GetDescription();
  friend Tools::ASCIIOutStream& operator<<(Tools::ASCIIOutStream& AStream,
                                           SignalSet& ASignalSet);
  friend Tools::ASCIIInStream& operator>>(Tools::ASCIIInStream& AStream,
                                          SignalSet& ASignalSet);
};

Tools::ASCIIOutStream& operator<<(Tools::ASCIIOutStream& AStream,
                                  SignalSet& ASignalSet);
Tools::ASCIIInStream& operator>>(Tools::ASCIIInStream& AStream,
                                 SignalSet& ASignalSet);


}
#endif
