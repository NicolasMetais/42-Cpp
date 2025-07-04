#include <iostream>

std::string JoinWithSpace(std::string concat, char **av)
{
	int	len = 0;

	while (av[len])
		len++;
	for (int i = 1; av[i]; ++i)
	{
		if (len - 1 == i)
			concat = concat + av[i];
		else
			concat = concat  + av[i] + ' ';
	}
	return (concat);
}
void PrintInUpper(std::string concat)
{
	for (int i = 0; i < (int) concat.size(); i++)
	{
		if ((int) concat.size() - 1 == i)
			std::cout << (char) toupper(concat[i]) << std::endl;
		else
			std::cout << (char) toupper(concat[i]);
	}
}
int main(int ac, char **av)
{
	std::string concat;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	concat = JoinWithSpace(concat, av);
	PrintInUpper(concat);
	return 0;
}