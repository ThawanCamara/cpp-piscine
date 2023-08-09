/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:53:51 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/07 17:54:04 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <iostream>
#include "EasyFind.hpp"
#include "colors.hpp"
#include "utils.hpp"
#include "cstdlib"

void putHeader(std::string msg)
{
	std::cout << std::endl << "===== " <<  std::string(GOLD) << msg << RESET << " =====" << std::endl;
}

void	testInt()
{
	std::vector<int> vectorInt;
		
	// This tells the compiler to reserve space for 7 values.
	// The push_back function can append without issues
	// Inserting at a random point may cause problems if not reserve()'d enough space first.
	// According to the design of vectors, they are not intended to be used like this
	// The following line is merely part of a demonstration
	// arrayInt.reserve(7);

	vectorInt.assign(6, 42);
	for (int i = 0; i < 5; i++)
		vectorInt.pop_back();
	for (int i = 0; i < 5; i++)
		vectorInt.push_back(i + 1);
	
	// This is how you store the return value of .begin()/.end()
	// std::vector<int>::iterator it = arrayInt.begin();
	
	// Insertion at a arbitrary position
	// arrayInt.insert(it + 1, 6);

	printContainer(vectorInt);

	putHeader("Provide input for fetching");
	std::string input;
	while (true)
	{
		std::cout << "\e[38;5;48m$>\e[0m ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input == "exit")
			break ;
		std::cout << std::flush;
		try
		{
			int it = *easyfind(vectorInt, std::atoi(input.c_str()));
			std::cout << "Fetched element { " << it << " }" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "ERROR: " << RESET << e.what() << '\n';
		}
	}
}

void	testFloat()
{
	std::vector<float> vectorFloat;

	vectorFloat.assign(6, 42.5f);
	for (int i = 0; i < 5; i++)
		vectorFloat.pop_back();
	for (int i = 0; i < 5; i++)
		vectorFloat.push_back(i + 1.23f);

	printContainer(vectorFloat);

	putHeader("Provide input for fetching");
	std::string input;
	while (true)
	{
		std::cout << "\e[38;5;48m$>\e[0m ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input == "exit")
			break ;
		std::cout << std::flush;
		try
		{
			float it = *easyfind(vectorFloat, static_cast<float>(std::atof(input.c_str())));
			std::cout << "Fetched element { " << it << " }" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "ERROR: " << RESET << e.what() << '\n';
		}
	}
}

void	testList()
{
	std::list<std::string> listString;

	listString.assign(6, "ola");
	for (int i = 0; i < 5; i++)
		listString.pop_back();
	listString.push_back("mundo");
	listString.push_back("doido");
	listString.push_back("abacaxi");
	listString.push_back("goiaba");

	printContainer(listString);

	putHeader("Provide input for fetching");
	std::string input;
	while (true)
	{
		std::cout << "\e[38;5;48m$>\e[0m ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input == "exit")
			break ;
		std::cout << std::flush;
		try
		{
			std::string it = *easyfind(listString, input.c_str());
			std::cout << "Fetched element { " << it << " }" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "ERROR: " << RESET << e.what() << '\n';
		}
	}
}

int main(int argc, char *argv[])
{
	putHeader("Available Data");
	if (argc && argv[1] && argv[1] == std::string("float"))
		testFloat();
	else if (argc && argv[1] && argv[1] == std::string("list"))
		testList();
	else
		testInt();
}
