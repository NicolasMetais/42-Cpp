#pragma once
#include <iostream>

class Zombie {
public:
	Zombie(std::string give_name);
	~Zombie();
	void announce(void);

private:
	std::string name;

};

Zombie* newZombie(std::string name);
void randomChump(std::string name);