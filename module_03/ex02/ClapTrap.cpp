#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name( name )
{
	std::cout << "ClapTrap constructor called for " << _name << std::endl;
	_hitPoints = 10;
	std::cout << "\t- Hit pts:\t\t" << _hitPoints << std::endl;
	_energyPoints = 10;
	std::cout << "\t- Energy pts:\t\t" << _energyPoints << std::endl;
	_attackDamage = 0;
	std::cout << "\t- Attack damage:\t" << _attackDamage << std::endl;
}

ClapTrap::ClapTrap( void ) : _name( "No Name" )
{
	std::cout << "ClapTrap constructor called for " << _name << std::endl;
	_hitPoints = 10;
	std::cout << "\t- Hit pts:\t\t" << _hitPoints << std::endl;
	_energyPoints = 10;
	std::cout << "\t- Energy pts:\t\t" << _energyPoints << std::endl;
	_attackDamage = 0;
	std::cout << "\t- Attack damage:\t" << _attackDamage << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

void ClapTrap::attack( const std::string & name )
{
	if (this->_energyPoints > 0)
	{
		std::cout << this->_name << " pays 1pts to attack" << std::endl;
		--(this->_energyPoints);
		std::cout << "He has now " << this->_energyPoints << "pts" << std::endl;
		std::cout << "ClapTrap " << this->_name << " attacks " << name << " causing " << this->_attackDamage << std::endl;
	}
	else
	{
		std::cout << this->_name << " cannot attack without energy points!" << std::endl;
	}
}

ClapTrap & ClapTrap::operator=( ClapTrap const & inst)
{
	this->_name = inst._name;
	this->_hitPoints = inst._hitPoints;
	this->_energyPoints = inst._energyPoints;
	this->_attackDamage = inst._attackDamage;
	return *this;
}

void ClapTrap::takeDamage( unsigned int amount )
{
	this->_energyPoints -= amount;
	std::cout << this->_name << " have now " << this->_energyPoints << " energy points" << std::endl;
}
void ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_energyPoints > 0)
	{
		std::cout << this->_name << " pays 1pts to attack" << std::endl;
		--(this->_energyPoints);
		std::cout << "He has now " << this->_energyPoints << "pts" << std::endl;
		std::cout << "ClapTrap " << this->_name << " is being repaired" << std::endl;
		this->_energyPoints += amount;
		std::cout << "He has now " << this->_energyPoints << "pts" << std::endl;
	}
	else
	{
		std::cout << this->_name << " cannot be repaired without energy points!" << std::endl;
	}
}

int ClapTrap::getAttackDamage( void )
{
	return (this->_attackDamage);
}

void ClapTrap::setAttackDamage( unsigned int amount )
{
	this->_attackDamage += amount;
	std::cout << this->_name << " attack damage points: " << this->_attackDamage << std::endl;
}

std::string & ClapTrap::getName()
{
	return (this->_name);
}
