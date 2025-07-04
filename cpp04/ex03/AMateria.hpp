#pragma once
#include "ICharacter.hpp"
#include <iostream>

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();
		std::string const &gettype() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};