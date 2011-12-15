#ifndef _Tools_Stream_
#define _Tools_Stream_
#include <string>
#include <fstream>
#include <vector>

namespace Tools{

class ASCIIInStream
{
  private:
  std::ifstream FFile;
  public:
  void Close();
  ASCIIInStream(std::string AFileName);
  ASCIIInStream(ASCIIInStream& AStream);
  ~ASCIIInStream();
  ASCIIInStream& operator>>(const char * AString);
  ASCIIInStream& operator>>(double& ANumber);
  ASCIIInStream& operator>>(unsigned int& ANumber);
  ASCIIInStream& operator>>(std::string& AString);
  ASCIIInStream& operator>>(std::vector<double>& AVector);
  ASCIIInStream& operator=(ASCIIInStream& AStream);
};

class ASCIIOutStream
{
  private:
  std::ofstream FFile;
  public:
  void Close();
  ASCIIOutStream(std::string AFileName);
  ASCIIOutStream(ASCIIOutStream& AStream);
  ~ASCIIOutStream();
  ASCIIOutStream& operator<<(const char * AString);
  ASCIIOutStream& operator<<(double ANumber);
  ASCIIOutStream& operator<<(std::vector<double>& AVector);
  ASCIIOutStream& operator<<(std::string& AString);
  ASCIIOutStream& operator<<(unsigned int ANumber);
  ASCIIOutStream& operator=(ASCIIOutStream& AStream);
};

}

#endif
