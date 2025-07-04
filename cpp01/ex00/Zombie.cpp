#include "Zombie.hpp"

Zombie::Zombie(std::string give_name){
	name = give_name;
}

Zombie::~Zombie()
{
	std::cout << name << " died" << std::endl;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}

