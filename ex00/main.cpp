#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int main()
{
	Zombie*	zombie_ptr;

	randomChump("Crocodile");
	std::cout << "Random Chump is now destroyed" << std::endl;
	zombie_ptr = newZombie("Aligator");
	std::cout << "Lets the new Zombie annouce himself so we can see his name" << std::endl;
	zombie_ptr->announce();
	delete zombie_ptr;
	std::cout << "You see that the new zombie is destroyed before the end of the program" << std::endl;

	return (0);
}
