#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;
public:
	Dog(/* args */);
	virtual ~Dog();
	Dog( Dog const & );
	Dog & operator=( Dog const & );
	virtual void makeSound( void ) const;

	std::string showThought( int );
};

#endif