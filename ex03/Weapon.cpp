#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

std::string const &	Weapon::getType(void)
{
	std::string const & typeREF = this->_type;
	return (typeREF);
}

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
}