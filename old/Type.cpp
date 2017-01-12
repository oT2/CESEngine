//
// Vie.cpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:41:32 2016 Clément Arnoux
// Last update Fri Jan  6 02:12:47 2017 Clément Arnoux
//

#include "includes/Type.hpp"
#include "includes/Msg.hpp"
#include <iostream>
#include <string.h>

extern "C" IComponent      *getComponent()
{
  Type	*tmp;
  tmp = new Type();
  return (tmp);
}

extern "C" Msg      *createMsg(IComponent* comp)
{

  Msg		*msg;
  TypeDatagram	*ret;
  Type		*tmp;

  ret = new TypeDatagram();
  tmp = (Type*) comp;
  strcpy(ret->str, tmp->str);
  msg = new Msg((Datagram*) ret, sizeof(*ret), false);
  return (msg);
}
