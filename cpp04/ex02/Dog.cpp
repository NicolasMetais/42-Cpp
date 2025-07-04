#include "Dog.hpp"

Dog::Dog() : type("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
	Animal::type = type;
	brain = new Brain;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		//this->type = type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Bark" << std::endl;
}

std::string Dog::getType() const
{
	return this->type;
}
