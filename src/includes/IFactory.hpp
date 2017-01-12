// by Gabriel Goude

#ifndef IFACTORY_HPP_
# define IFACTORY_HPP_

#include <string>
#include <iostream>
#include "IComponent.hpp"

class Engine;

class IFactory
{
public:
  IFactory(Engine &, const char*);
  ~IFactory();
  const std::string& getId() const;
  const int createEntity();
  IComponent      *AddComponent(int, std::string);
  virtual const bool	initComponent(int) = 0;
protected:
  Engine	& data;
  std::string	id;
};

#endif
