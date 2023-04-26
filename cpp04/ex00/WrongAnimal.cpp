/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 08:18:11 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/23 08:19:55 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << "\033[38;5;118mConstructor : it's a WRONG ANIMAL!\033[0m" << std::endl;
	type = "Unknown";
}

WrongAnimal::WrongAnimal(std::string type)
{	
	std::cout << "\033[38;5;118mConstructor : it's a WRONG ANIMAL!\033[0m" << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "\e[38;5;189mWrongAnimal\e[0m : Copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "\e[38;5;189mWrongAnimal\e[0m : Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[38;5;9mDestructor : rip WRONG ANIMAL\033[0m" << std::endl;
}

void WrongAnimal::makeSound()
{
	std::cout << "* Unknown wrong animal noises *" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}
