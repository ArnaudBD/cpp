#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap( ScavTrap const & );
		ScavTrap & operator=( ScavTrap const & );
		ScavTrap( std::string );
		
		void guardGate( void );
		void attack( const std::string & );
};

#endif