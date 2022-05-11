#include "Zombie.hpp"
#include <cstdlib>
#include <iostream>

Zombie*	zombieHorde( int N, std::string name);

int main(int ac, char *av[])
{
	Zombie* horde;
	std::string name(av[2]);
	if (ac != 3)
		return 1;
	horde = zombieHorde(std::atoi(av[1]), name);

	for (int i = 0 ; i < std::atoi(av[1]) ; i++)
	{
		horde[i].announce();
	}

	delete [] horde;
}