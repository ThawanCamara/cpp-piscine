/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:48:26 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/23 08:23:23 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	std::cout << "\033[38;5;118mConstructor : it's a WRONGCAT!\033[0m" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(std::string type)
{
	std::cout << "\033[38;5;118mConstructor : it's a WRONGCAT!\033[0m" << std::endl;
	this->type = type;
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "\e[38;5;189mWrongCat\e[0m : Copy constructor called" << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "\e[38;5;189mWrongCat\e[0m : Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "\033[38;5;9mDestructor : rip WRONGCAT\033[0m" << std::endl;
}

void WrongCat::makeSound()
{
	std::cout << "* Wrong Meow *" << std::endl;
}
