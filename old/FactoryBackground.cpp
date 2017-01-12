//
// FactoryMario.cpp for FactoryMario in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 19:18:47 2016 Clément Arnoux
// Last update Fri Jan  6 02:07:15 2017 Clément Arnoux
//

#include "includes/FactoryBackground.hpp"
#include "includes/Position.hpp"
#include "includes/Speed.hpp"
#include "includes/HitboxParam.hpp"
#include "includes/Vector.hpp"
#include "includes/Type.hpp"
#include <string.h>
#include <iostream>

FactoryBackground::FactoryBackground(Engine & d)
  : IFactory(d, "Background")
{
}

const bool    FactoryBackground::initComponent(int index)
{
  Position	*pos;
  HitboxParam	*hit;
  Speed		*s;
  Vector        *v;
  Type		*t;

  if ((pos = (Position*) AddComponent(index, "Position")) == NULL)
    return (false);
  pos->x = 0;
  pos->y = 0;
  if ((hit = (HitboxParam*) AddComponent(index, "HitboxParam")) == NULL)
    return (false);
  hit->hiting = 1;
  hit->player = false;
  if ((s = (Speed*) AddComponent(index, "Speed")) == NULL)
    return (false);
  s->value = 0.66;
  if ((v = (Vector*) AddComponent(index, "Vector")) == NULL)
    return (false);
  v->x = -1;
  if ((t = (Type*) AddComponent(index, "Type")) == NULL)
    return (false);
  strcpy(t->str,"Background");
  return (true);
}

extern "C" IFactory      *getFactory(Engine &data)
{
  return (new FactoryBackground(data));
}

extern "C" std::string      getTypes()
{
  // ret = "COMPONENT1.COMPONENT2.COMPONENT3.(...):.SYSTEM1.SYSTEM2.SYSTEM3.(...)
  std::string ret("Position.HitboxParam.Speed.Type.:.Hitbox");
  return (ret);
}
