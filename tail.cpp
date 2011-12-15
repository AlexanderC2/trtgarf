#include "TRT/Straw.hpp"
#include "Tools/Stream.hpp"
#include <TApplication.h>
#include <TStyle.h>
#include <TMultiGraph.h>

#include "boost/filesystem.hpp"

const unsigned int SignalBins    = 64;
const unsigned int SignalBinDiv  = 256;

int main(int argc,char * argv[])
{
 try
  {
    InitRoot();
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    
    TApplication application("App",&argc,argv);
  
    boost::filesystem::create_directory("Plots");

    Signals::Signal electronsignal;
    Signals::Signal ionsignal;

/*    TRT::Straw strawtubeanalysis("pion",3.125/SignalBinDiv,SignalBins*SignalBinDiv);

    double energyloss;     // Energy loss of current particle in eV
    unsigned int trackelectrons;
    unsigned int clusters;
  
    strawtubeanalysis.EnableIonSignal();
    strawtubeanalysis.EnableMicroscopicCalculation();
    strawtubeanalysis.LoadIonLookupTable("IonLookup.dat");

    strawtubeanalysis.CalcTrack(5.0,
                                0.1,
                                energyloss,
                                trackelectrons,
                                clusters,
                                true);

    electronsignal = strawtubeanalysis.GetElectronSignal();
    ionsignal      = strawtubeanalysis.GetIonSignal();

    Tools::ASCIIOutStream s("tailfile.dat");
    s<<electronsignal<<ionsignal;
    s.Close();*/
    Tools::ASCIIInStream f("tailfile.dat");
    f>>electronsignal>>ionsignal;
    f.Close();

    Signals::Signal signal;
    signal.AdjustSignalEnviroment(electronsignal);
    signal.Clear();
    signal.Add(electronsignal);
    signal.Add(ionsignal);
    std::cout<<"Integral:"<<electronsignal.IntegralAbove(-10000000)<<std::endl;
    
    TH1D * hion=ionsignal.H1D();
    TH1D * helectron=electronsignal.H1D();
    TH1D * hsignal=signal.H1D();
    
    TF1 * tailfit=new TF1("tailfit","[0]*exp([1]*(x-20.5))+[2]*exp([3]*(x-20.5))",50,150);
    tailfit->SetParameter(0,-1);
    tailfit->SetParameter(1,-0.01);
    tailfit->SetParameter(2,-0.1);
    tailfit->SetParameter(3,-0.001);
    hion->Fit("tailfit","M","",40,190);

    TCanvas * canvas=new TCanvas;
    hsignal->GetXaxis()->SetTitle("ns");
    hsignal->GetYaxis()->SetTitle("fC/3.125ns");
    hsignal->Draw("");
    tailfit->SetLineColor(kRed);
    tailfit->GetXaxis()->SetTitle("ns");
    tailfit->GetYaxis()->SetTitle("fC/3.125ns");
    tailfit->Draw("SAME");
    canvas->Update();
    canvas->Print("tailfit.pdf");

    application.Run(kTRUE);
   
  }
  catch(const char * e)
  {
    std::cout<<e<<std::endl;
    throw;
  }
  return 0;
}
