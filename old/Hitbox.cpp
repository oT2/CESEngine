//
// Damage.cpp for Damage in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 13:08:41 2016 Clément Arnoux
// Last update Wed Jan  4 00:20:33 2017 Clément Arnoux
//

#include "includes/Hitbox.hpp"
#include "includes/Engine.hpp"
#include <iostream>

Hitbox::Hitbox(Engine &d)
  : data(d)
{
  compare.set(d.getCCompIndex("Position"));
  compare.set(d.getCCompIndex("HitboxParam"));
  id = "Hitbox";
}

Hitbox::~Hitbox()
{

}

const std::string	& Hitbox::getId() const
{
  return (id);
}

const bool		Hitbox::check_position(Position *pos_a, Position *pos_b)
{
  if ((int) pos_a->x == (int) pos_b->x && (int) pos_a->y == (int) pos_b->y)
    return (true);
  return (false);
}

const int		Hitbox::update()
{
  Position	*first;
  Position	*second;
  bool		first_res;
  bool		second_res;

  for (int i = 0; i < MAX_ENTITIES; ++i)
    {
      if ((data.get_entity(i) & compare) == compare)
	{
	  for (int j = 0; j < MAX_ENTITIES; ++j)
	    {
	      first_res = false;
	      second_res = false;
	      if (j != i)
		{
		  first = (Position*) data.getComponent(i, "Position");
		  second = (Position*) data.getComponent(j, "Position");
		  if (check_position(first, second) == true)
		    {
		      first_res = Hit(i, j);
		      second_res = Hit(j, i);
		      if (first_res == true)
			data.erase(i);
		      if (second_res == true)
			data.erase(j);
		    }
		}
	    }
	}
    }
  return (0);
}

const bool		Hitbox::Hit(int entity, int entity_hiting)
{
  HitboxParam	*hitbox_first;
  HitboxParam	*hitbox_second;
  ISystem	*sys;

  hitbox_first = (HitboxParam*) data.getComponent(entity, "HitboxParam");
  if (hitbox_first->hiting % 3 != 1)
    return (false);
  hitbox_second = (HitboxParam*) data.getComponent(entity_hiting, "HitboxParam");
  if (hitbox_second->hiting < 2)
    return (false);
  if (hitbox_first->player == !hitbox_second->player)
    return (true);
  return (false);
}

const int		Hitbox::apply(int)
{
  return (0);
}

extern "C" ISystem	*getSystem(Engine &data)
{
  return (new Hitbox(data));
}

