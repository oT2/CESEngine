//
// Vie.cpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:41:32 2016 Clément Arnoux
// Last update Wed Jan  4 19:44:37 2017 Clément Arnoux
//

#include "includes/Vector.hpp"
#include "includes/Msg.hpp"
#include <iostream>


extern "C" IComponent      *getComponent()
{
  Vector	*tmp;
  tmp = new Vector();
  tmp->x = 1;
  tmp->y = 0;
  return (tmp);
}

extern "C" Msg      *createMsg(IComponent* comp)
{

  Msg			*msg;
  VectorDatagram	*ret;
  Vector		*tmp;

  ret = new VectorDatagram();
  tmp = (Vector*) comp;
  ret->x = tmp->x;
  ret->y = tmp->y;
  msg = new Msg((Datagram*) ret, sizeof(VectorDatagram), false);
  return (msg);
}
