//
// FactoryMario.cpp for FactoryMario in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 19:18:47 2016 Clément Arnoux
// Last update Fri Jan  6 02:08:59 2017 Clément Arnoux
//

#include "includes/FactoryShip.hpp"
#include "includes/Position.hpp"
#include "includes/Speed.hpp"
#include "includes/HitboxParam.hpp"
#include "includes/Vector.hpp"
#include "includes/Player.hpp"
#include "includes/Type.hpp"
#include <string.h>
#include <iostream>

FactoryShip::FactoryShip(Engine & d)
  : IFactory(d, "Ship")
{
}

const bool    FactoryShip::initComponent(int index)
{
  Position	*pos;
  HitboxParam	*hit;
  Speed		*s;
  Vector        *v;
  Player	*p;
  Type		*t;

  if ((pos = (Position*) AddComponent(index, "Position")) == NULL)
    return (false);
  pos->x = 0;
  pos->y = 10;
  if ((hit = (HitboxParam*) AddComponent(index, "HitboxParam")) == NULL)
    return (false);
  hit->hiting = 1;
  hit->player = true;
  if ((s = (Speed*) AddComponent(index, "Speed")) == NULL)
    return (false);
  s->value = 0;
  if ((v = (Vector*) AddComponent(index, "Vector")) == NULL)
    return (false);
  v->x = 0;
  v->y = 0;
  if ((p = (Player*) AddComponent(index, "Player")) == NULL)
    return (false);
  p->number = data.getLastPlayer();
  if ((t = (Type*) AddComponent(index, "Type")) == NULL)
    return (false);
  strcpy(t->str, "Ship");
  return (true);
}

extern "C" IFactory      *getFactory(Engine &data)
{
  return (new FactoryShip(data));
}

extern "C" std::string      getTypes()
{
  // ret = "COMPONENT1.COMPONENT2.COMPONENT3.(...):.SYSTEM1.SYSTEM2.SYSTEM3.(...)
  std::string ret("Position.HitboxParam.Speed.Vector.Player.Weapon.Type.:.Hitbox.HandlePlayer.Display");
  return (ret);
}
