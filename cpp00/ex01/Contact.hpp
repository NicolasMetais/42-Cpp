#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

public:
	void addContact(std::string f_name, std::string l_name, std::string phone, std::string secret, std::string nick);
	void displayOneContact();
	void display_contact();
	void charTooLong(std::string str);
};

#endif
