//
// Vie.cpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:41:32 2016 Clément Arnoux
// Last update Fri Jan  6 01:48:32 2017 Clément Arnoux
//

#include "includes/Behaviour.hpp"
#include "includes/Msg.hpp"
#include <iostream>


extern "C" IComponent      *getComponent()
{
  Behaviour	*tmp;
  tmp = new Behaviour();
  tmp->lastx = 0;
  tmp->lasty = 0;
  tmp->i = -1;
  return (tmp);
}

extern "C" Msg      *createMsg(IComponent* comp)
{
  Msg	*msg;
  msg = new Msg(new Datagram(), sizeof(Datagram), false);
  return (msg);
}
