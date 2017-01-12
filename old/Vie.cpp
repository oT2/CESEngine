//
// Vie.cpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:41:32 2016 Clément Arnoux
// Last update Wed Dec 28 03:09:05 2016 Clément Arnoux
//

#include "includes/Vie.hpp"
#include "includes/Msg.hpp"
#include <iostream>


extern "C" IComponent      *getComponent()
{
  Vie	*life;
  life = new Vie();
  life->value = 1;
  return (life);
}

extern "C" Msg      *createMsg(IComponent* comp)
{

  Msg		*msg;
  VieDatagram	*ret;
  Vie		*vie;

  ret = new VieDatagram();
  vie = (Vie*) comp;
  ret->value = vie->value;
  msg = new Msg((Datagram *)ret, sizeof(VieDatagram), false);
  return (msg);
}
