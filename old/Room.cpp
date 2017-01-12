//by Gabriel Goude

#include "includes/Room.hpp"

Room::Room()
{
}

Room::~Room()
{
}

bool        Room::addClient(Client *cl)
{
    this->_clients.push_back(cl);
}

bool        Room::removeClient(Client *cl)
{
    if (_clients.empty())
        return (false);
    for (std::list<Client *>::iterator it=_clients.begin(); it != _clients.end(); ++it)
    {
        if (cl == *it)
            _clients.erase(it);
    }
}

void        Room::setName(std::string name)
{
    this->_name = name;
}

std::string Room::getName() const
{
    return this->_name;
}

bool        Room::hasClient(const sockaddr_in& cl) const
{
    if (_clients.empty())
        return (false);
    for (std::list<Client *>::const_iterator it=_clients.begin(); it != _clients.end(); ++it)
    {
        if (cl == (*it)->getSock())
            return (true);
    }
    return (false);
}

bool        Room::isReady()
{
    for (std::list<Client *>::const_iterator it=_clients.begin(); it != _clients.end(); ++it)
    {
        if ((*it)->isReady() == false)
            return (false);
    }
    return (true);
}
