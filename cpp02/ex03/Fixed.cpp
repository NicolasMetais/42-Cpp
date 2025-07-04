#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fixed_point_number(0) 
{
	//std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int val) : _fixed_point_number(0) 
{
	//std::cout << "Int constructor called" << std::endl;
	_fixed_point_number = val << _fractional_bit_number;
};

Fixed::Fixed(const float val) : _fixed_point_number(0) 
{
	//std::cout << "Float constructor called" << std::endl;
	_fixed_point_number = roundf(val * (1 << _fractional_bit_number));
};

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	_fixed_point_number = other._fixed_point_number;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this!= &other)
		_fixed_point_number = other._fixed_point_number;
	return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return _fixed_point_number;
}

void Fixed::setRawBits(int const raw)
{
	_fixed_point_number = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_fixed_point_number / (1 << _fractional_bit_number);
}

int Fixed::toInt(void) const
{
	return _fixed_point_number >> _fractional_bit_number;
}
//Surcharge de l'operateur <<. Je change l'output de << pour qu'il arrive a return ma class
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator>(const Fixed &other) const {
	return this->toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed &other) const {
	return this->toFloat() < other.toFloat();
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->toFloat() <= other.toFloat();
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->toFloat() >= other.toFloat();
}

bool Fixed::operator==(const Fixed &other) const {
	return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->toFloat() != other.toFloat();
}

Fixed Fixed::operator++() {
	this->_fixed_point_number += 1;
	return *this;
}

Fixed Fixed::operator++(int) 
{
	Fixed tmp = *this;

	++this->_fixed_point_number;
	return tmp;
}

Fixed Fixed::operator--() {
	this->_fixed_point_number--;
	return *this;
}

Fixed Fixed::operator--(int) 
{
	Fixed tmp = *this;

	this->_fixed_point_number -= 1;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return a;
	else
		return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return a;
	else
		return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return a;
	else
		return b;
}