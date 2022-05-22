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
	for (int i = 0 ; i < 100 ; i++)
	{
		this->_ideas[i] = rhs._ideas[i]	;
	}
	return (*this);
}

void Brain::setIdea( int index, std::string idea )
{
	this->_ideas[index] = idea;
}

std::string & Brain::getIdea( int index )
{
	return this->_ideas[index];
}