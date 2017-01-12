//by Gabriel Goude

#ifndef LINUXSOCKET_HPP_
# define LINUXSOCKET_HPP_

# include "ISocket.hpp"

class LinuxSocket : public ISocket
{
    int _socket;
    char* _port;
    public:
    LinuxSocket(char*);
     bool    send(Msg* msg);
     Msg*    read();

};

#endif
