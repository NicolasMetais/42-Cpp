#include <easyfind.hpp>

int main(void)
{
	int find;

	std::vector<int> container(5);
	container[0] = 1;
	container[1] = 2;
	container[2] = 3;
	container[3] = 4;
	container[4] = 5;
	try {
		find = easyfind(container, 3);
		std::cout << find << std::endl;
	} 
	catch (...)	{
        std::cerr << "Not found " << std::endl;
	}
	try {
		find = easyfind(container, 5);
		std::cout << find << std::endl;
	}
	catch (...) {
        std::cerr << "Not found " << std::endl;
	}
}