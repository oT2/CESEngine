//by Gabriel Goude

#ifndef DATAGRAM_HPP_
# define DATAGRAM_HPP_

#include <iostream>

enum EVENT
{
    SHOOT,
    CHARGE,
    FORCE,
    MV_DOWNLEFT,
    MV_DOWN,
    MV_DOWNRIGHT,
    MV_LEFT,
    CANCEL,
    MV_RIGHT,
    MV_UPLEFT,
    MV_UP,
    MV_UPRIGHT,
};

struct          Datagram
{
  char	component_id[16];
  int		entity_index;
};

#endif
