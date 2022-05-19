#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	std::cout << "ScavTrap constructor called for " << ClapTrap::_name << std::endl;
	_hitPoints = 100;
	std::cout << "\t- Hit pts:\t\t" << _hitPoints << std::endl;
	_energyPoints = 50;
	std::cout << "\t- Energy pts:\t\t" << _energyPoints << std::endl;
	_attackDamage = 20;
	std::cout << "\t- Attack damage:\t" << _attackDamage << std::endl;
}

ScavTrap::ScavTrap( std::string name )
{
	_name = name;
	std::cout << "ScavTrap constructor called for " << _name << std::endl;
	_hitPoints = 100;
	std::cout << "\t- Hit pts:\t\t" << _hitPoints << std::endl;
	_energyPoints = 50;
	std::cout << "\t- Energy pts:\t\t" << _energyPoints << std::endl;
	_attackDamage = 20;
	std::cout << "\t- Attack damage:\t" << _attackDamage << std::endl;


}

ScavTrap::~ScavTrap()
{
	// ScavTrap::ClapTrap::~ClapTrap();
	std::cout << "ScavTrap destructor called for " << this->getName() << std::endl;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & inst)
{
	this->_name = inst._name;
	this->_hitPoints = inst._hitPoints;
	this->_energyPoints = inst._energyPoints;
	this->_attackDamage = inst._attackDamage;
	return *this;
}

void ScavTrap::attack( const std::string & name )
{
	if (this->_energyPoints > 0)
	{
		std::cout << this->_name << " pays 1pts to attack" << std::endl;
		--(this->_energyPoints);
		std::cout << "He has now " << this->_energyPoints << "pts" << std::endl;
		std::cout << "ScavTrap " << this->_name << " attacks " << name << " causing " << this->_attackDamage << std::endl;
	}
	else
	{
		std::cout << this->_name << " cannot attack without energy points!" << std::endl;
	}
}

void ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name << " is now in gate keeper mode" << std::endl;
}