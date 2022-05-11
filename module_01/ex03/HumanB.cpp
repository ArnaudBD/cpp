#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name)
{
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
	std::cout << this->_name << " attacks with their " << this->_weaponB->getType() << std::endl;
}