// by Gabriel Goude

#ifndef ISYSTEM_HPP_
# define ISYSTEM_HPP_

#include <string>
#include <bitset>

class Engine;

class ISystem
{
public:
  virtual const std::string& getId() const = 0;
  virtual const int update() = 0;
  virtual const int apply(int) = 0;
};

#endif /* !ISYSTEM_H_ */
