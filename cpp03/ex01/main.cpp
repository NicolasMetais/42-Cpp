#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	ScavTrap A("A");
	ScavTrap B("B");
	ClapTrap C("C");

	A.takeDamage(5);
	B.attack("D");
	C.attack("D");
	A.beRepaired(1);
	B.takeDamage(10);
	B.attack("C");
	B.guardGate();
}