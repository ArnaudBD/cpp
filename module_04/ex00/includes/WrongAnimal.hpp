#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>
# include <iostream>
// # include "Cat.hpp"
// # include "Dog.hpp"

class WrongAnimal
{
private:
protected:
	std::string _type;
public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal( WrongAnimal const & );
	WrongAnimal & operator=( WrongAnimal const & );

	std::string getType( void ) const;
	void makeSound( void ) const;
};

#endif