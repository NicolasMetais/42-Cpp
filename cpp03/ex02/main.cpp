#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap A("A");
	ScavTrap B("B");
	ClapTrap C("C");
	FragTrap D("D");

	A.takeDamage(5);
	B.attack("E");
	C.attack("E");
	A.beRepaired(1);
	B.takeDamage(10);
	B.attack("E");
	B.guardGate();
	D.attack("E");
	D.highFivesGuys();
	D.takeDamage(10);
	D.beRepaired(3);
}