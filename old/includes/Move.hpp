//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Wed Jan  4 20:33:13 2017 Clément Arnoux
//

#ifndef MOVE_HPP_
# define MOVE_HPP_

#include "ISystem.hpp"
#include "Position.hpp"
#include "Speed.hpp"
#include "Vector.hpp"

class Move : public ISystem 
{
public:
  Move(Engine &);
  ~Move();
  const std::string   &	getId() const;
  const int		update();
  const int		apply(int);
  
private:
  std::bitset<32>	compare;
  Engine &		data;
  std::string		id;
};

#endif
