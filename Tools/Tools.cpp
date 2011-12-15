#include "Tools/Tools.hpp"
#include "Tools/Exception.hpp"
#include "Tools.hpp"

#include <iostream>

std::string UnescapeString(std::string AString)
{
  std::string  result;
  unsigned int len=0;
  for(unsigned int i=0;i<AString.size();++i)
  {
    if(AString[i]=='\\') ++i;
    len++;
  }
  result.resize(len);
  unsigned int pos = 0;
  for(unsigned int i=0;i<AString.size();++i)
  {
    if(AString[i]!='\\')
    {
      result[pos]=AString[i];
    }
    else
    {
      ++i;
      switch(AString[i])
      {
        case '0':
          result[pos]='\0';
          break;
        case 'n':
          result[pos]='\n';
          break;
        case 'r':
          result[pos]='\r';
          break;
        case '\\':
        default:
          throw Tools::MsgException("UnescapeString : Unknown escape type encountered.");
          break;
      }
    }
    pos++;
  }
  return result;
}

std::string EscapeString(std::string AString)
{
  std::string  result;
  unsigned int len=0;
  for(unsigned int i=0;i<AString.size();++i)
  {
    switch(AString[i])
    {
      case '\0':case '\n':case '\r':
        len++;
        break;
    }
    len++;
  }
  result.resize(len);
  unsigned int pos = 0;
  for(unsigned int i=0;i<AString.size();++i)
  {
    switch(AString[i])
    {
      case 0:
        result[pos]='\\';
        pos++;
        result[pos]='0';
      case '\n':
        result[pos]='\\';
        pos++;
        result[pos]='n';
      case '\r':
        result[pos]='\\';
        pos++;
        result[pos]='r';
      case '\\':
        result[pos]='\\';
        pos++;
        result[pos]='\\';
      default:
        result[pos]=AString[i];
        break;
    }
    pos++;
  }
  return result;
}
