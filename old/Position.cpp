//
// Vie.cpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:41:32 2016 Clément Arnoux
// Last update Fri Jan  6 01:50:13 2017 Clément Arnoux
//

#include "includes/Position.hpp"
#include "includes/Msg.hpp"
#include <iostream>


extern "C" IComponent      *getComponent()
{
  Position	*pos;
  pos = new Position();
  pos->x = 0;
  pos->y = 0;
  return (pos);
}

extern "C" Msg      *createMsg(IComponent* comp)
{

  Msg			*msg;
  PositionDatagram	*ret;
  Position		*pos;

  ret = new PositionDatagram();
  pos = (Position*) comp;
  ret->x = pos->x;
  ret->y = pos->y;
  msg = new Msg((Datagram*) ret, sizeof(ret), false);
  return (msg);
}
