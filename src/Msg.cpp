//by Gabriel Goude

#include "includes/Msg.hpp"

Msg::Msg(Datagram *dg, long unsigned int datasize, bool mandatory)
    : _dg(dg), _datasize(datasize), _mandatory(mandatory)
{
}

Msg::~Msg()
{
    for (std::list<sockaddr_in *>::iterator it = _dests.begin(); it != _dests.end(); ++it)
        delete *it;
    delete _dg;
}

bool    Msg::addDest(std::list<Client *> dests)
{
    for (std::list<Client *>::iterator it = dests.begin(); it != dests.end(); ++it)
    {
        sockaddr_in *tmp;
        tmp = new sockaddr_in((*it)->getSock());
        _dests.push_back(tmp);
    }
}

bool    Msg::addSock(struct sockaddr_in *s)
{
    _dests.push_back(s);
}

Datagram*       Msg::getData() const
{
    return (this->_dg);
}

size_t          Msg::getSize() const
{
    return this->_datasize;
}
