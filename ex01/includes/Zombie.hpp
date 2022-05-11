#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <cstring>
#include <string>

class Zombie
{
private:
	std::string _zombieSound;
	std::string _name;
public:
	Zombie();
	~Zombie();

	void	announce( void );
	void	setName( std::string name );
};
#endif