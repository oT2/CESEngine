//
// FactoryMario.cpp for FactoryMario in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 19:18:47 2016 Clément Arnoux
// Last update Fri Jan  6 02:00:40 2017 Clément Arnoux
//

#include "includes/FactoryMario.hpp"
#include "includes/Vie.hpp"
#include <string.h>
#include <iostream>

FactoryMario::FactoryMario(Data & d)
  : IFactory(d, "Mario")
{
}

const bool    FactoryMario::initComponent(int index)
{
  Vie   *vie;

  if ((vie = (Vie*) AddComponent(index, "Vie")) == NULL)
    return (false);
  vie->value = 3;
  return (true);
}

extern "C" IFactory      *getFactory(Engine &data)
{
  return (new FactoryMario(data));
}

extern "C" std::string      getTypes()
{
  // ret = "COMPONENT1.COMPONENT2.COMPONENT3.(...):.SYSTEM1.SYSTEM2.SYSTEM3.(...)
  std::string ret("Vie.:.Damage");
  return (ret);
}
