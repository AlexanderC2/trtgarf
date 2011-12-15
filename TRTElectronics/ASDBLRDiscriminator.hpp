#ifndef _Signals_ASDBLRDiscriminator_
#define _Signals_ASDBLRDiscriminator_
#include "Signals/Signal.hpp"
#include "Tools/Stream.hpp"
namespace TRT
{

class ASDBLRDiscriminator:public Signals::Signal
{
  public:
  double FThreshold;
  double FDCHysteresis;
  double FACHysteresis;
  double FACHysteresisDecay;
  double FDelay;
  protected:
  virtual void Apply(Signal& ASource);
  public:
  ASDBLRDiscriminator(double ASignalBinTime):Signal(ASignalBinTime){};
  void SaveCoefficientsToStream(Tools::ASCIIOutStream& AStream);
  void Debug(std::string AIndent="");
};

}
#endif
