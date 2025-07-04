#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Empty")
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string new_name) : 	ClapTrap(new_name)
{
	std::cout << "ScavTrap Constructor called" << std::endl;
	life = 100;
	energy = 50;
	damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
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

void ScavTrap::attack(const std::string& target)
{
	if (this->life <= 0)
	{
		std::cout << "ScavTrap " << name << " is already dead" << std::endl;
		return ;
	}
	else if (energy <= 0)
	{
		std::cout << "ScavTrap " << this->name << " has no more energy" << std::endl;
		return ;
	}
	this->energy--;
	std::cout << "ScavTrap " << this->name << " attacks " << target <<" ,causing " << this->damage << " points of damage !" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}