#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie()
{
	std::cout << "Constructor called" << std::endl;
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

void	Zombie::setName( std::string name )
{
	this->_name = name;
}