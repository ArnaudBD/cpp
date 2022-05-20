#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
private:
	/* data */
public:
	Dog(/* args */);
	~Dog();
	Dog( Dog const & );
	Dog & operator=( Dog const & );
	virtual void makeSound( void ) const;
};

#endif