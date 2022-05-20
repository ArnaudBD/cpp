#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	/* data */
public:
	WrongCat(/* args */);
	~WrongCat();
	WrongCat( WrongCat const & );
	WrongCat & operator=( WrongCat const & );
	void makeSound( void ) const;
};

#endif