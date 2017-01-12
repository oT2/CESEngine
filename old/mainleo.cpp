//
// mainleo.cpp for maintest in /home/arnoux_c/cprtype/rtype/server_src
// 
// Made by Clément Arnoux
// Login   <arnoux_c@epitech.net>
// 
// Started on  Sun Jan  1 18:23:40 2017 Clément Arnoux
// Last update Sun Jan  1 18:25:43 2017 Clément Arnoux
//

#include <chrono>
#include <iostream>

typedef std::chrono::high_resolution_clock Clock;

bool	instantiate(std::string)
{
  return (true);
}

void    init_entities(std::chrono::duration<long int>)
{

}

int	main()
{
  Clock::time_point begin;
  Clock::time_point end;
  Clock::time_point very_begin;
  std::chrono::milliseconds ms;

  begin = Clock::now();
  very_begin = begin;
  while (42)
    {
      end = Clock::now();
      ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
      if (ms.count() > 16)
	{
	  begin = Clock::now();
	  init_entities(std::chrono::duration_cast<std::chrono::seconds>(very_begin - begin));
	}
    }
  return (0);
}
