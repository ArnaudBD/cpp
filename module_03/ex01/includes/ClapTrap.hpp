#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# include <string>
# include <iostream>

class ClapTrap
{
protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

public:
	ClapTrap();
	~ClapTrap();
	ClapTrap & operator=( ClapTrap const & );
	ClapTrap( ClapTrap const & );

	ClapTrap( std::string );

	void attack( const std::string & target);
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );

	int getAttackDamage( void );
	void setAttackDamage( unsigned int amount );
	std::string & getName();
};

#endif