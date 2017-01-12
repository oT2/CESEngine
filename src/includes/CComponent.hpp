// by Gabriel Goude

#ifndef CCOMPONENT_HPP_
# define CCOMPONENT_HPP_

#include <string>
#include "IComponent.hpp"
#include "Msg.hpp"

#define MAX_ENTITIES 1000

typedef   IComponent *(*componentgetter)();
typedef   Msg *(*Msggetter)(IComponent*);

class CComponent
{
private:
  IComponent *_comps[MAX_ENTITIES];
  std::string             _id;
  Msggetter		Msg_maker;
  int			last;
  
public:
  CComponent(std::string, componentgetter, Msggetter);
  const std::string& getId() const;
  IComponent *operator[](int index) const;
  Msg		*getDatagram();
};

#endif
