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

  TApplication application("app",&argc,argv);

  Signals::SignalSet signals("Meine Signale");
  Signals::Signal a(3.125);
  Signals::Signal b(3.125);
  a.SetSignalLength(200);
  b.SetSignalLength(200);
  a.CreateHeaviside(100,-1,1);
  b.CreateHeaviside(150,-2,2);

  unsigned int index=signals.SetSignal(-1,"signal",a);
  signals.SetSignal(index,"b",b);

  Tools::ASCIIOutStream streamout("test.sig");
  streamout<<signals;
  
  Tools::ASCIIInStream streamin("test.sig");
  Signals::SignalSet sigtest("Test");
  streamin>>sigtest;
  Signals::Signal& ra=sigtest.GetSignal(0,"signal");
  Signals::Signal& rb=sigtest.GetSignal(0,"b");

  TCanvas * canvas1=new TCanvas;
  a.Graph()->Draw("AL*");
  canvas1->Update();

  TCanvas * canvas2=new TCanvas;
  b.Graph()->Draw("AL*");
  canvas2->Update();

  application.Run(kTRUE);

  return 0;
}
