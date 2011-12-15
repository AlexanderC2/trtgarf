#include "TRT/Straw.hpp"
#include "Signals/Signal.hpp"
#include "Signals/SignalSet.hpp"
#include "Tools/Stream.hpp"

#include "boost/filesystem.hpp"

const unsigned int SignalBins    = 64;
const unsigned int SignalBinDiv  = 256;

const std::string UserName="kccmp";
const std::string Password="asmb%xx4_c";

int main(int argc,char * argv[])
{
  if(argc<2)
  {
    std::cout<<"Please specify wire distance"<<std::endl;
    return -1;
  }
  TRT::Straw straw("pion",3.125/SignalBinDiv,SignalBins*SignalBinDiv);
  straw.EnableIonSignal();
  straw.EnableMicroscopicCalculation();
  straw.LoadIonLookupTable("IonLookup.dat");
  straw.SetSignalScalingFactor(double(25)/3);
  std::cout<<"LOOP"<<std::endl;
  double distance=atof(argv[1]);
  
  std::cout<<"Distance : "<<distance<<std::endl;
  Signals::SignalSet signalset(DoubleToStr(distance));

  for(unsigned int i=0;i<128;++i)
  {
    std::cout<<">>>"<<i<<std::endl;

    double energyloss;
    unsigned int trackelectrons;
    unsigned int clusters;
    straw.CalcTrack(5.0,distance,energyloss,trackelectrons,clusters,true);
    Signals::Signal signal=straw.GetSignal();
    signalset.SetSignal(-1,"signal",signal);
  }
  Tools::ASCIIOutStream f("pion5GeV"+DoubleToStr(distance)+"cm.sigs");
  f<<signalset;
  f.Close();
  return 0;
}
