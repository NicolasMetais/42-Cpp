#pragma once
//#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		~Cure();
		AMateria* clone() const;
		void use(ICharacter& target);
};