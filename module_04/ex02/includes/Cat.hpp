#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;
public:
	Cat(/* args */);
	// ~Cat();
	virtual ~Cat();
	Cat( Cat const & );
	Cat & operator=( Cat const & );
	virtual void makeSound( void ) const;
};

#endif