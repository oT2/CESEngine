//
// Damage.cpp for Damage in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 13:08:41 2016 Clément Arnoux
// Last update Thu Jan  5 14:13:18 2017 Clément Arnoux
//

#include "includes/HandleBehaviour.hpp"
#include "includes/Engine.hpp"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

HandleBehaviour::HandleBehaviour(Engine &d)
  : data(d)
{
  int index;

  if ((index = d.getCCompIndex("Behaviour")) == -1)
    {
      std::cout << "exit Handleplayer\n";
      //throw exception
      exit(84);
    }
  compare.set(index);
  if ((index = d.getCCompIndex("Position")) == -1)
    {
      std::cout << "exit Handleplayer\n";
      //throw exception
      exit(84);
    }
  compare.set(index);
  id = "HandleBehaviour";
}

HandleBehaviour::~HandleBehaviour()
{

}

bool			HandleBehaviour::comparediff(int a,  int b, int comp)
{
  //  std::cout << " pos  = " << a << " behave last = " << b << " cond = " << comp << std::endl;  
  int val = a - b;
  if (val < 0)
    val = val * -1;
  if (val > comp)
    return (true);
  return (false);
}

const std::string	& HandleBehaviour::getId() const
{
  return (id);
}

const int		HandleBehaviour::update()
{
  Behaviour	*behave;
  Position	*pos;
  Vector	*ori;
  ISystem	*s;

  for (int i = 0; i < MAX_ENTITIES; ++i)
    {
      if ((data.get_entity(i) & compare) == compare)
        {
	  behave = (Behaviour*) data.getComponent(i, "Behaviour");
	  pos = (Position*) data.getComponent(i, "Position");
	  if (behave->i == -1)
	    {
	      //	      std::cout << "here\n";
	      behave->lastx = pos->x;
	      behave->lasty = pos->y;
	      ++behave->i;
	    }
	  else
	    {
	      if (comparediff(pos->x, behave->lastx, behave->conditions[behave->i].first) && comparediff(pos->y, behave->lasty, behave->conditions[behave->i].second))
		{
		  //		  std::cout << "change behaviour\n";
		  behave->lastx = pos->x;
		  behave->lasty = pos->y;
		  ori->x = behave->orientation[behave->i].first;
		  ori->y = behave->orientation[behave->i].second;
		  ++behave->i;
		  if (behave->i >= behave->conditions.size() || behave->i >= behave->orientation.size())
		    behave->i = 0;
		}
	    }
	}
    }
  return (0);
}


const int		HandleBehaviour::apply(int)
{
  return (0);
}

extern "C" ISystem	*getSystem(Engine &data)
{
  return (new HandleBehaviour(data));
}
