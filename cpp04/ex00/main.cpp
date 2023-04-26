/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:18:30 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/23 09:12:08 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
	Animal a;
	Dog d;
	Dog b = d;
	std::cout << "-- STAGE 0 --"<< std::endl;
	Animal* y = new Dog("Pincher");
	std::cout << "-- STAGE 1 --"<< std::endl;
	Animal u = Dog();
	std::cout << "-- STAGE 2 --"<< std::endl;
	Dog g(b);
	std::cout << "-- STAGE 3 --"<< std::endl;

	std::cout << u.getType() << std::endl;
	std::cout << y->getType() << std::endl;
	std::cout << d.getType() << std::endl;
	std::cout << a.getType() << std::endl;
	std::cout << g.getType() << std::endl;

	a.makeSound();
	g.makeSound();
	d.makeSound();
	y->makeSound();	
	std::cout << "-- STAGE 4 --"<< std::endl;
	u.makeSound();
	Cat c;
	c.makeSound();
	u = c;
	u.makeSound();
	std::cout << c.getType() << std::endl;

	WrongAnimal wa;
	WrongCat wc;
	//WrongCat ac = wa; // <--- This is forbidden, superclass is incomplete to setup subclass
	WrongAnimal ca = wc; 

	wa.makeSound();
	wc.makeSound();
	wc.getType();
	ca.makeSound();
	ca.getType();

	delete y;
	return (0);
}
