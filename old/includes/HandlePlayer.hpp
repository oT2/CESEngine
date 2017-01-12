//
// Vie.hpp for Vie in /home/arnoux_c/rtype/server_src/includes
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:36:22 2016 Clément Arnoux
// Last update Wed Jan  4 19:47:20 2017 Clément Arnoux
//

#ifndef HANDLEPLAYER_HPP_
# define HANDLEPLAYER_HPP_

#include "ISystem.hpp"
#include "Player.hpp"
#include "Vector.hpp"

class HandlePlayer : public ISystem 
{
public:
  HandlePlayer(Engine &);
  ~HandlePlayer();
  const std::string   &	getId() const;
  const int		update();
  const int		apply(int);
  
private:
  void	changeOrientation(int, int);
  void	handleOrder(int, int);
  std::bitset<32>	compare;
  Engine &		data;
  std::string		id;
};

#endif
