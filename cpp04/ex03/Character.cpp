#include "Character.hpp"

Character::Character() 
{
	for(int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::Character(std::string const &name) : name(name) 
{
	for(int i = 0; i < 4; i++)
		inventory[i] = 0;
};

Character::Character(const Character& other)
{
	for(int i = 0; i < 4; i++)
	{
		delete inventory[i];
		inventory[i] = 0;
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		for(int i = 0; i < 4; i++)
		{
			if (other.inventory[i])
				inventory[i] = other.inventory[i];
			else
				inventory[i] = 0;
		}
	}
	return *this;
}

Character::~Character()
{
	for(int i = 0; i < 4; i++)
	{
		if (inventory[i] != 0)
		{
			delete inventory[i];
			inventory[i] = 0;
		}
	}
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	for(int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return ;
		}
	}
	std::cout << "Bruh, Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
	{
		inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}