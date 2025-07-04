#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor called" << std::endl;
	this->name = name;
	this->life = 10;
	this->energy = 10;
	this->damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->name = other.name;
	this->life = other.life;
	this->energy = other.energy;
	this->damage = other.damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this!= &other)
	{
		this->name = other.name;
		this->life = other.life;
		this->energy = other.energy;
		this->damage = other.damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->life <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;
		return ;
	}
	else if (energy <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy left" << std::endl;
		return ;
	}
	this->energy--;
	std::cout << "ClapTrap " << this->name << " attacks " << target <<" ,causing " << this->damage << " points of damage !" << std::endl;
	std::cout << "ClapTrap " << this->energy << " left" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->life <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;
		return ;
	}
	if (amount > 150)
	{
		std::cout << "Suspicious amout. Overflow ?" << std::endl;
		return ;
	}
	if (amount >= this->life)
		this->life = 0;
	else
		this->life -= amount;
	std::cout << "ClapTrap " << name << " took " << amount << " damage. " << " Hit point : "<< life << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->life <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;
		return ;
	}
	else if (this->energy <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy left" << std::endl;
		return ;
	}
	if (amount > 150)
	{
		std::cout << "Suspicious amout. Overflow ?" << std::endl;
		return ;
	}
	this->energy -= 1;
	if (amount >= this->life)
		this->life = 0;
	else
		this->life -= amount;
	std::cout << "ClapTrap " << name << " repair itself for " << amount << ". Hit point : " << life << std::endl; 
	std::cout << "Energy : " << energy << std::endl;
}