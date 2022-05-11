#include "Zombie.hpp"
#include <iostream>

void	randomChump( std::string name )
{
	Zombie zombie(name);
	zombie.announce();
	std::cout << "The destructor is not called yet" << std::endl;
}