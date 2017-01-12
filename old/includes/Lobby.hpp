//by Gabriel Goude

#ifndef LOBBY_HPP_
# define LOBBY_HPP_

# include <list>
# include "Room.hpp"
# include "server.hpp"
# include "MsgBox.hpp"

class Lobby
{
    std::list<Client *> _clients;
    MsgBox*         _outbox;

    public:
    Lobby(MsgBox* msgbox);
    ~Lobby();
    bool        hasClient(const sockaddr_in& cl);
    bool handleMsgs();
    bool        addClient(Client* cl);
    std::list<Room> _rooms;
    MsgBox          _inbox;

    private:
    Lobby(Lobby&);
    void operator=(Lobby&);
    bool handleJoin(Msg*);
    bool handleLeave(Msg*);
    bool handleReady(Msg*);
    bool handleNotReady(Msg*);
    bool handleUpdate(Msg*);
};

#endif
