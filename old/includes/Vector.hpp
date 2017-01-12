//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Mon Jan  2 11:33:01 2017 Clément Arnoux
//

#ifndef VECTOR_HPP_
# define VECTOR_HPP_

#include "IComponent.hpp"
#include "Datagram.hpp"

struct Vector : public IComponent
{
  float x;
  float y;
};

struct VectorDatagram : public Datagram
{
  float x;
  float y;
};

#endif
