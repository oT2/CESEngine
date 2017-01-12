//
// Data.hpp for DATA in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 13:25:23 2016 Clément Arnoux
// Last update Fri Dec 30 01:34:42 2016 Clément Arnoux
//

#ifndef DATA_HPP_
# define DATA_HPP_

#include <bitset>
#include <vector>
#include "CComponent.hpp"

class	Data
{
private:
  std::bitset<32>	_entities[MAX_ENTITIES];
  std::vector<CComponent> _components;
  int	where;

public:
  Data();
  ~Data();
  void				erase(int);
  Msg				*getchanges();
  const	std::bitset<32>	      & get_entity(int);
  IComponent			*getComponent(int, std::string) const;
  const int			getCCompIndex(std::string) const;
  int				nextFreeEntity();
  int				AddComponent(std::string);
};

#endif
