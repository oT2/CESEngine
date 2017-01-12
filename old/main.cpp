// by Gabriel Goude

#include "includes/server.hpp"
#include "includes/Engine.hpp"
#include "includes/World.hpp"
#include <iostream>
#include <thread>

int         main(int ac, char **av)
{
    std::thread *nw_thread;
    if (ac < 2)
      exit_usage();
    World world(av[1]);
    std::cout << "wok" << std::endl;
    nw_thread = new std::thread(&World::receive_data, &world);
    world.run();
    return (0);
}

void        exit_usage()
{
  MsgBox	*m = new MsgBox();
  std::list<Client*> l;
  Engine	engine(l, m);

  engine.instantiatePlayer("Ship");
  engine.instantiate("Monster");
  engine.run();
  std::cout << "USAGE : ./RType_server PORT ..." << std::endl;
}

