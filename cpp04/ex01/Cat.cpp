#include "Cat.hpp"

Cat::Cat() : type("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	Animal::type = type;
	brain = new Brain;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		//this->type = type;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "UwU" << std::endl;
}

std::string Cat::getType() const
{
	return this->type;
}