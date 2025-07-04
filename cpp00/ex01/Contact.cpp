#include "Contact.hpp"

void Contact::addContact(std::string first_name, std::string l_name, std::string phone, std::string secret, std::string nick)
{
	this->first_name = first_name;
	last_name = l_name;
	darkest_secret = secret;
	nickname = nick;
	phone_number = phone ;
}

void Contact::displayOneContact()
{
	std::cout << first_name << std::endl << last_name << std::endl << nickname << std::endl
			<< phone_number << std::endl << darkest_secret << std::endl;
}

void Contact::display_contact()
{
	int	size = 0;

	if (first_name.size() > 10)
		charTooLong(first_name);
	else
	{
		size = 10 - first_name.size();
		for(int i = 0; i < size; i++)
		{
			std::cout << " ";
		}
		std::cout << first_name;
	}
	std::cout << "|";
	if (last_name.size() > 10)
		charTooLong(last_name);
	else 
	{
		size = 10 - last_name.size();
		for(int i = 0; i < size; i++)
		{
			std::cout << " ";
		}
		std::cout << last_name;
	}
	std::cout << "|";
	if (nickname.size() > 10)
		charTooLong(nickname);
	else
	{
		size = 10 - nickname.size();
		for(int i = 0; i < size; i++)
		{
			std::cout << " ";
		}
		std::cout << nickname;
	}
	std::cout << "\n";
	
}

void Contact::charTooLong(std::string str)
{
	for(int i = 0; i < 10; i++)
	{
		if (i == 9)
			std::cout << ".";
		else
			std::cout << str[i];
	}
}