#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		templates[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.templates[i])
			templates[i] = other.templates[i]->clone();
		else
			templates[i] = 0;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (templates[i])
				delete templates[i];
			if (other.templates[i])
				templates[i] = other.templates[i]->clone();
			else
				templates[i] = 0;
		}
	}
	return *this;

}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] != 0)
		{
			delete templates[i];
			templates[i] = 0;
		}
	}
}

void MateriaSource::learnMateria(AMateria* new_temp)
{
	for (int i = 0; i < 4; i++)
	{
		if (!templates[i])
		{
			templates[i] = new_temp->clone();
			delete new_temp;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] && templates[i]->gettype() == type)
		{
			return templates[i]->clone();
		}
	}
	return 0;
}