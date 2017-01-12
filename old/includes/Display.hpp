//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Wed Jan  4 12:25:38 2017 Clément Arnoux
//

#ifndef DISPLAY_HPP_
# define DISPLAY_HPP_

#include "ISystem.hpp"
#include "Position.hpp"
#include "Engine.hpp"

class Display : public ISystem 
{
public:
  Display(Engine &);
  ~Display();
  const std::string   &	getId() const;
  const int		update();
  const int		apply(int);
  
private:
  std::bitset<32>	compare;
  Engine &		data;
  std::string		id;
};

#endif
