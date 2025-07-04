#include "AMateria.hpp"

AMateria::AMateria() : type("no_type") {};

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(const AMateria& other) : type(other.type) {}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::gettype() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}