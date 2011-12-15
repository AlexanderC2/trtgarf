#ifndef _Tools_SSH_
#define _Tools_SSH_
#include "libssh/libssh.h"
#include <string>
#include <list>

namespace SSH
{
  class SSH
  {
    private:
    ssh_session            FSession;
    public:
    std::list<std::string> FOutput;
    void ReceiveFile(std::string ASource,std::string ADest);
    void SendFile(std::string ASource,std::string ADest);
    void ExecuteCommand(std::string ACommand);
    SSH(std::string AHost,std::string AUserName,std::string APassword);
    ~SSH();
  };
}
#endif
