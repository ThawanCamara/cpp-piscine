/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:48:26 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/23 00:08:52 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "\033[38;5;118mConstructor : it's a CAT!\033[0m" << std::endl;
	type = "Cat";
}

Cat::Cat(std::string type)
{
	std::cout << "\033[38;5;118mConstructor : it's a CAT!\033[0m" << std::endl;
	this->type = type;
}

Cat::Cat(const Cat& other)
{
	std::cout << "\e[38;5;189mCat\e[0m : Copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "\e[38;5;189mCat\e[0m : Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "\033[38;5;9mDestructor : rip CAT\033[0m" << std::endl;
}

void Cat::makeSound()
{
	std::cout << "* Meow *" << std::endl;
}
