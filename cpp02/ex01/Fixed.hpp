/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:07:28 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/22 17:07:29 by tde-souz         ###   ########.fr       */
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
