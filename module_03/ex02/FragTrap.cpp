#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	std::cout << "FragTrap constructor called for " << ClapTrap::_name << std::endl;
	_hitPoints = 100;
	std::cout << "\t- Hit pts:\t\t" << _hitPoints << std::endl;
	_energyPoints = 100;
	std::cout << "\t- Energy pts:\t\t" << _energyPoints << std::endl;
	_attackDamage = 30;
	std::cout << "\t- Attack damage:\t" << _attackDamage << std::endl;
}

FragTrap::FragTrap( std::string name )
{
	_name = name;
	std::cout << "FragTrap constructor called for " << _name << std::endl;
	_hitPoints = 100;
	std::cout << "\t- Hit pts:\t\t" << _hitPoints << std::endl;
	_energyPoints = 100;
	std::cout << "\t- Energy pts:\t\t" << _energyPoints << std::endl;
	_attackDamage = 30;
	std::cout << "\t- Attack damage:\t" << _attackDamage << std::endl;


}

FragTrap::~FragTrap()
{
	// FragTrap::ClapTrap::~ClapTrap();
	std::cout << "FragTrap destructor called for " << this->getName() << std::endl;
}

FragTrap & FragTrap::operator=( FragTrap const & inst)
{
	this->_name = inst._name;
	this->_hitPoints = inst._hitPoints;
	this->_energyPoints = inst._energyPoints;
	this->_attackDamage = inst._attackDamage;
	return *this;
}

	void FragTrap::highFiveGuys( void )
	{
		std::cout << "High five ?" << std::endl;
	}
