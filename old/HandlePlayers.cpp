//
// Damage.cpp for Damage in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 13:08:41 2016 Clément Arnoux
// Last update Sat Dec 31 00:01:52 2016 Clément Arnoux
//

#include "includes/HandlePlayers.hpp"
#include <iostream>

HandlePlayers::HandlePlayers(Data &d)
  : data(d)
{
  compare.set(d.getCCompIndex("Player"));
  id = "HandlePlayers";
}

HandlePlayers::~HandlePlayers()
{

}

const std::string	& HandlePlayers::getId() const
{
  return (id);
}

const int		HandlePlayers::update()
{
  Msg	*msg;

  while ((msg = box->getMsg()) != NULL)
    {
      msg->
    }
  for (int i = 0; i < MAX_ENTITIES; ++i)
    {
      if ((data.get_entity(i) & compare) == compare)
	{
	  pos = (Position*) data.getComponent(i, "Position");
	  s = (Speed*) data.getComponent(i, "Speed");
	  v = (Vector*) data.getComponent(i, "Vector");
	  old = pos->x;
	  pos->x += s->value * v->x;
	  pos->y += s->value * v->y;
	  if (oldx != (int) pos->x || oldy != (int) pos->y)
	    pos->modified == true;
	}
    }
  return (0);
}


extern "C" ISystem	*getSystem(Data &data)
{
  return (new HandlePlayers(data));
}

