//
// Damage.cpp for Damage in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 13:08:41 2016 Clément Arnoux
// Last update Wed Jan  4 20:41:43 2017 Clément Arnoux
//

#include "includes/InitBackground.hpp"
#include "includes/Engine.hpp"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

InitBackground::InitBackground(Engine &d)
  : data(d)
{
  done = false;
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
  id = "InitBackground";
}

InitBackground::~InitBackground()
{

}

const std::string	& InitBackground::getId() const
{
  return (id);
}

const int		InitBackground::update()
{
  Position	*pos;
  Speed		*s;
  int		oldx;
  int		oldy;
  Vector	*v;

  if (done == true)
    return (0);
  std::ifstream	myfile("background.conf");
  if (file.peek() == std::ifstream::traits_type::eof())
    {
      std::cerr << "Invalid argument" << std::endl;
      return (84);
    }
  return (0);
}

const int		InitBackground::apply(int)
{
  return (0);
}

extern "C" ISystem	*getSystem(Engine &data)
{
  return (new InitBackground(data));
}
