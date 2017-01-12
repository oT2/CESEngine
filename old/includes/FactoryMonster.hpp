//
// FactoryMario.hpp for FactoryMario in /home/arnoux_c/rtype/server_src
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 19:11:16 2016 Clément Arnoux
// Last update Wed Jan  4 14:46:53 2017 Clément Arnoux
//

#ifndef FACTORYMONSTER_HPP_
# define FACTORYMONSTER_HPP_

#include "IFactory.hpp"
#include "Engine.hpp"

class FactoryMonster : public IFactory
{
public:
  FactoryMonster(Engine &);
  ~FactoryMonster();
  const	bool  initComponent(int);
  const bool	create(int);
  //virtual const bool createEntity();
};

#endif
