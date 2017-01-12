// by Gabriel Goude

#ifndef MSG_HPP_
# define MSG_HPP_

// CROSSPLATFORM HERE
#  include <netinet/in.h>

# include <list>
# include "Client.hpp"
# include "Datagram.hpp"

class                       Msg
{
    Datagram                *_dg;
    size_t                  _datasize;
    bool                    _mandatory;

    public:
    std::list<struct sockaddr_in *>  _dests;
    Msg(Datagram *dg, long unsigned int datasize, bool mandatory);
    ~Msg();
    bool addDest(std::list<Client *> dests);
    bool addSock(struct sockaddr_in *);
    Datagram*       getData() const;
    size_t          getSize() const;
};

#endif
