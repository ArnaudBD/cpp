#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon& _weaponA;
public:
	HumanA(std::string name, Weapon& type);
	~HumanA();

	void attack( void );
};

#endif