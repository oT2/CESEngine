//
// Damage.cpp for Damage in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 13:08:41 2016 Clément Arnoux
// Last update Thu Jan  5 16:05:47 2017 Clément Arnoux
//

#include "includes/Display.hpp"
#include "includes/Position.hpp"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

Display::Display(Engine &d)
  : data(d)
{
  int index;
  if ((index = d.getCCompIndex("Position")) == -1)
    {
      std::cout << "exit display\n";
      //throw exception
      exit(84);
    }
  compare.set(index);
  id = "Display";
}

Display::~Display()
{

}

const std::string	& Display::getId() const
{
  return (id);
}

const int		Display::update()
{
  std::vector<Position*>	p;
  char				c;
  
  system("clear");
  for (int i = 0; i < MAX_ENTITIES; ++i)
    {
      if ((data.get_entity(i) & compare) == compare)
	{
	  p.push_back((Position*) data.getComponent(i, "Position"));
	}
    }
  for (int j = 0; j < 30; ++j)
    {
      for (int k = 0; k < 30; ++k)
	{
	  c = ' ';
	  for (int l = 0; l < p.size(); ++l)
	    {
	      if ((int) p[l]->x == k && (int) p[l]->y == j)
		c = (l % 10) + 48;
	    }
	  std::cout << c;
	}
      std::cout << std::endl;
      
    }
  return (0);
}

const int		Display::apply(int)
{
  return (0);
}

extern "C" ISystem	*getSystem(Engine &data)
{
  return (new Display(data));
}

