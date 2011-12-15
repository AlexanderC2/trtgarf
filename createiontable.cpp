#include "TRT/Straw.hpp"
#include <TApplication.h>

#include "boost/filesystem.hpp"

const unsigned int SignalBins    = 64;
const unsigned int SignalDiv     = 256;

int main(int argc,char * argv[])
{

  try
  {

    InitRoot();

    TRT::Straw strawtubeanalysis("pion",3.125/SignalDiv,SignalBins*SignalDiv);

    strawtubeanalysis.SetIonDriftDistanceStep(2*10.e-7);
    strawtubeanalysis.CalcIonLookupTable(2*10.e-6); // cm
    strawtubeanalysis.SaveIonLookupTable("IonLookup.dat");
    strawtubeanalysis.CheckIonLookupTable("IonLookup.dat");
  }
  catch(char const * e)
  {
    std::cout<<"Exception:"<<e<<std::endl;
  }
  return 0;
}
