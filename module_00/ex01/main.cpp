#include <cstring>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int main()
{
	std::string command;
	PhoneBook phonebook;
	std::cout << "Welcome to PhoneBook, the best phone book for professionals" << std::endl;
	while (command != "EXIT")
	{
		std::cout << "Please enter one of the following commands:" << std::endl;
		std::cout << "\t- ADD:\t\tadd a contact," << std::endl << "\t- SEARCH:\tfind a saved contact" << std::endl << "\t- EXIT:\t\texit." << std::endl;
		command = "";
		if (std::cin.eof())
			exit(0);
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.createContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
	}
	return (0);
}