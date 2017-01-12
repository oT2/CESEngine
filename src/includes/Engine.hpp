// by Gabriel Goude

#ifndef _ENGINE_H_
# define _ENGINE_H_

#include <bitset>
#include <vector>
#include <chrono>
#include <thread>
#include "ISystem.hpp"
#include "IFactory.hpp"
#include "CComponent.hpp"
#include "MsgBox.hpp"

typedef IFactory      *(*factorygetter)(Engine&);
typedef std::string   (*typegetter)();
typedef ISystem       *(*systemgetter)(Engine&);
typedef std::chrono::high_resolution_clock Clock;

class           Engine {
public:
  Engine(std::list<Client*> &, MsgBox*);
  ~Engine();
  int				loadLib(std::string);
  bool				hasClient(const sockaddr_in& cl) const;
  int				run();
  int				instantiate(std::string);
  int				instantiatePlayer(std::string);
  void				erase(int);
  Msg				*getchanges();
  const std::bitset<32>		& get_entity(int);
  IComponent			*getComponent(int, std::string) const;
  const int			getCCompIndex(std::string) const;
  int				nextFreeEntity();
  int				loadComponent(std::string);
  ISystem			*getSystem(std::string);
  Msg				*getMessage() const;
  const int			getClientNumber(const sockaddr_in& cl) const;
  const int			getLastPlayer();
  bool              queueMsg(Msg *msg);
  std::thread       *gamethread;

private:
  void				eraseMessage(int);
  IFactory			*getFactory(std::string);
  void				init_entities(std::chrono::duration<long int>);
  int				loadSystem(std::string);
  MsgBox			*_inbox;
  MsgBox			*_box;
  std::list<Client*>	&	_clients;
  std::vector<ISystem *>	_systems;
  std::vector<IFactory *>	_factories;
  std::bitset<32>		_entities[MAX_ENTITIES];
  std::vector<CComponent>	_components;
  std::vector<int>		_erased;
  int				_where;
  int				_lastplayer;
};

#endif
