#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	// ScavTrap A("A");
	// ScavTrap B("B");
	// ClapTrap C("C");
	// FragTrap D("D");
	DiamondTrap E("E");

/* 	A.takeDamage(5);
	B.attack("F");
	C.attack("F");
	A.beRepaired(1);
	B.takeDamage(10);
	B.attack("F");
	B.guardGate();
	D.attack("F");
	D.highFivesGuys();
	D.takeDamage(10);
	D.beRepaired(3); */
	E.attack("F");
	E.takeDamage(10);
	E.beRepaired(2);
	E.whoAmI();

}