#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include "Contact.class.hpp"

class PhoneBook
{
private:
	Contact _contact[8];
	int _index;

public:
	PhoneBook(/* args */);
	~PhoneBook();

	void createContact(void);
	void searchContact(void);
	void contactsPreview(void);
	std::string checkLength(std::string info);

};

#endif