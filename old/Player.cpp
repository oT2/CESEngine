//
// Vie.cpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:41:32 2016 Clément Arnoux
// Last update Fri Jan  6 01:50:02 2017 Clément Arnoux
//

#include "includes/Player.hpp"
#include "includes/Msg.hpp"
#include <iostream>


extern "C" IComponent      *getComponent()
{
  Player	*tmp;
  tmp = new Player();
  tmp->number = -1;
  return (tmp);
}

extern "C" Msg      *createMsg(IComponent* comp)
{

  Msg		*msg;
  PlayerDatagram	*ret;
  Player		*tmp;

  ret = new PlayerDatagram();
  tmp = (Player*) comp;
  ret->number = tmp->number;
  msg = new Msg((Datagram*) ret, sizeof(ret), false);
  return (msg);
}
