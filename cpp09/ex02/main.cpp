#include <PmergeMe.hpp>

int main(int arc, char **arv) 
{
	if (arc > 1)
	{
		PmergeMe sorting;
		try {
		sorting.parseValues(arv + 1);
		}
		catch (std::runtime_error &e) {
			std::cerr << e.what() << std::endl;
			return (0);
		}
		sorting.sort();
	}
	else
		std::cerr << "Error : give me positive numbers" << std::endl;
};