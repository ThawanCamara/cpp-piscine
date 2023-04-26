/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:08:42 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/22 20:43:16 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

int	main(void)
{
	Fixed a;
	Fixed b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max(a,b) << std::endl;
	
	std::cout << (b > a) << std::endl;
	
	Fixed d(10);

	std::cout << d << std::endl;

	std::cout << d + Fixed(2.5f) << std::endl;
	std::cout << d - Fixed(2.5f) << std::endl;
	std::cout << d * Fixed(2) << std::endl;
	std::cout << d / Fixed(2.5f) << std::endl;

	return (0);
}
