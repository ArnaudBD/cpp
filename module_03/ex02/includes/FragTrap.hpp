#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
	public:
		FragTrap();
		~FragTrap();
		FragTrap( FragTrap const & );
		FragTrap & operator=( FragTrap const & );
		FragTrap( std::string );

		void highFiveGuys( void );
};

#endif