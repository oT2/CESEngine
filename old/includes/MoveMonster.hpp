//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Fri Dec 30 02:47:07 2016 Clément Arnoux
//

#ifndef MOVEMONSTER_HPP_
# define MOVEMONSTER_HPP_

#include "ISystem.hpp"
#include "Position.hpp"
#include "Speed.hpp"

class MoveMonster : public ISystem 
{
public:
  MoveMonster(Data &);
  ~MoveMonster();
  const std::string   &	getId() const;
  const int		update();
  
private:
  int			value;
  std::bitset<32>	compare;
  Data &		data;
  std::string		id;
};

#endif
