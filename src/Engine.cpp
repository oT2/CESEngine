//
// Engine.cpp for Engine in /home/arnoux_c/rtype/server_src
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Wed Dec 21 12:08:57 2016 Clément Arnoux
// Last update Thu Jan  5 16:32:27 2017 Clément Arnoux
//

#include "includes/Engine.hpp"
#include "includes/Vie.hpp"
#include <unistd.h>
#include <dlfcn.h>
#include <iostream>
#include <sstream>

Engine::Engine(std::list<Client*>& clients, MsgBox *tmpbox)
  : _clients(clients), _box(tmpbox)
{
  _where = 0;
  _lastplayer = 0;
}

Engine::~Engine()
{
}

bool    Engine::queueMsg(Msg *msg)
{
    _inbox->queueMsg(msg);
}

bool	Engine::hasClient(const sockaddr_in& cl) const
{
  for (std::list<Client *>::iterator it=_clients.begin(); it != _clients.end(); ++it)
    {
      if (cl == (*it)->getSock())
	return (true);
    }
  return (true);
}

const int	Engine::getClientNumber(const sockaddr_in& cl) const
{
  int	i = 0;
  for (std::list<Client *>::iterator it=_clients.begin(); it != _clients.end(); ++it)
    {
      if (cl == (*it)->getSock())
	return (i);
      ++i;
    }
  return (-1);
}

const int	Engine::getLastPlayer()
{
  return (_lastplayer++);
}

Msg	*Engine::getMessage() const
{
  return (_inbox->getMsg());
}	

void	Engine::init_entities(std::chrono::duration<long int>)
{

}

int	Engine::run()
 {
   Clock::time_point begin;
   Clock::time_point end;
   Clock::time_point very_begin;
   std::chrono::milliseconds ms;
   Datagram		*tmp;
   Msg			*msg;
   std::bitset<32>	nul;
   bool			destroyed = false;

   begin = Clock::now();
   very_begin = begin;
   while (42)
     {
       end = Clock::now();
       init_entities(std::chrono::duration_cast<std::chrono::seconds>(very_begin - end));
       ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
       if (ms.count() > 200)
	 {
	   begin = Clock::now();
	   for (int i = 0; i < _systems.size(); ++i)
	     _systems[i]->update();
	   //	   std::cout << ms.count() << "ms\n";
	   if (destroyed == false && (get_entity(0) == nul || get_entity(1) == nul))
	     {
	       std::cout << "Ship destroyed!\n";
	       destroyed = true;
	     }
	   for (int i = 0; i < _erased.size(); ++i)
	     eraseMessage(_erased[i]);
	   while ((msg = getchanges()) != NULL)
	     {
	       msg->addDest(_clients);
	       _box->queueMsg(msg);
	     }	   
	 }
     }
   return (0);
}


int	Engine::loadLib(std::string libid)
{
  void		*ptr;
  bool		system = false;
  IFactory*	Fact;
  factorygetter	getfact;
  typegetter	gettype;
  std::string	types;
  std::string	token;

  libid = "./lib" + libid + ".so";
  if ((ptr = dlopen(libid.c_str(), RTLD_LAZY)) == NULL)
    {
      std::cout << "error no lib named : " << libid << "\n";
      return (-1);
    }
  getfact = (factorygetter) dlsym(ptr, "getFactory");
  gettype = (typegetter) dlsym(ptr, "getTypes");
  types = gettype();
  std::istringstream st(types);
  while(std::getline(st, token, '.'))
    {
      if (token == ":" && system == false)
	system = true;
      else if (system == false && loadComponent(token) == -1)
	return (-1);
      if (token != ":" && system == true && loadSystem(token) == -1)
	return (-1);
    }
  Fact = getfact(*this);
  _factories.push_back(Fact);
  return (0);
}

int	Engine::loadSystem(std::string lib)
{
  void		*ptr;
  systemgetter	ss;
 
  for (int i = 0; i < _systems.size(); ++i)
    {
      if (_systems[i]->getId() == lib)
	return (0);
    }
  lib = "./lib" + lib + "System.so";
  if ((ptr = dlopen(lib.c_str(), RTLD_LAZY)) == NULL)
    {
      std::cout << "error no System named : " << lib << "\n";
      return (-1);
    }
  ss = (systemgetter) dlsym(ptr, "getSystem");
  _systems.push_back(ss(*this));
  return (0);
}

int                     Engine::loadComponent(std::string id)
{
  void                  *ptr;
  Msggetter		msgmaker;
  componentgetter       get;
  std::string		load_id;

  for (int i = 0; i < _components.size(); ++i)
    {
      if (_components[i].getId() == id)
        return (0);
    }
  load_id = "./lib" + id + "Component.so";
  if ((ptr = dlopen(load_id.c_str(), RTLD_LAZY)) == NULL)
    {
      std::cout << "error no Component amed:" << id << "\n";
      return (-1);
    }
  if ((msgmaker = (Msggetter) dlsym(ptr, "createMsg")) == NULL)
    {
      std::cout << "datagram problem" << id << "\n";
      return (-1);
    }
  if ((get = (componentgetter) dlsym(ptr, "getComponent")) == NULL)
    {
      std::cout << "getterpromblem" << id << "\n";
      return (-1);
    }
  CComponent    tmp(id, get, msgmaker);
  _components.push_back(tmp);
  return (0);
}


IFactory        *Engine::getFactory(std::string name)
{
  for (int i = 0; i < _factories.size(); ++i)
    {
      if (_factories[i]->getId() == name)
        return (_factories[i]);
    }
  if (loadLib(name) == -1)
    return (NULL);
  return (_factories[_factories.size() - 1]);
}

ISystem        *Engine::getSystem(std::string name)
{
  for (int i = 0; i < _systems.size(); ++i)
    {
      if (_systems[i]->getId() == name)
        return (_systems[i]);
    }
  if (loadSystem(name) == -1)
    return (NULL);
  return (_systems[_systems.size() - 1]);
}

int		Engine::instantiate(std::string name)
{
  int		i;
  IFactory	*fact;

  if ((fact = getFactory(name)) == false)
    return (-1);
  return (fact->createEntity());
}

int		Engine::instantiatePlayer(std::string name)
{
  std::cout << "instantiate player\n";
  return (instantiate(name));
  // for (std::list<Client *>::iterator it = _clients.begin(); it != _clients.end(); ++\
  // 	 it)
  //   {
  //     if (fact->createEntity() == false)
  // 	return (false);
  //   }
}

Msg             *Engine::getchanges()
{
  Msg           *ret;

  while (_where < _components.size())
    {
      if ((ret = _components[_where].getDatagram()) != NULL)
	return (ret);
      ++_where;
    }
  _where = 0;
  return (NULL);
}

const std::bitset<32>   & Engine::get_entity(int index)
{
  return (_entities[index]);
}

const int               Engine::getCCompIndex(std::string id) const
{
  for (int i = 0; i < _components.size(); ++i)
    {
      if (_components[i].getId() == id)
        return (i);
    }
  return (-1);
}

IComponent *Engine::getComponent(int index, std::string id) const
{
  int i = getCCompIndex(id);
  if (i != -1)
    return (_components[i][index]);
  return (NULL);
}

int             Engine::nextFreeEntity()
{
  std::bitset<32>       free_bitset;
  for (int i = 0; i < MAX_ENTITIES; ++i)
    {
      if (_entities[i] == free_bitset)
        return (i);
    }
  return (MAX_ENTITIES - 1);
}

void		Engine::eraseMessage(int i)
{
  Datagram	*d;
  Msg		*msg;

  d = new Datagram();
  d->entity_index = i;
  msg = new Msg(d, sizeof(Datagram), true);
  msg->addDest(_clients);
  _box->queueMsg(msg);
}

void            Engine::erase(int entity)
{
  _entities[entity].reset();
  _erased.push_back(entity);
}
