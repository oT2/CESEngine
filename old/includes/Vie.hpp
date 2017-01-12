//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Tue Dec 27 18:51:53 2016 Clément Arnoux
//

#ifndef VIE_HPP_
# define VIE_HPP_

#include "IComponent.hpp"
#include "Datagram.hpp"

struct Vie : public IComponent
{
  int value;
};

struct VieDatagram : public Datagram
{
  int value;
};

// class Vie : public IComponent
// {
// public:
//   Vie();
//   Vie(int);
//   ~Vie();
//   void	Add(int);
//   void	Set(int);
  
// private:
//   int value;
// };

#endif
