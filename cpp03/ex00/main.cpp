#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap A("A");
	ClapTrap B("B");

	B.attack("C");
	B.takeDamage(10);
	B.attack("C");
	A.attack("C");
	A.attack("C");
	A.attack("C");
	A.attack("C");
	A.attack("C");
	A.attack("C");
	A.attack("C");
	A.attack("C");
	A.attack("C");
	A.attack("C");
	A.attack("C");
	A.attack("C");
	A.attack("C");
	A.attack("C");
	A.attack("C");
	A.attack("C");
	A.attack("C");
	A.attack("C");
	A.takeDamage(5);
	A.takeDamage(5);
	A.takeDamage(5);
	A.attack("C");
}