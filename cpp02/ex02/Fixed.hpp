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
	//overload de fonction membre min
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
		//overload de fonction membre min
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	//surchage de l'operateur << pour pouvoir afficher directement les class Fixed
	friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	
private:
	int _fixed_point_number;
	static const int _fractional_bit_number = 8;
};