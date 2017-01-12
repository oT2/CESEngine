//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Wed Jan  4 00:21:09 2017 Clément Arnoux
//

#ifndef HITBOX_HPP_
# define HITBOX_HPP_

#include "ISystem.hpp"
#include "Position.hpp"
#include "HitboxParam.hpp"

class Hitbox : public ISystem 
{
public:
  Hitbox(Engine &);
  ~Hitbox();
  const ISystem		*get_hitsystem(std::string & sys_id);
  const bool		check_position(Position *pos_a, Position *pos_b);
  const std::string   &	getId() const;
  const int		update();
  const bool		Hit(int entity, int entity_hiting);
  const int		apply(int);
  
private:
  int			value;
  std::bitset<32>	compare;
  Engine &		data;
  std::string		id;
};

#endif
