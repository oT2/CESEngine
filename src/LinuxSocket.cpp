//by Gabriel Goude

#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include "includes/LinuxSocket.hpp"

LinuxSocket::LinuxSocket(char* port)
    : _port(port)
{
    struct addrinfo hints;
    struct addrinfo *res;

    memset(&hints,0,sizeof(hints));
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_DGRAM;
    hints.ai_protocol=IPPROTO_UDP;
    hints.ai_flags=AI_PASSIVE|AI_ADDRCONFIG;
    if (getaddrinfo(NULL, _port, &hints, &res) != 0)
        exit(1);
    if ((_socket=socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1)
        exit(1);
    if (bind(_socket,res->ai_addr,res->ai_addrlen)==-1)
        exit(1);
    freeaddrinfo(res);
}

bool    LinuxSocket::send(Msg* msg)
{
    for (std::list<struct sockaddr_in*>::iterator it=msg->_dests.begin(); it != msg->_dests.end(); ++it)
    {
        if (sendto(_socket, msg->getData(), msg->getSize(), 0, (struct sockaddr*) *it, sizeof(*it)) == -1)
            exit(1);
    }
    return true;
}

Msg*    LinuxSocket::read()
{
    Msg*    msg;
    Datagram* dg;
    char buffer[512];
    struct sockaddr_storage src_addr;
    struct sockaddr_in      *s;
    socklen_t src_addr_len = sizeof(src_addr);

    ssize_t count = recvfrom(_socket,buffer,sizeof(buffer),0,(struct sockaddr*)&src_addr, &src_addr_len);
    if (count==-1)
        exit(1);
    else if (count==sizeof(buffer))
        exit(1);
    else
    {
        if ((dg = (Datagram*) malloc(sizeof(buffer))) == NULL)
            exit(1);
        memset(dg, 0, 512);
        memcpy(dg, buffer, count);
        s = new sockaddr_in();
        s->sin_family = ((sockaddr_in*) &src_addr)->sin_family;
        s->sin_port = ((sockaddr_in*) &src_addr)->sin_port;
        s->sin_addr = ((sockaddr_in*) &src_addr)->sin_addr;
        msg = new Msg(dg, count, false);
        // add client infos to msg
        msg->addSock(s);
        return msg;
    }
}
