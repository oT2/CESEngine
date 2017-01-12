//by Gabriel Goude

#ifndef LOBBYMSG_HPP_
# define LOBBYMSG_HPP_

#include "Datagram.hpp"

enum LobbyEvent
{
    JOIN,
    LEAVE,
    READY,
    NOTREADY,
    UPDATE
};

struct LobbyMsg : public Datagram
{
    int  type;
    char player[16];
    char player2[16];
    char player3[16];
    char player4[16];
    char room[16];
};

#endif
