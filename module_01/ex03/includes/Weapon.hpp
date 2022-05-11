#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
private:
	std::string _type;
public:
	Weapon(std::string name);
	Weapon();
	~Weapon();

	std::string const & getType(void);
	void	setType(std::string newType);
};

#endif