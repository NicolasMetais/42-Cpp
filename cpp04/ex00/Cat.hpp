#pragma once
#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
	private:
		std::string type;
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();
		void makeSound() const;
		std::string getType() const;
};