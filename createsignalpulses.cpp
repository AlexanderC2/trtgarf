#include <TApplication.h>
#include "Signals/Signal.hpp"
#include "Signals/SignalSet.hpp"
#include "Tools/Stream.hpp"
#include "tools.hpp"
#include <iostream>
#include <TROOT.h>
#include <TCanvas.h>
#include <TGraph.h>

#include "boost/filesystem.hpp"

int main(int argc,char ** argv)
{

  Signals::SignalSet signals("Test pulses with different height(directly set)");
  for(double height=0.1;height<1;height*=1.1)
  {
    std::cout<<"Height:"<<height<<std::endl;
    Signals::Signal signal(3.125/256);
    signal.SetSignalLength(200);
    signal.CreateGauss(50,10,height);
    signals.SetSignal(-1,"signal",signal);
  }
  Tools::ASCIIOutStream f("pulses.sig");
  f<<signals;

  return 0;
}
