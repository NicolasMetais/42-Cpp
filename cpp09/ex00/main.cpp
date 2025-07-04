#include <BitcoinExchange.hpp>

int main(int av, char **ac)
{
	if (av == 2)
	{
		BitcoinExchange btc(ac[1]);
		btc.extractData();
		btc.compare();
	}
	else
		std::cerr << "Error \n could not open file." << std::endl;
}