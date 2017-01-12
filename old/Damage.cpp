//
// Damage.cpp for Damage in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 13:08:41 2016 Clément Arnoux
// Last update Wed Dec 28 02:31:57 2016 Clément Arnoux
//

#include "includes/Damage.hpp"
#include "includes/Vie.hpp"
#include <iostream>

Damage::Damage(Data &d)
  : data(d)
{
  compare.set(d.getCCompIndex("Vie"));
  id = "Damage";
}

Damage::~Damage()
{

}

const std::string	& Damage::getId() const
{
  return (id);
}

const int		Damage::update()
{
  return (0);
}

const int		Damage::apply(int entity_index)
{
  Vie			*vie;

  if ((data.get_entity(entity_index) & compare) == compare)
    {
      vie = (Vie*) data.getComponent(entity_index, "Vie");
      vie->value -= 20;
      std::cout << "vie = " << vie->value << std::endl;
    } 
}

extern "C" ISystem	*getSystem(Data &data)
{
  return (new Damage(data));
}
