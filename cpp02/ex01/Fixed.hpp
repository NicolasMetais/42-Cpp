#pragma once
#include <iostream>
//Forme cannonique est la norme et obligatoire.
//C'est pour gerer de la memoire et pas avoir de leak + le debug
class Fixed
{
public:
	//je peux creer plusieur constructeur tant que c'est different
	Fixed();
	Fixed(const int val);
	Fixed(const float val);
	//constructeur de copie pour creer un nouvel objet copie 
	//d'un deja existant
	Fixed(const Fixed& other);
	//operateur d'affectation pour remplacer le contenu 
	//de l'objet par celui d'un autre
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	//surchage de l'operateur << pour pouvoir afficher directement les class Fixed
	friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
private:
	int _fixed_point_number;
	static const int _fractional_bit_number = 8;
};