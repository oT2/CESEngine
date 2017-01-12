//
// FactoryMario.hpp for FactoryMario in /home/arnoux_c/rtype/server_src
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 19:11:16 2016 Clément Arnoux
// Last update Tue Jan  3 10:09:40 2017 Clément Arnoux
//

#ifndef FACTORYMARIO_HPP_
# define FACTORYMARIO_HPP_

#include "IFactory.hpp"

class FactoryMario : public IFactory
{
public:
  FactoryMario(Engine &);
  ~FactoryMario();
  const	bool  initComponent(int);
  //virtual const bool createEntity();
};

#endif
