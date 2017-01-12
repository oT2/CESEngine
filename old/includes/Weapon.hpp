//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Mon Jan  2 15:50:29 2017 Clément Arnoux
//

#ifndef Weapon_HPP_
# define Weapon_HPP_

#include "IComponent.hpp"
#include "Datagram.hpp"

struct Weapon : public IComponent
{
  bool continuous;
};

struct WeaponDatagram : public Datagram
{
  bool continuous;
};

#endif
