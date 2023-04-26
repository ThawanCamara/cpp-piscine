/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:40:15 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/24 18:04:59 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "\033[38;5;118mConstructor : it's an ANIMAL!\033[0m" << std::endl;
	type = "Unknown";
}

Animal::Animal(std::string type)
{	
	std::cout << "\033[38;5;118mConstructor : it's an ANIMAL!\033[0m" << std::endl;
	this->type = type;
}

Animal::Animal(const Animal& other)
{
	std::cout << "\e[38;5;189mAnimal\e[0m : Copy constructor called" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "\e[38;5;189mAnimal\e[0m : Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "\033[38;5;9mDestructor : rip ANIMAL\033[0m" << std::endl;
}

void Animal::makeSound()
{
	std::cout << "* Unknown animal noises *" << std::endl;
}

void Animal::setType(const std::string str)
{
	type = str;
}

std::string Animal::getType() const
{
	return (type);
}
