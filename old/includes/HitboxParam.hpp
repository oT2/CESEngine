//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Fri Dec 30 01:51:47 2016 Clément Arnoux
//

#ifndef HITBOXPARAM_HPP_
# define HITBOXPARAM_HPP_

#include "IComponent.hpp"
#include "Datagram.hpp"

struct HitboxParam : public IComponent
{
  int hiting;
  bool player;
};

struct HitboxParamDatagram : public Datagram
{
  int hiting;
  bool player;
};

#endif
