/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:08:30 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/22 21:26:00 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	_fixedPoint = 0;
}

Fixed::Fixed(const int fixedPoint)
{
	_fixedPoint = fixedPoint << FRACTION;
}

Fixed::Fixed(const float fixedPoint)
{
	_fixedPoint = static_cast<int>(roundf(fixedPoint * (1 << FRACTION)));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		_fixedPoint = other.getRawBits();
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
	return (_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPoint = raw;
}

int Fixed::toInt() const
{
	return (_fixedPoint >> FRACTION);
}

float Fixed::toFloat() const
{
	return (static_cast<float>(_fixedPoint) / (1 << FRACTION));
}

Fixed Fixed::operator+(const Fixed& other)
{
	Fixed ret;
	ret._fixedPoint = _fixedPoint + other.getRawBits();
	return (ret);
}

Fixed Fixed::operator-(const Fixed& other)
{
	Fixed ret;
	ret._fixedPoint = _fixedPoint - other.getRawBits();
	return (ret);
}

Fixed Fixed::operator*(const Fixed& other)
{
	Fixed ret;
	ret._fixedPoint = _fixedPoint * (other.getRawBits() >> FRACTION);
	return (ret);
}

Fixed Fixed::operator/(const Fixed& other)
{
	Fixed ret;
	ret._fixedPoint = _fixedPoint * (1 << FRACTION) / other.getRawBits();
	return (ret);
}

//++a
Fixed Fixed::operator++(void)
{
	_fixedPoint++;
	return (*this);
}

//a++
Fixed Fixed::operator++(int)
{
	Fixed ret;

	ret.setRawBits(_fixedPoint);
	_fixedPoint++;
	return (ret);
}

Fixed Fixed::operator--(void)
{
	_fixedPoint--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed ret;

	ret.setRawBits(_fixedPoint);
	_fixedPoint--;
	return (ret);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (_fixedPoint > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
	return (_fixedPoint < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (_fixedPoint >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (_fixedPoint <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (_fixedPoint == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (_fixedPoint != other.getRawBits());
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
