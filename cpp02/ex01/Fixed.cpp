/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:59:38 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/22 16:59:39 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPoint = 0;
}

Fixed::Fixed(const int fixedPoint)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPoint = fixedPoint << FRACTION;
}

Fixed::Fixed(const float fixedPoint)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPoint = static_cast<int>(roundf(fixedPoint * (1 << FRACTION)));
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
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
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
