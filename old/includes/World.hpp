// by Gabriel Goude

#ifndef WORLD_HPP_
# define WORLD_HPP_

#include <string>
#include <list>
#include <netinet/in.h>
#include "Lobby.hpp"
#include "Engine.hpp"
#include "MsgBox.hpp"
#include "ISocket.hpp"
#include "LinuxSocket.hpp"

class World {
    MsgBox _outbox;
    Lobby _lobby;
    std::list<Engine*> _games;
    char* _port;
    ISocket *_socket;

    public:
    World(char* port);
    ~World();
    bool receive_data();
    bool run();
    World(World&);

    private:
    void operator=(World&);
    int findClient(const sockaddr_in& infos);

};

#endif
