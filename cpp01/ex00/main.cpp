#include "Zombie.hpp"

int main(void)
{

	randomChump("Zombie1");
	randomChump("Zombie2");
	randomChump("Zombie3");

	Zombie *Zombie4 = newZombie("Zombie4");
	Zombie *Zombie5 = newZombie("Zombie5");

	Zombie4->announce();
	Zombie5->announce();
	delete Zombie4;
	delete Zombie5;
}