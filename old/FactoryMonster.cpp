//
// FactoryMario.cpp for FactoryMario in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 19:18:47 2016 Clément Arnoux
// Last update Fri Jan  6 02:01:44 2017 Clément Arnoux
//

#include <iostream>
#include <string.h>
#include "includes/FactoryMonster.hpp"
#include "includes/Position.hpp"
#include "includes/Speed.hpp"
#include "includes/HitboxParam.hpp"
#include "includes/Vector.hpp"
#include "includes/Weapon.hpp"
#include "includes/Behaviour.hpp"
#include "includes/Type.hpp"

FactoryMonster::FactoryMonster(Engine & d)
  : IFactory(d, "Monster")
{
}

const bool    FactoryMonster::initComponent(int index)
{
  Position	*pos;
  HitboxParam	*hit;
  Speed		*s;
  Vector	*v;
  Weapon	*w;
  Behaviour	*b;
  Type		*t;

  if ((pos = (Position*) AddComponent(index, "Position")) == NULL)
    return (false);
  pos->x = 36;
  pos->y = 11;  
  if ((hit = (HitboxParam*) AddComponent(index, "HitboxParam")) == NULL)
    return (false);
  hit->hiting = 2;
  hit->player = false;
  if ((s = (Speed*) AddComponent(index, "Speed")) == NULL)
    return (false);
  s->value = 0.166;
  if ((v = (Vector*) AddComponent(index, "Vector")) == NULL)
    return (false);
  v->x = -1;
  v->y = -1;  
  if ((w = (Weapon*) AddComponent(index, "Weapon")) == NULL)
    return (false);
  w->continuous = true;
  if ((b = (Behaviour*) AddComponent(index, "Behaviour")) == NULL)
    return (false);
  b->orientation.push_back(std::make_pair(-1, 1));
  b->orientation.push_back(std::make_pair(-1, -1));
  b->conditions.push_back(std::make_pair(5, 10));
  b->conditions.push_back(std::make_pair(5, 10));
  if ((t = (Type*) AddComponent(index, "Type")) == NULL)
    return (false);
  strcpy(t->str, "Monster");
  return (true);
}

extern "C" IFactory      *getFactory(Engine &data)
{
  return (new FactoryMonster(data));
}

extern "C" std::string      getTypes()
{
  // ret = "COMPONENT1.COMPONENT2.COMPONENT3.(...):.SYSTEM1.SYSTEM2.SYSTEM3.(...)
  std::string ret("Position.HitboxParam.Speed.Vector.Behaviour.Weapon.Type.:.Hitbox.Move.HandleBehaviour.Shoot");
  return (ret);
}
