//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Thu Jan  5 13:09:53 2017 Clément Arnoux
//

#ifndef BEHAVIOUR_HPP_
# define BEHAVIOUR_HPP_

#include <vector>
#include <utility>
#include "IComponent.hpp"
#include "Datagram.hpp"

struct Behaviour : public IComponent
{
  std::vector<std::pair<int, int> >	orientation;
  std::vector<std::pair<int, int> >	conditions;
  int					lastx;
  int					lasty;
  int					i;
};

struct BehaviourDatagram : public Datagram
{
  std::vector<std::pair<int, int> >	orientation;
  std::vector<std::pair<int, int> >	conditions;
  int					lastx;
  int					lasty;
  int					i;
};

#endif
