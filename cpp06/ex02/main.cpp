/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:53:51 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/06 12:24:35 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <colors.hpp>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void putHeader(std::string msg)
{
	std::cout << std::endl << "===== " <<  std::string(GOLD) << msg << RESET << " =====" << std::endl;
}

Base *generate(void)
{
	std::string proof[] = {"A", "B", "C"};

	static int roll = 0;
	if (roll == 0 && ++roll)
		std::srand(static_cast<unsigned>(std::time(0)));
	int rand = std::rand();
	std::cout << "Generator Prediction: It should be " << YELLOW << proof[rand % 3] << RESET << std::endl;
	if (rand % 3 == 0)
		return (new A);
	else if (rand % 3 == 1)
		return (new B);
	else
		return (new C);
}

static void printType(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Object of type " << GREEN << "A" << RESET << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Object of type " << GREEN << "B" << RESET << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Object of type " << GREEN << "C" << RESET << std::endl;
	else
		std::cout << RED << "WARNING: " << RESET << "Unexpected conversion attempted." << std::endl;
}

void identify(Base *p)
{
	printType(p);
}

void identify(Base &p)
{
	printType(&p);
}

int main(void)
{
	std::string input;
	
	putHeader("Type Checker");
	std::cout << LIGHTSTEEL << "Press enter to generate a new object" << RESET << std::endl;
	std::cout << LIGHTSTEEL << "Non-empty input will bring an error" << RESET << std::endl;
	std::cout << LIGHTSTEEL << "Type 'exit' to quit" << RESET << std::endl;
	while (true)
	{
		std::cout << "\e[38;5;48m$>\e[0m ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input == "exit")
			break ;
		std::cout << std::flush;
		Base *r;
		if (input == "")
		{
			putHeader("Generating a random type...");
			r = generate();
		}
		else
		{
			putHeader("Invalid case, checking for Base type");
			std::cout << "Allocating a new " << YELLOW << "Base" << RESET << " object" << std::endl;
			r = new Base;
		}
		try
		{
			putHeader("Testing for pointer");
			identify(r);
			putHeader("Testing for reference");
			identify(*r);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete r;
	}
	
}