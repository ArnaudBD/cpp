#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Constructor called for " << this->_name << std::endl;
	this->_zombieSound = "BraiiiiiiinnnzzzZ...";
}

Zombie::~Zombie()
{
	std::cout << this->_name << " destructor is being called" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": " << this->_zombieSound << std::endl;
}