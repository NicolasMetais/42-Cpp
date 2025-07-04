#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon)
	: name(name), weapon(weapon) {}

HumanA::~HumanA() {
	std::cout << name << " died" << std::endl;
}

void HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}