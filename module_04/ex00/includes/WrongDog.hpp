#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP
# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
private:
	/* data */
public:
	WrongDog(/* args */);
	~WrongDog();
	WrongDog( WrongDog const & );
	WrongDog & operator=( WrongDog const & );
	void makeSound( void ) const;
};

#endif