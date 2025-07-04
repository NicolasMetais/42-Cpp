#include "PhoneBook.hpp"

void	PhoneBook::display()
{
	for(int i = 0; i < nb_contact; i++)
	{
		std::cout << "         " << i << "|";
		contacts[i].display_contact();
	}
}
void	PhoneBook::displayAllData(int index)
{
	if (index >= nb_contact)
		std::cout << "This contact does not exist" << std::endl;
	else
		contacts[index].displayOneContact();

}
void	PhoneBook::newContact(std::string f_name, std::string l_name, std::string phone, std::string secret, std::string nick)
{
	if (nb_contact == 8)
		last_contact = 0;
	contacts[last_contact].addContact(f_name, l_name, phone, secret, nick);
	if (nb_contact < 8)
		nb_contact++;
	last_contact = (last_contact + 1) % 8;
}