#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("empty_clap_name"), ScavTrap("empty_scav_name"), FragTrap("empty_frag_name"), name("clap_name")
{
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) 
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	this->life = FragTrap::life;
	this->damage = FragTrap::damage;
	this->energy = ScavTrap::energy;
	std::cout << "DiamondTrap Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) 
	: ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this!= &other)
	{
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name : " << this->name << " ClapTrap name : " << ClapTrap::name << std::endl;
}
