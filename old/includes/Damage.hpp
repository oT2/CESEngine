//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Tue Dec 27 16:59:09 2016 Clément Arnoux
//

#ifndef DAMAGE_HPP_
# define DAMAGE_HPP_

#include "ISystem.hpp"

class Damage : public ISystem 
{
public:
  Damage(Data &d);
  ~Damage();
  const std::string   &	getId() const;
  const int		update();
  const int		apply(int entity_index);
  
private:
  int			value;
  std::bitset<32>	compare;
  Data &		data;
  std::string		id;
};

#endif
