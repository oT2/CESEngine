//by Gabriel Goude

#include "includes/Client.hpp"

Client::Client(sockaddr_in& sock)
{
    this->_sock.sin_family = sock.sin_family;
    this->_sock.sin_port = sock.sin_port;
    this->_sock.sin_addr.s_addr = sock.sin_addr.s_addr;
    this->_ready = false;
}

Client::~Client()
{
}

void        Client::setReady(bool state)
{
    this->_ready = state;
}

bool        Client::isReady() const
{
    return (this->_ready);
}

const struct sockaddr_in& Client::getSock() const
{
    return this->_sock;
}

void        Client::setName(const std::string name)
{
}

const std::string& Client::getName() const
{
    return this->_name;
}

bool        operator==(const sockaddr_in& lhs, const sockaddr_in& rhs)
{
    if (lhs.sin_family == rhs.sin_family
            && lhs.sin_port == rhs.sin_port
            && lhs.sin_addr.s_addr == rhs.sin_addr.s_addr
       )
        return (true);
    return (false);
}
