#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
# include <cstring>
# include <iomanip>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
	std::string _firstNamePreview;
	std::string _lastNamePreview;
	std::string _nicknamePreview;

public:
	Contact(/* args */);
	~Contact();
	void updateContact(	std::string firstNamePreview,
						std::string lastNamePreview,
						std::string nicknamePreview, 
						std::string firstName, 
						std::string lastName, 
						std::string nickname, 
						std::string phoneNumber, 
						std::string darkestSecret);
	void displayOneContactPreview(int i);
	void displayFullContact(void);
};

#endif