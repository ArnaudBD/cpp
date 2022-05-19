#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{
private:
	/* data */
public:
	Cat(/* args */);
	~Cat();
	Cat( Cat const & );
	Cat & operator=( Cat const & );
	void makeSound( void );
};

#endif