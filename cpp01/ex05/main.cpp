#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << "INFO : ";
	harl.complain("INFO");

	std::cout << "DEBUG : ";
	harl.complain("DEBUG");

	std::cout << "ERROR : ";
	harl.complain("ERROR");
	
	std::cout << "WARNING : ";
	harl.complain("WARNING");
}