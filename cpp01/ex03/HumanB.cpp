#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
	:name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

HumanB::~HumanB() {
	std::cout << name << " died" << std::endl;
}

void HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}