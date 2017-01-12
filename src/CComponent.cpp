//
// CComponent.cpp for CComponent in /home/arnoux_c/rtype/server_src
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Thu Dec 22 14:03:04 2016 Clément Arnoux
// Last update Wed Jan  4 13:16:24 2017 Clément Arnoux
//

#include "includes/CComponent.hpp"
#include <dlfcn.h>
#include <iostream>
#include <cstdlib>

CComponent::CComponent(std::string id, componentgetter get, Msggetter msgmaker)
{
  void			*ptr;

  last = 0;
  _id = id;
  std::cout << "id = " << id << std::endl;
  Msg_maker = msgmaker;
  for (int i = 0; i < MAX_ENTITIES; ++i)
    {
      _comps[i] = get();
      _comps[i]->modified = false;
    }
}

Msg		*CComponent::getDatagram()
{
  while (last < MAX_ENTITIES)
    {
      if (_comps[last]->modified == true)
	{
	  _comps[last]->modified = false;
	  return (Msg_maker(_comps[last]));
	}
      ++last;
    }
  last = 0;
  return (NULL);
}

const std::string& CComponent::getId() const
{
  return (this->_id);
}

IComponent *CComponent::operator[](int index) const
{
  return (this->_comps[index]);
}
