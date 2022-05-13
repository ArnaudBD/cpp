#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name)
{
	_weaponB = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& newType)
{
	this->_weaponB = &newType;
}

void HumanB::attack( void )
{
	if (this->_weaponB)
		std::cout << this->_name << " attacks with their " << this->_weaponB->getType() << std::endl;
	else
		std::cout << this->_name << " does not have any weapon!" << std::endl;
}