//
// Damage.cpp for Damage in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 13:08:41 2016 Clément Arnoux
// Last update Fri Dec 30 11:59:17 2016 Clément Arnoux
//

#include "includes/Hitbox.hpp"
#include <iostream>

Hitbox::Hitbox(Data &d)
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

  for (int i = 0; i < MAX_ENTITIES; ++i)
    {
      if ((data.get_entity(i) & compare) == compare)
	{
	  for (int j = 0; j < MAX_ENTITIES; ++j)
	    {
	      if (j != i)
		{
		  first = (Position*) data.getComponent(i, "Position");
		  second = (Position*) data.getComponent(j, "Position");
		  if (check_position(first, second) == true)
		    Hit(i, j);
		}
	    }
	}
    }
  return (0);
}

const int		Hitbox::Hit(int entity, int entity_hiting)
{
  HitboxParam	*hitbox_first;
  HitboxParam	*hitbox_second;
  ISystem	*sys;

  hitbox_first = (HitboxParam*) data.getComponent(entity, "HitboxParam");
  if (hitbox_first->hiting % 3 != 1)
    return (-1);
  hitbox_second = (HitboxParam*) data.getComponent(entity_hiting, "HitboxParam");
  if (hitbox_second->hiting < 2)
    return (-1);
  if (hitbox_first->player == !hitbox_second->player)
    data.erase(entity);
  return (0);
}

extern "C" ISystem	*getSystem(Data &data)
{
  return (new Hitbox(data));
}

