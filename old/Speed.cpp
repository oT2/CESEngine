//
// Vie.cpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:41:32 2016 Clément Arnoux
// Last update Fri Jan  6 01:51:14 2017 Clément Arnoux
//

#include "includes/Speed.hpp"
#include "includes/Msg.hpp"
#include <iostream>


extern "C" IComponent      *getComponent()
{
  Speed	*tmp;
  tmp = new Speed();
  tmp->value = 0;
  return (tmp);
}

extern "C" Msg      *createMsg(IComponent* comp)
{

  Msg		*msg;
  SpeedDatagram	*ret;
  Speed		*tmp;

  ret = new SpeedDatagram();
  tmp = (Speed*) comp;
  ret->value = tmp->value;
  msg = new Msg((Datagram*) ret, sizeof(ret), false);
  return (msg);
}
