#include "HumanA.hpp"

HumanA::HumanA(std::string humanName,  Weapon& weaponName) : _name(humanName), _weaponA(weaponName)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attacks whith their " << this->_weaponA.getType() << std::endl;
}