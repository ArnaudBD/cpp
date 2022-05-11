#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

void Contact::updateContact(std::string firstNamePreview, 
							std::string lastNamePreview, 
							std::string nicknamePreview, 
							std::string firstName, 
							std::string lastName, 
							std::string nickname, 
							std::string phoneNumber, 
							std::string darkestSecret)
{
	this->_firstNamePreview = firstNamePreview;
	this->_lastNamePreview = lastNamePreview;
	this->_nicknamePreview = nicknamePreview;
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

void Contact::displayOneContactPreview(int i)
{
	std::cout.width(10);
	std::cout << std::right << i << "|";
	std::cout.width(10);
	std::cout << std::right << this->_firstNamePreview << "|";
	std::cout.width(10);
	std::cout << std::right << this->_lastNamePreview << "|";
	std::cout.width(10);
	std::cout << std::right << this->_nicknamePreview << std::endl;
}

void Contact::displayFullContact(void)
{
	std::cout << "First name:\t" << this->_firstName << std::endl;
	std::cout << "Last name:\t" << this->_lastName << std::endl;
	std::cout << "Nickname:\t" << this->_nickname << std::endl;
	std::cout << "Phone number:\t" << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret:\t" << this->_darkestSecret << std::endl;	
}
