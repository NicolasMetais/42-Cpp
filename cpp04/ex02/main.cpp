#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	//Je ne peux plus faire ca, animal n'existe plus vraiment
	//const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	//Idem
	//meta->makeSound();
	//delete meta;
	delete j;
	delete i;
	
	return 0;
}
