#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor Called" << std::endl;
	this->type = other.type;
}
Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy operator Called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "erwuwoeureuwio <- not an animal sound" << std::endl;
}
std::string Animal::getType() const
{
	return this->type;
}