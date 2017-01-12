//
// Data.cpp for Data in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 18:49:56 2016 Clément Arnoux
// Last update Sat Dec 31 17:30:57 2016 Clément Arnoux
//

#include "includes/Data.hpp"
#include <iostream>

Data::Data()
{
  where = 0;
}

Data::~Data()
{
}

Msg		*Data::getchanges()
{
  Msg		*ret;

  while (where < _components.size())
    {
      if ((ret = _components[where].getDatagram()) != NULL)
          return (ret);
      ++where;
    }
  where = 0;
  return (NULL);
}

int			Data::AddComponent(std::string id)
{
  for (int i = 0; i < _components.size(); ++i)
    {
      if (_components[i].getId() == id)
	return (-1);
    }
  CComponent	tmp(id);
  _components.push_back(tmp);
  return (0);
}

const std::bitset<32>	& Data::get_entity(int index)
{
  return (_entities[index]);
}

const int		Data::getCCompIndex(std::string id) const
{
  for (int i = 0; i < _components.size(); ++i)
    {
      if (_components[i].getId() == id)
	return (i);
    }
  return (-1);
}

IComponent *Data::getComponent(int index, std::string id) const
{
  int i = getCCompIndex(id);
  if (i != -1)
    return (_components[i][index]);
  return (NULL);
}

int		Data::nextFreeEntity()
{
  std::bitset<32>	free_bitset;
  for (int i = 0; i < MAX_ENTITIES; ++i)
    {
      if (_entities[i] == free_bitset)
	return (i);
    }
  return (MAX_ENTITIES);
}

void		Data::erase(int entity)
{
  _entities[entity].reset();
}
