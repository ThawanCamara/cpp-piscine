#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixedPoint = 0;
}

Fixed::Fixed(const int fixedPoint)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = fixedPoint << fraction;
}

Fixed::Fixed(const float fixedPoint)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = static_cast<int>(roundf(fixedPoint * (1 << fraction)));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPoint = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& nbr)
{
	os << nbr.fixedPoint;
	return (os);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixedPoint = raw;
}

int Fixed::toInt() const
{
	return (this->fixedPoint >> fraction);
}

float Fixed::toFloat() const
{
	return (static_cast<float>(this->fixedPoint) / (1 << fraction));
}
