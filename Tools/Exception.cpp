#include "Tools/Exception.hpp"

namespace Tools
{

const char * MsgException::what() const throw()
{
  return FMessage.c_str();
}

MsgException::~MsgException() throw()
{
}

MsgException::MsgException(std::string AMessage)
{
  FMessage = AMessage;
}

}
