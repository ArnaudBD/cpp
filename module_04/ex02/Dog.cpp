#include <sstream>
#include <cstdlib>
#include "Dog.hpp"
Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Constructor called for " << this->_type << std::endl;
	this->_brain = new Brain();
	int random = rand();
	std::stringstream sstr;
	sstr << random;
	this->_brain->setIdea(0, sstr.str());
}

Dog::~Dog()
{
	std::cout << "Destructor called for " << this->_type << std::endl;
	// if (this->_brain)
	delete this->_brain;
}

Dog::Dog( Dog const & copy ) : Animal()
{
	*this = copy;
	_brain = new Brain ();
	*_brain = *(copy._brain);
	return ;
}

Dog & Dog::operator=( Dog const & rhs )
{
	this->_type = rhs._type;
	this->_brain = rhs._brain;
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "Woof!" << std::endl;
}

std::string Dog::showThought( int index )
{
	return this->_brain->getIdea( index );
}