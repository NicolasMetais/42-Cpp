#pragma once
#include <iostream>
//Forme cannonique est la norme et obligatoire.
//C'est pour gerer de la memoire et pas avoir de leak + le debug
class Fixed
{
public:
	Fixed();
	//constructeur de copie pour creer un nouvel objet copie 
	//d'un deja existant
	Fixed(const Fixed& other);
	//operateur d'affectation pour remplacer le contenu 
	//de l'objet par celui d'un autre
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int	getRawBits(void) const;
	void setRawBits(int const raw);
private:
	int _fixed_point_number;
	static const int _fractional_bit_number = 8;
};