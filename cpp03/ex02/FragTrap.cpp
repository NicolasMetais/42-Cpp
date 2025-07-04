#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Empty")
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string new_name) : 	ClapTrap(new_name)
{
	std::cout << "FragTrap Constructor called" << std::endl;
	life = 100;
	energy = 100;
	damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = other;
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this!= &other)
	{
		ClapTrap::operator=(other);
		this->name = other.name;
		this->life = other.life;
		this->energy = other.energy;
		this->damage = other.damage;
	}
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (this->life <= 0)
	{
		std::cout << "FragTrap " << name << " is already dead" << std::endl;
		return ;
	}
	else if (energy <= 0)
	{
		std::cout << "FragTrap " << this->name << " has no more energy" << std::endl;
		return ;
	}
	this->energy--;
	std::cout << "FragTrap " << this->name << " attacks " << target <<" ,causing " << this->damage << " points of damage !" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " requests a high five !" << std::endl;
}
