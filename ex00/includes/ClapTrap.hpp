#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# include <string>
# include <iostream>

class ClapTrap
{
private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

public:
	ClapTrap( std::string );
	~ClapTrap();
	ClapTrap & operator=( ClapTrap const & );
	ClapTrap( ClapTrap const & );

	void attack( const std::string & target);
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );

	int getAttackDamage( void );
	void setAttackDamage( unsigned int amount );
};

#endif