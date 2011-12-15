#ifndef _Signals_SignalPairSet_
#define _Signals_SignalPairSet_
#include "Signals/Signal.hpp"
#include <TCanvas.h>

//*****************************************************************************
// SignalPair
//  Organizes a set of signal pairs
//*****************************************************************************

namespace Signals
{

struct SignalPair
{
  Signal FInput;
  Signal FOutput;
  Signal FResult;
  Signal FExtra1;
  struct SignalPair * FNext;
};

class SignalPairSet
{
  private:
  struct SignalPair * FPairs;
  struct SignalPair * FCurrentPair;
  double FSignalBinTime;
  double FSignalBins;

  double FScaleInput;
  double FScaleOutput;
  double FScaleResult;
  double FScaleExtra1;

  unsigned int FColorInput;
  unsigned int FColorOutput;
  unsigned int FColorResult;
  unsigned int FColorExtra1;

  public:

  void SetPlotScales(double AScaleInput,
                     double AScaleOutput,
                     double AScaleResult=1,
                     double AScaleExtra1=1);
  void SetPlotColors(unsigned int AColorInput,
                     unsigned int AColorOutput,
                     unsigned int AColorResult=0,
                     unsigned int AColorExtra1=0);
  void PlotAll(TCanvas * canvas);

  double CompareAll();

  unsigned int GetSignalBins();
  double GetSignalBinTime();
  unsigned int GetSignalPairCount();

  void SetCurrentResult(Signal& ASignal);
  void SetCurrentExtra1(Signal& ASignal);

  Signal& GetCurrentExtra1();
  Signal& GetCurrentResult();
  Signal& GetCurrentInput();
  Signal& GetCurrentOutput();

  bool IterReset();
  bool IterNext();
  void Clear();
  void AddSignalPair(Signal& AInput,Signal& AOutput);

  SignalPairSet();
  ~SignalPairSet();

};

}

#endif
