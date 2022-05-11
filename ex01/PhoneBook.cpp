#include <cstring>
#include <cstdlib>
#include <cctype>
#include <string>
#include <iomanip>
#include <iostream>
#include <istream>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

PhoneBook::PhoneBook(/* args */)
{
	this->_index = 0;	
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::contactsPreview(void)
{
	std::cout.width(10);
	std::cout << std::right << "INDEX" << "|";
	std::cout.width(10);
	std::cout << std::right << "FIRST NAME" << "|";
	std::cout.width(10);
	std::cout << std::right << "LAST NAME" << "|";
	std::cout.width(10);
	std::cout << std::right << "NICKNAME" << std::endl;
	for (int i = 0; i < this->_index && i < 8; i++)
		this->_contact[i].displayOneContactPreview(i);
}

std::string PhoneBook::checkLength(std::string info)
{
	if (info.length() > 10)
		return (info.replace(9, info.length() - 9, ".", 1));
	return (info);
}

void PhoneBook::createContact(void)
{
	std::string firstNamePreview, lastNamePreview, nicknamePreview, firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "You just started to create a new contact" << std::endl;
	std::cout << "Please follow this easy 5 steps form:" << std::endl;
	std::cout << "(1/5)" << "First name:";
	while ((firstNamePreview = checkLength(firstName)) == "")
	{
		std::getline(std::cin, firstName);
		if (std::cin.eof())
			exit(0);
	}		
	std::cout << "(2/5)" << "Last name:";
	while ((lastNamePreview = checkLength(lastName)) == "")
	{
		std::getline(std::cin, lastName);
		if (std::cin.eof())
			exit(0);
	}		
	std::cout << "(3/5)" << "Nickname:";
	while ((nicknamePreview = checkLength(nickname)) == "")
	{
		std::getline(std::cin, nickname);
		if (std::cin.eof())
			exit(0);
	}		
	std::cout << "(4/5)" << "Phone number:";
	while (phoneNumber == "")
	{
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
			exit(0);
	}		
	std::cout << "(5/5)" << "Darkest secret:";
	while (darkestSecret == "")
	{
		std::getline(std::cin, darkestSecret);
		if (std::cin.eof())
			exit(0);
	}		
	this->_contact[this->_index % 8].updateContact(firstNamePreview, lastNamePreview, nicknamePreview, firstName, lastName, nickname, phoneNumber, darkestSecret);
	++this->_index;
}

void PhoneBook::searchContact(void)
{
	int index = this->_index;
	std::string buffer;

	if (index == 0)
	{
		std::cout << "You have no contacts saved in PhoneBook" << std::endl <<std::endl;
		return ;
	}
	this->contactsPreview();
	
	while (index < 0 || index > 7 || index >= this->_index)
	{
		std::cout << "Please enter the buffer of the contact you want to see" << std::endl;
		std::getline(std::cin, buffer);
		if (std::cin.eof())
			exit(0);
		if (buffer == "0" || buffer == "1" || buffer == "2" || buffer == "3" || buffer == "4" || buffer == "5" || buffer == "6" || buffer == "7")
			index = std::atoi(buffer.c_str());
	}
	if (index >= 0 && index < 8)
		this->_contact[index % 8].displayFullContact();
	else
		std::cout << "Error: wrong index" << std::endl;
}
