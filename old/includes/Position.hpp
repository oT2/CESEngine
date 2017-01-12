//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Fri Dec 30 02:36:22 2016 Clément Arnoux
//

#ifndef POSITION_HPP_
# define POSITION_HPP_

#include "IComponent.hpp"
#include "Datagram.hpp"

struct Position : public IComponent
{
  float x;
  float y;
};

struct PositionDatagram : public Datagram
{
  float x;
  float y;
};

#endif
