#include "TRTElectronics/ASDBLR.hpp"

namespace TRT
{

void ASDBLR::SaveCoefficientsToStream(Tools::ASCIIOutStream AStream)
{
  FASDBLRPreamplifier.SaveCoefficientsToStream(AStream);
  FASDBLRShaper.SaveCoefficientsToStream(AStream);
  FASDBLRBaselineRestorer.SaveCoefficientsToStream(AStream);
  FASDBLRLowDiscIntegrator.SaveCoefficientsToStream(AStream);
  FASDBLRLowDiscriminator.SaveCoefficientsToStream(AStream);
  FASDBLRHighDiscIntegrator.SaveCoefficientsToStream(AStream);
  FASDBLRHighDiscriminator.SaveCoefficientsToStream(AStream);
}

void ASDBLR::SaveCoefficientsToFile(std::string AFileName)
{
  Tools::ASCIIOutStream Stream(AFileName);
  SaveCoefficientsToStream(Stream);
}

ASDBLR::ASDBLR():FASDBLRPreamplifier(0),
                                    FASDBLRShaper(0),
                                    FASDBLRBaselineRestorer(0),
                                    FASDBLRLowDiscIntegrator(0),
                                    FASDBLRHighDiscIntegrator(0),
                                    FASDBLRLowDiscriminator(0),
                                    FASDBLRHighDiscriminator(0)
{
}

}
