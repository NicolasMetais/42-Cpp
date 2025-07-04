#pragma once
#include "Weapon.hpp"

class HumanB {
public:
	HumanB(const std::string& name);
	~HumanB();
	void attack();
	void setWeapon(Weapon& weapon);
private:
	std::string name;
	Weapon		*weapon;
};