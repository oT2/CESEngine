//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Tue Jan  3 16:42:04 2017 Clément Arnoux
//

#ifndef ORDER_HPP_
# define ORDER_HPP_

#include "IComponent.hpp"
#include "Datagram.hpp"

struct OrderDatagram : public Datagram
{
  EVENT playerevent;
};

#endif
