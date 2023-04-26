/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:18:30 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/24 17:44:30 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

int main()
{
	int totalAnimals = 4;
	Animal *fauna[totalAnimals];

	//Animal x;

	for (int i = 0; i < totalAnimals; i++)
	{
		if (i < totalAnimals / 2)
		{
			fauna[i] = new Dog;
			// fauna[i] = new Animal;
			std::cout << fauna[i]->getType() << std::endl;
			fauna[i]->makeSound();
		}
		else
		{
			fauna[i] = new Cat;
			std::cout << fauna[i]->getType() << std::endl;
			fauna[i]->makeSound();
		}
	}
	for (int i = 0; i < totalAnimals; i++)
	{
		delete fauna[i];
	}
	
	return (0);
}
