#pragma once
#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string new_name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		virtual ~ScavTrap();
		void attack(const std::string& target);
		void guardGate();
};