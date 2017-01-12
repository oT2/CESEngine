//
// Damage.cpp for Damage in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 13:08:41 2016 Clément Arnoux
// Last update Thu Jan  5 16:07:21 2017 Clément Arnoux
//

#include "includes/Shoot.hpp"
#include "includes/Weapon.hpp"
#include "includes/Position.hpp"
#include "includes/HitboxParam.hpp"
#include "includes/Vector.hpp"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

Shoot::Shoot(Engine &d)
  : data(d)
{
  int index;

  wait = 0;
  if ((index = d.getCCompIndex("Weapon")) == -1)
    {
      std::cout << "exit weapon\n";
      //throw exception
      exit(84);
    }
  compare.set(index);
  id = "Shoot";
}

Shoot::~Shoot()
{

}

const std::string	& Shoot::getId() const
{
  return (id);
}

bool			Shoot::createMissile(int owner)
{
  Position      *pos;
  Position      *posown;
  HitboxParam   *hit;
  HitboxParam   *hitown;
  Vector        *v;
  int		index;

  if ((index = data.instantiate("Missile")) == -1)
    return (false);
  if ((pos = (Position*) data.getComponent(index, "Position")) == NULL)
    return (false);
  posown = (Position*) data.getComponent(owner, "Position");
  pos->x = posown->x;
  pos->y = posown->y;
  if ((hit = (HitboxParam*) data.getComponent(index, "HitboxParam")) == NULL)
    return (false);
  hitown = (HitboxParam*) data.getComponent(owner, "HitboxParam");
  hit->hiting = 2;
  hit->player = hitown->player;
  if ((v = (Vector*) data.getComponent(index, "Vector")) == NULL)
    return (false);
  v->x = 1;
  if (hitown->player == false)
    v->x = -1;
  v->y = 0;
  return (true);
}

const int		Shoot::update()
{
  Weapon		*w;
  IFactory		*fact;
  int			i;

  //  return (-1);
  ++wait;
  if (wait % 10 == 0)
    return (-1);
  for (int i = 0; i < MAX_ENTITIES; ++i)
    {
      if ((data.get_entity(i) & compare) == compare)
	{
	  w = (Weapon*) data.getComponent(i, "Weapon");
	  if (w->continuous == true)
	    {
	      createMissile(i);
	    }
	}
    }
  return (0);
}

const int		Shoot::apply(int)
{
  return (0);
}

extern "C" ISystem	*getSystem(Engine &data)
{
  return (new Shoot(data));
}

