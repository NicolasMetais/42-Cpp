#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private :
	Contact contacts[8];
	int		nb_contact;
	int		last_contact;

public:

	PhoneBook() : nb_contact(0), last_contact(0) {}

	void	display();
	void	displayAllData(int index);
	void	newContact(std::string f_name, std::string l_name, std::string phone, std::string secret, std::string nick);
};

#endif