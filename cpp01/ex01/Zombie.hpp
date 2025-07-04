#pragma once
#include <iostream>

class Zombie {
public:
	Zombie();
	~Zombie();
	void announce(void);
	void set_name(std::string name);

private:
	std::string name;
};

Zombie *zombieHorde(int n, std::string name);
