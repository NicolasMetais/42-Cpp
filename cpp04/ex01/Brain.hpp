#pragma once
#include <iostream>

class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();
};