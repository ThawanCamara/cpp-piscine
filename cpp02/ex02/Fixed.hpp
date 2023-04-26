/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:08:39 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/22 17:08:40 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const int fixedPoint);
		Fixed(const float fixedPoint);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		static Fixed& min(Fixed& lvalue, Fixed& rvalue);
		static Fixed& max(Fixed& lvalue, Fixed& rvalue);
		static const Fixed& min(const Fixed& lvalue, const Fixed& rvalue);
		static const Fixed& max(const Fixed& lvalue, const Fixed& rvalue);

		Fixed operator+(const Fixed& other);
		Fixed operator-(const Fixed& other);
		Fixed operator*(const Fixed& other);
		Fixed operator/(const Fixed& other);
		Fixed operator++(void);
		Fixed operator++(int);
		Fixed operator--(void);
		Fixed operator--(int);
	
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt() const;
		float toFloat() const;
		
	private:
		int _fixedPoint;
		static const int FRACTION = 8;		
};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif
