#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Constructor called for Brain" << std::endl; 
}

Brain::~Brain()
{
	std::cout << "Destructor called for Brain" << std::endl;
}

Brain::Brain( Brain const & copy )
{
	*this = copy;
	return ;
}

Brain & Brain::operator=( Brain const & rhs )
{
	this->_ideas = rhs._ideas;
	return (*this);
}
