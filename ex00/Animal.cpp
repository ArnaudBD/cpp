#include "Animal.hpp"
Animal::Animal(/* args */)
{
}

Animal::~Animal()
{
}

Animal::Animal( Animal const & copy )
{
	*this = copy;
	return ;
}

Animal & Animal::operator=( Animal const & rhs )
{
	this->type = rhs.type;
	return (*this);
}
