//by Gabriel Goude

#include "includes/Lobby.hpp"
#include "includes/LobbyMsg.hpp"

#include <string.h>

Lobby::Lobby(MsgBox* msgbox)
    : _outbox(msgbox)
{
}

Lobby::~Lobby()
{
}

bool Lobby::addClient(Client *cl)
{
    this->_clients.push_back(cl);
}

bool Lobby::hasClient(const sockaddr_in& cl)
{
    for (std::list<Client*>::iterator it=_clients.begin(); it != _clients.end(); ++it)
    {
        if ((*it)->getSock() == cl)
            return true;
    }
    if (_rooms.empty())
        return (false);
    for (std::list<Room>::iterator it=_rooms.begin(); it != _rooms.end(); ++it)
    {
        if ((*it).hasClient(cl))
            return (true);
    }
    return (false);
}

bool Lobby::handleMsgs()
{
    Msg         *msg;
    int         mtype;

    while ((msg = _inbox.getMsg()) != NULL)
    {
        mtype = ((LobbyMsg*) msg->getData())->type;
        if (mtype == JOIN)
            handleJoin(msg);
        if (mtype == LEAVE)
            handleLeave(msg);
        if (mtype == READY)
            handleReady(msg);
        if (mtype == NOTREADY)
            handleNotReady(msg);
        if (mtype == UPDATE)
            handleUpdate(msg);
        delete msg;
    }
}

bool Lobby::handleUpdate(Msg* msg)
{
    Msg     *tmpmsg;
    Client  *cl;
    LobbyMsg *lmsg;
    for (std::list<Room>::iterator it=_rooms.begin(); it != _rooms.end(); ++it)
    {
        lmsg = new LobbyMsg();
        lmsg->type = UPDATE;
        strncpy(lmsg->room, it->getName().c_str(), 15);
        lmsg->room[15] = 0;
        int i = 0;
        lmsg->player[0] = 0;
        lmsg->player2[0] = 0;
        lmsg->player3[0] = 0;
        lmsg->player4[0] = 0;
        for (std::list<Client *>::iterator it2=it->_clients.begin(); it2 != it->_clients.end(); ++it2)
        {
            const char *cstr;
            cstr = (*it2)->getName().c_str();
            if (i == 0)
            {
                strncpy(lmsg->player, cstr, 15);
                lmsg->player[15] = 0;
            }
            if (i == 1)
            {
                strncpy(lmsg->player2, cstr, 15);
                lmsg->player2[15] = 0;
            }
            if (i == 2)
            {
                strncpy(lmsg->player3, cstr, 15);
                lmsg->player3[15] = 0;
            }
            if (i == 3)
            {
                strncpy(lmsg->player4, cstr, 15);
                lmsg->player4[15] = 0;
            }
            if ((*it2)->getSock() == *(msg->_dests.front()))
                cl = *it2;
            ++i;
        }
        tmpmsg = new Msg((Datagram*) lmsg, sizeof(lmsg), false);
        std::list<Client *> tlist;
        tlist.push_back(cl);
        tmpmsg->addDest(tlist);
        _outbox->queueMsg(tmpmsg);
    }
}

bool Lobby::handleJoin(Msg* msg)
{
    LobbyMsg*       lmsg;
    lmsg = (LobbyMsg*) msg->getData();
    for (std::list<Client *>::iterator it=_clients.begin(); it != _clients.end(); ++it)
        if ((*it)->getSock() == *(msg->_dests.front()))
        {
            for (std::list<Room>::iterator it2=_rooms.begin(); it != _clients.end(); ++it) 
            {
                if (lmsg->room == it2->getName())
                {
                    it2->addClient(*it);
                    _clients.erase(it);
                    return true;
                }
            }
        }
}

bool Lobby::handleLeave(Msg* msg)
{
    LobbyMsg*       lmsg;
    lmsg = (LobbyMsg*) msg->getData();
    for (std::list<Room>::iterator it=_rooms.begin(); it != _rooms.end(); ++it)
        if (lmsg->room == it->getName())
        {
            for (std::list<Client*>::iterator it2= it->_clients.begin(); it2 != it->_clients.end(); ++it2) 
            {
                if ((*it2)->getSock() == *(msg->_dests.front()))
                {
                    _clients.push_back(*it2);
                    it->_clients.erase(it2);
                    return true;
                }
            }
        }
}

bool Lobby::handleReady(Msg* msg)
{
    LobbyMsg*       lmsg;
    lmsg = (LobbyMsg*) msg->getData();
    for (std::list<Room>::iterator it=_rooms.begin(); it != _rooms.end(); ++it)
        if (lmsg->room == it->getName())
        {
            for (std::list<Client*>::iterator it2=it->_clients.begin(); it2 != it->_clients.end(); ++it2) 
            {
                if ((*it2)->getSock() == (*msg->_dests.front()))
                {
                    (*it2)->setReady(true);
                    return true;
                }
            }
        }
}

bool Lobby::handleNotReady(Msg* msg)
{
    LobbyMsg*       lmsg;
    lmsg = (LobbyMsg*) msg->getData();
    for (std::list<Room>::iterator it=_rooms.begin(); it != _rooms.end(); ++it)
        if (lmsg->room == it->getName())
        {
            for (std::list<Client*>::iterator it2=it->_clients.begin(); it2 != it->_clients.end(); ++it2) 
            {
                if ((*it2)->getSock() == (*msg->_dests.front()))
                {
                    (*it2)->setReady(false);
                    return true;
                }
            }
        }
}
