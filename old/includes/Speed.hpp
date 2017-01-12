//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Fri Dec 30 02:42:07 2016 Clément Arnoux
//

#ifndef SPEED_HPP_
# define SPEED_HPP_

#include "IComponent.hpp"
#include "Datagram.hpp"

struct Speed : public IComponent
{
  float value;
};

struct SpeedDatagram : public Datagram
{
  float value;
};

#endif
