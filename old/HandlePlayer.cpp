//
// Damage.cpp for Damage in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 13:08:41 2016 Clément Arnoux
// Last update Wed Jan  4 19:50:45 2017 Clément Arnoux
//

#include "includes/HandlePlayer.hpp"
#include "includes/Engine.hpp"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

HandlePlayer::HandlePlayer(Engine &d)
  : data(d)
{
  int index;

  if ((index = d.getCCompIndex("Player")) == -1)
    {
      std::cout << "exit Handleplayer\n";
      //throw exception
      exit(84);
    }
  compare.set(index);
  id = "HandlePlayer";
}

void			HandlePlayer::changeOrientation(int player, int order)
{
  Vector	*orien;

  orien = (Vector*) data.getComponent(player, "Vector");
  orien->x = ((order + 1) / 3) - 1;
  orien->y = order % 3 -1;
}

HandlePlayer::~HandlePlayer()
{

}

const std::string	& HandlePlayer::getId() const
{
  return (id);
}

void			HandlePlayer::handleOrder(int client, int order)
{
  Player	*player;
  ISystem	*s;

  for (int i = 0; i < MAX_ENTITIES; ++i)
    {
      if ((data.get_entity(i) & compare) == compare)
        {
	  player = (Player*) data.getComponent(i, "Player");
	  if (player->number == client)
	    {
	      if (order > 2)
		changeOrientation(i, order - 3);
	      else
		{
		  s = data.getSystem("Shoot");
		  s->apply(i);
		}
	    }
	}
    }
}


const int		HandlePlayer::update()
{
  Msg		*msg;
  int		pos;
  Datagram	*d;
  sockaddr_in	*sock;

  while ((msg = data.getMessage()) != NULL)
    {
      sock = *msg->_dests.begin();
      if ((pos = data.getClientNumber(*sock)) != -1)
	{
	  d = msg->getData();
	  handleOrder(pos, d->entity_index);
	}
    }
  return (0);
}

const int		HandlePlayer::apply(int)
{
  return (0);
}

extern "C" ISystem	*getSystem(Engine &data)
{
  return (new HandlePlayer(data));
}
