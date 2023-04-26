/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:12:04 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/23 08:43:10 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "\033[38;5;118mConstructor : it's a DOG!\033[0m" << std::endl;
	type = "Dog";
}

Dog::Dog(std::string type)
{
	std::cout << "\033[38;5;118mConstructor : it's a DOG!\033[0m" << std::endl;
	this->type = type;
}

Dog::Dog(const Dog& other)
{
	std::cout << "\e[38;5;189mDog\e[0m : Copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "\e[38;5;189mDog\e[0m : Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "\033[38;5;9mDestructor : rip DOG\033[0m" << std::endl;
}

void Dog::makeSound()
{
	std::cout << "* A bark in the dark *" << std::endl;
}
