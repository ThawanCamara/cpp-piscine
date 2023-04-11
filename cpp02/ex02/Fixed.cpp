#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedPoint = 0;
}

Fixed::Fixed(const int fixedPoint)
{
	this->fixedPoint = fixedPoint << fraction;
}

Fixed::Fixed(const float fixedPoint)
{
	this->fixedPoint = static_cast<int>(roundf(fixedPoint * (1 << fraction)));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->fixedPoint = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& nbr)
{
	os << nbr.toFloat();
	return (os);
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits(void) const
{
	return (fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
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

Fixed Fixed::operator+(const Fixed& other)
{
	Fixed ret;
	ret.fixedPoint = fixedPoint + other.getRawBits();
	return (ret);
}

Fixed Fixed::operator-(const Fixed& other)
{
	Fixed ret;
	ret.fixedPoint = fixedPoint - other.getRawBits();
	return (ret);
}

Fixed Fixed::operator*(const Fixed& other)
{
	Fixed ret;
	ret.fixedPoint = fixedPoint * (other.getRawBits() >> fraction);
	return (ret);
}

Fixed Fixed::operator/(const Fixed& other)
{
	Fixed ret;
	ret.fixedPoint = fixedPoint * (1 << fraction) / other.getRawBits();
	return (ret);
}
	
Fixed Fixed::operator++(void)
{
	this->fixedPoint++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed ret;

	ret.setRawBits(fixedPoint);
	fixedPoint++;
	return (ret);
}

Fixed Fixed::operator--(void)
{
	this->fixedPoint--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed ret;

	ret.setRawBits(fixedPoint);
	fixedPoint--;
	return (ret);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (fixedPoint > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
	return (fixedPoint < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (fixedPoint >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (fixedPoint <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (fixedPoint == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (fixedPoint != other.getRawBits());
}

Fixed& Fixed::min(Fixed& lvalue, Fixed& rvalue)
{
	if (lvalue < rvalue)
		return (lvalue);
	else
		return (rvalue);
}
Fixed& Fixed::max(Fixed& lvalue, Fixed& rvalue)
{
	if (lvalue > rvalue)
		return (lvalue);
	else
		return (rvalue);
}
const Fixed& Fixed::min(const Fixed& lvalue, const Fixed& rvalue)
{
	if (lvalue < rvalue)
		return (lvalue);
	else
		return (rvalue);
}
const Fixed& Fixed::max(const Fixed& lvalue, const Fixed& rvalue)
{
	if (lvalue > rvalue)
		return (lvalue);
	else
		return (rvalue);
}
