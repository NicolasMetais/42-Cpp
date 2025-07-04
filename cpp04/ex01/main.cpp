#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *Animals[100];
	Animal *test;

	for(int i = 0; i < 100; i++)
	{
		if (i < 50)
			Animals[i] = new Dog();
		else
			Animals[i] = new Cat();
	}

	std::cout << "deep copy" << std::endl;
	test = Animals[5];
	std::cout << test->getType() << std::endl;


	std::cout << "----------------- Delete Animals -------------" << std::endl;
	for(int i = 0; i < 100; i++)
	delete Animals[i];
	return 0;
}
