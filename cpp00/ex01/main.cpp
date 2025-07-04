#include "PhoneBook.hpp"
#include <cstdlib>
std::string	wait_user_input(int size, std::string print, std::string *res, int is_index)
{
	while (1)
	{
		std::cout << print;
		std::getline(std::cin, *res);
		if (std::cin.eof())
        {
			std::cout << "\nStopped" << std::endl;
			*res = "\0";
            return *res;
        }
		if ((int)(*res).size() > size)
		{
			std::cout << "Error \n Too long" << std::endl;
		}
		else if ((*res).size() == 0)
			std::cout << "Error \n Empty line" << std::endl;
		else if (is_index && (std::atoi((*res).c_str()) > 7 || std::atoi((*res).c_str()) < 0))
		{
			std::cout << "Error \n 0 to 7 range or nothing" << std::endl;
		}
		else 
			break;
	}
	return *res;
}

void	input_new_infos(PhoneBook &phonebook)
{
	std::string	f_name, l_name, nick, phone, secret;

	wait_user_input(50, "Enter a first name: ", &f_name, 0);
	if (f_name.empty())
		return ;
	wait_user_input(50, "Enter a last name: ", &l_name, 0);
	if (l_name.empty())
		return ;
	wait_user_input(50, "Enter a nickname: ", &nick, 0);
	if (nick.empty())
		return ;
	wait_user_input(10, "Enter a phone number: ", &phone, 0);
	if (phone.empty())
		return ;
	wait_user_input(100, "Tell me your darkest secret: ", &secret, 0);
	if (secret.empty())
		return ;
	phonebook.newContact(f_name, l_name, phone, secret, nick);
}

void	searching_contact(PhoneBook &phonebook)
{
	std::string index;
	phonebook.display();
	wait_user_input(3, "Give me an index: ", &index, 1);
	if (index.empty())
		return ;
	phonebook.displayAllData(std::atoi(index.c_str()));
}

void	launchPhoneBook()
{
	PhoneBook phonebook;
	std::string line;

	std::cout << "Type ADD, SEARCH or EXIT" << std::endl;
	while(1)
	{
		std::cout << "Phone Book > ";
		std::getline(std::cin, line);
		if (std::cin.eof())
			break ;
		else if (line == "ADD")
			input_new_infos(phonebook);
		else if (line == "SEARCH")
			searching_contact(phonebook);
		else if (line == "EXIT")
			break ;
	}
}
int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
		return 0;
	launchPhoneBook();
}
