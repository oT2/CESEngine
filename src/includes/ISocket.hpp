#ifndef ISOCKET_HPP_
# define ISOCKET_HPP_

# include "Msg.hpp"

class ISocket
{
public :
    ISocket();
  ~ISocket(); 
 virtual bool			send(Msg* msg) = 0;
 virtual Msg*			read() = 0;
//  static struc sockaddr UdpFormatAdress(char *host, u_short port);
//  char			*get_ip();
};

#endif
