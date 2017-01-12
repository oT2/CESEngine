//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Thu Jan  5 14:01:36 2017 Clément Arnoux
//

#ifndef HANDLEPLAYER_HPP_
# define HANDLEPLAYER_HPP_

#include "ISystem.hpp"
#include "Behaviour.hpp"
#include "Position.hpp"
#include "Vector.hpp"

class HandleBehaviour : public ISystem 
{
public:
  HandleBehaviour(Engine &);
  ~HandleBehaviour();
  const std::string   &	getId() const;
  const int		update();
  const int		apply(int);
  
private:
  bool			comparediff(int, int ,int);
  std::bitset<32>	compare;
  Engine &		data;
  std::string		id;
};

#endif
