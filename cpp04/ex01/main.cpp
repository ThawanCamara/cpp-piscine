/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:18:30 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/24 18:11:26 by tde-souz         ###   ########.fr       */
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

	for (int i = 0; i < totalAnimals; i++)
	{
		if (i < totalAnimals / 2)
		{
			fauna[i] = new Dog;
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

	Cat *a = new Cat;
	//Dog *a = new Dog;
	//Cat a;
	//Dog a;

	std::cout << "[ Before ] Animal a : " << a->getBrain()->getTotalIdeas() << std::endl;
	a->getBrain()->makeMyMind("Sopa é sopa");
	a->getBrain()->makeMyMind("Não há sopa");
	std::cout << "[ After ]  Animal a: " << a->getBrain()->getTotalIdeas() << std::endl;

	// Teste para o limite de pensamentos
	// for (int i = 0; i < 100; i++)
	// 	a.getBrain()->makeMyMind("Gostaria de repetir a sopa");
	
	a->getBrain()->readMyMind();

	// Bizarro!
	// Teste da copia profunda (problems)
	// Cat *b = a;
	// b->setType("fuu");
	// std::cout << "type of a: " << a->getType() << std::endl;
	// delete a;
	// delete b;
	// b->getBrain()->readMyMind();
	// std::cout << b->getBrain()->getTotalIdeas() << std::endl;
	// //delete b;

	// Teste da copia profunda (fine)
	Cat b = *a;
	delete a;
	b.getBrain()->readMyMind();
	std::cout << b.getBrain()->getTotalIdeas() << std::endl;

	// std::string *s = new std::string;
	// std::string *d = s;
	// delete s;
	//delete d;
	return (0);
}
