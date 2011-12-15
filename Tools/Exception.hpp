#ifndef _Tools_Exception_
#define _Tools_Exception_
#include <exception>
#include <string>

namespace Tools
{

class MsgException : public std::exception
{
  private:
  std::string FMessage;
  public:
  virtual const char * what() const throw();
  MsgException(std::string AMessage);
  ~MsgException() throw();
};

}

#endif
