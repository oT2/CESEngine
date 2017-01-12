//by Gabriel Goude

#ifndef CLIENT_HPP_
# define CLIENT_HPP_

# include "server.hpp"

#include <iostream>
// CROSSPLATFORM HERE
#  include <netinet/in.h>
// end of crossplatform

class Client
{
    struct sockaddr_in _sock;
    std::string _name;
    bool        _ready;

    public:
    Client(sockaddr_in& sock);
    ~Client();
    void        setReady(bool);
    bool        isReady() const;
    const struct sockaddr_in&    getSock() const;
    void        setName(const std::string name);
    const std::string& getName() const;

    private:
    Client(Client&);
    void        operator=(Client&);
};

bool    operator==(const sockaddr_in& lhs, const sockaddr_in& rhs);

#endif
