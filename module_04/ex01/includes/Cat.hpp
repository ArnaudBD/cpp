#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{
private:
	/* data */
public:
	Cat(/* args */);
	// ~Cat();
	virtual ~Cat();
	Cat( Cat const & );
	Cat & operator=( Cat const & );
	virtual void makeSound( void ) const;
};

#endif