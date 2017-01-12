//
// FactoryMario.hpp for FactoryMario in /home/arnoux_c/rtype/server_src
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 19:11:16 2016 Clément Arnoux
// Last update Wed Jan  4 20:31:55 2017 Clément Arnoux
//

#ifndef FACTORYBACKGROUND_HPP_
# define FACTORYBACKGROUND_HPP_

#include "IFactory.hpp"
#include "Engine.hpp"

class FactoryBackground : public IFactory
{
public:
  FactoryBackground(Engine &);
  ~FactoryBackground();
  const	bool  initComponent(int);
  const bool	createEntity(int);
  //virtual const bool createEntity();
};

#endif
