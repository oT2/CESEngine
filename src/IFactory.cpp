//
// IFactory.cpp for IFactory.cpp in /home/arnoux_c/rtype/server_src
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Tue Dec 27 20:06:04 2016 Clément Arnoux
// Last update Wed Jan  4 16:49:05 2017 Clément Arnoux
//

#include <bitset>
#include <vector>
#include "includes/IFactory.hpp"
#include "includes/Engine.hpp"

IFactory::IFactory(Engine & d, const char *_id)
  : data(d), id(_id)
{
}

IFactory::~IFactory()
{
}

IComponent      *IFactory::AddComponent(int index, std::string component)
{
  IComponent		*comp;
  int			tmpindex;
  std::bitset<32>	*entity;

  entity = (std::bitset<32>*) &data.get_entity(index);
  if ((tmpindex = data.getCCompIndex(component)) == -1)
    return (NULL);
  entity->set(tmpindex);
  comp = data.getComponent(index, component);
  return (comp);
}

const int		IFactory::createEntity()
{
  int                   lifeindex;

  int index = data.nextFreeEntity();
  initComponent(index);
  return (index);
}

const std::string       &IFactory::getId() const
{
  return (id);
}
