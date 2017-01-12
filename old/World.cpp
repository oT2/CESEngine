// by Gabriel Goude


#include <thread>
#include <iostream>
#include "includes/World.hpp"
#include "includes/ISocket.hpp"
#include "includes/LinuxSocket.hpp"

World::World(char* port)
    :_lobby(&_outbox), _port(port)
{
    _socket = new LinuxSocket(_port);
}

World::~World()
{
    delete _socket;
}

bool    World::run()
{
    std::list<Client *> *clist;
    while (42)
    {
        _lobby.handleMsgs();
        for (std::list<Room>::iterator it=_lobby._rooms.begin(); it != _lobby._rooms.end(); ++it)
        {
            if (it->isReady())
            {
                clist = new std::list<Client *>;
                for (std::list<Client*>::iterator it2=it->_clients.begin(); it2 != it->_clients.end(); ++it)
                    clist->push_back(*it2);
                Engine *tmp;
                tmp = new Engine(*clist, &_outbox);
                tmp->gamethread = new std::thread(&Engine::run, *tmp);
                _games.push_back(tmp);
            }
            _lobby._rooms.erase(it);
        }
    }
}

bool    World::receive_data()
{
    Msg     *pmsg;
    int client_pos;


    while (42)
    {
        while ((pmsg = _socket->read()) != NULL)
        {
            client_pos = this->findClient(*(pmsg->_dests.front()));
            if (client_pos == -1)
            {
                this->_lobby.addClient(new Client(*(pmsg->_dests.front())));
                this->_lobby._inbox.queueMsg(pmsg);
            }
            if (client_pos == 0)
                this->_lobby._inbox.queueMsg(pmsg);
            int i = 1;
            for (std::list<Engine*>::iterator it=_games.begin(); it != _games.end(); ++it)
            {
                if (i == client_pos)
                    (*it)->queueMsg(pmsg);
                ++i;
            }
        }
        while ((pmsg = _outbox.getMsg()) != NULL)
            _socket->send(pmsg);
        return (true);
    }
}

int     World::findClient(const sockaddr_in& infos)
{
    int i = 0;
    if (_lobby.hasClient(infos))
        return (i);
    for (std::list<Engine *>::iterator it=_games.begin(); it != _games.end(); ++it)
    {
        i++;
        if ((*it)->hasClient(infos))
            return (i);
    }
    return (-1); //client not found
}
