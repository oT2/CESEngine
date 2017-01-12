//
// Vie.cpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:41:32 2016 Clément Arnoux
// Last update Fri Jan  6 01:49:21 2017 Clément Arnoux
//

#include "includes/HitboxParam.hpp"
#include "includes/Msg.hpp"
#include <iostream>


extern "C" IComponent      *getComponent()
{
  HitboxParam	*comp;
  comp = new HitboxParam();
  comp->hiting = 0;
  return (comp);
}

extern "C" Msg      *createMsg(IComponent* comp)
{

  Msg			*msg;
  HitboxParamDatagram	*ret;
  HitboxParam		*tmp;

  ret = new HitboxParamDatagram();
  tmp = (HitboxParam*) comp;
  ret->hiting = tmp->hiting;
  msg = new Msg((Datagram*) ret, sizeof(ret), false);
  return (msg);
}
