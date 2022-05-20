#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>
// # include "Cat.hpp"
// # include "Dog.hpp"

class Animal
{
private:
protected:
	std::string _type;
public:
	Animal();
	// ~Animal();
	virtual ~Animal();
	Animal( Animal const & );
	Animal & operator=( Animal const & );

	std::string getType( void ) const;
	virtual void makeSound( void ) const;
};

#endif