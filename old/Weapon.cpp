//
// Vie.cpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:41:32 2016 Clément Arnoux
// Last update Fri Jan  6 01:50:48 2017 Clément Arnoux
//

#include "includes/Weapon.hpp"
#include "includes/Msg.hpp"
#include <iostream>


extern "C" IComponent      *getComponent()
{
  Weapon	*tmp;

  tmp = new Weapon();
  tmp->continuous = true;
  return (tmp);
}

extern "C" Msg      *createMsg(IComponent* comp)
{
  Msg			*msg;
  WeaponDatagram	*ret;
  Weapon		*tmp;

  ret = new WeaponDatagram();
  tmp = (Weapon*) comp;
  ret->continuous = tmp->continuous;
  msg = new Msg((Datagram*) ret, sizeof(ret), false);
  return (msg);
}
