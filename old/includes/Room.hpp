//by Gabriel Goude

#ifndef ROOM_HPP_
# define ROOM_HPP_

// CROSSPLATFORM HERE
# include <netinet/in.h>
// to here
# include <string>
# include <list>
# include "Client.hpp"
# include "server.hpp"

class Room
{
    std::string         _name;

    public:
    std::list<Client *> _clients;
    Room();
    ~Room();
    bool        addClient(Client *cl);
    bool        removeClient(Client *cl);
    bool        hasClient(const sockaddr_in& cl) const;
    bool        isReady();
    void        setName(std::string name);
    std::string getName() const;

    private:
    Room(Room&);
    void        operator=(Room&);
};

#endif
