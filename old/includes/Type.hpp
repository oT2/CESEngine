//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Fri Jan  6 01:46:48 2017 Clément Arnoux
//

#ifndef TYPE_HPP_
# define TYPE_HPP_

#include "IComponent.hpp"
#include "Datagram.hpp"

struct Type : public IComponent
{
  char	str[16];
};

struct TypeDatagram : public Datagram
{
  char	str[16];
};

#endif
