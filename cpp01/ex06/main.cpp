#include "Harl.hpp"

void harlfilter(char *av)
{
	Harl harl;
	std::string	arg = av;

	harl.complain(arg);
}

int main(int ac, char **av)
{
	if (ac == 2)
		harlfilter(av[1]);
	else
		std::cerr << "Wrong arg number";
}