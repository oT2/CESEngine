//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Wed Jan  4 11:05:41 2017 Clément Arnoux
//

#ifndef PLAYER_HPP_
# define PLAYER_HPP_

#include "IComponent.hpp"
#include "Datagram.hpp"

struct Player : public IComponent
{
  int number;
};

struct PlayerDatagram : public Datagram
{
  int number;
};

#endif
