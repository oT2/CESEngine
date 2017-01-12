//
// Damage.cpp for Damage in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 13:08:41 2016 Clément Arnoux
// Last update Wed Jan  4 20:32:49 2017 Clément Arnoux
//

#include "includes/Move.hpp"
#include "includes/Engine.hpp"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

Move::Move(Engine &d)
  : data(d)
{
  int index;
  if ((index = d.getCCompIndex("Position")) == -1)
    {
      //throw exception
      std::cout << "exitpositon\n";
      exit(84);
    }
  compare.set(index);
  if ((index = d.getCCompIndex("Speed")) == -1)
    {
      std::cout << "exitspeed\n";
      //throw exception
      exit(84);
    }
  compare.set(index);
  if ((index = d.getCCompIndex("Vector")) == -1)
    {
      std::cout << "exitvector\n";
      //throw exception
      exit(84);
    }
  compare.set(index);
  id = "Move";
}

Move::~Move()
{

}

const std::string	& Move::getId() const
{
  return (id);
}

const int		Move::update()
{
  Position	*pos;
  Speed		*s;
  int		oldx;
  int		oldy;
  Vector	*v;

  for (int i = 0; i < MAX_ENTITIES; ++i)
    {
      if ((data.get_entity(i) & compare) == compare)
	{
	  pos = (Position*) data.getComponent(i, "Position");
	  s = (Speed*) data.getComponent(i, "Speed");
	  v = (Vector*) data.getComponent(i, "Vector");
	  oldx = pos->x;
	  oldy = pos->y;
	  pos->x += s->value * v->x;
	  pos->y += s->value * v->y;
	  if (oldx != (int) pos->x || oldy != (int) pos->y)
	    pos->modified == true;
	}
    }
  return (0);
}

const int		Move::apply(int)
{
  return (0);
}

extern "C" ISystem	*getSystem(Engine &data)
{
  return (new Move(data));
}
