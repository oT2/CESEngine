//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Wed Jan  4 16:59:35 2017 Clément Arnoux
//

#ifndef SHOOT_HPP_
# define SHOOT_HPP_

#include "ISystem.hpp"
#include "Position.hpp"
#include "Speed.hpp"
#include "Vector.hpp"
#include "Engine.hpp"

class Shoot : public ISystem 
{
public:
  Shoot(Engine &);
  ~Shoot();
  const std::string   &	getId() const;
  const int		update();
  const int		apply(int);
  
private:
  bool			createMissile(int);
  int			wait;
  std::bitset<32>	compare;
  Engine &		data;
  std::string		id;
};

#endif
