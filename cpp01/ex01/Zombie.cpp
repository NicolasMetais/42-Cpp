#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie()
{
	std::cout << name << " died" << std::endl;
}

void	Zombie::set_name(std::string give_name)
{
	this->name = give_name;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}

