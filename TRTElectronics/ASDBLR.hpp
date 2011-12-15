#ifndef _TRTElectronics_ASDBLR_
#define _TRTElectronics_ASDBLR_
#include "TRTElectronics/ASDBLRPreamplifier.hpp"
#include "TRTElectronics/ASDBLRShaper.hpp"
#include "TRTElectronics/ASDBLRBaselineRestorer.hpp"
#include "TRTElectronics/ASDBLRDiscriminator.hpp"
#include "Signals/HighPass.hpp"

namespace TRT
{

class ASDBLR
{
  public:
  ASDBLRPreamplifier     FASDBLRPreamplifier;
  ASDBLRShaper           FASDBLRShaper;
  ASDBLRBaselineRestorer FASDBLRBaselineRestorer;
  Signals::HighPass      FASDBLRLowDiscIntegrator;
  Signals::HighPass      FASDBLRHighDiscIntegrator;
  ASDBLRDiscriminator    FASDBLRLowDiscriminator;
  ASDBLRDiscriminator    FASDBLRHighDiscriminator;
  ASDBLR();
  void SaveCoefficientsToStream(Tools::ASCIIOutStream AStream);
  void SaveCoefficientsToFile(std::string AFileName);
};

}

#endif
