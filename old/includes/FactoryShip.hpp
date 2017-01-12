//
// FactoryMario.hpp for FactoryMario in /home/arnoux_c/rtype/server_src
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 19:11:16 2016 Clément Arnoux
// Last update Wed Jan  4 14:46:45 2017 Clément Arnoux
//

#ifndef FACTORYSHIP_HPP_
# define FACTORYSHIP_HPP_

#include "IFactory.hpp"
#include "Engine.hpp"

class FactoryShip : public IFactory
{
public:
  FactoryShip(Engine &);
  ~FactoryShip();
  const	bool  initComponent(int);
  const bool	create(int);
  //virtual const bool createEntity();
};

#endif
