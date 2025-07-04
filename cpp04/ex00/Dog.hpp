#pragma once
#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
	private:
		std::string type;
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();
		std::string getType() const;
		void makeSound() const;
};