/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:53:51 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/08 21:16:13 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Span.hpp>
#include "colors.hpp"

void putHeader(std::string msg)
{
	std::cout << std::endl << "===== " <<  std::string(GOLD) << msg << RESET << " =====" << std::endl;
}

int main(void)
{
	putHeader("Testing Operations on Empty Span(5)");
	Span *a = new Span(5);
	std::cout << "Span " << GREEN << "A" << RESET << " (up to 5 slots)" << std::endl;
	a->print();
	std::cout << "-- " << GOLD << "Fetch Longest span" << RESET << " --" << std::endl;
	try
	{
		a->longestSpan();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "ERROR: " << RESET << e.what() << '\n';
	}
	std::cout << "-- " << GOLD << "Adding numbers" << RESET << " --" << std::endl;
	a->addNumber(88);
	std::cout << "Span " << GREEN << "A" << RESET << " (up to 5 slots)" << std::endl;
	a->print();
	std::cout << "-- " << GOLD << "Fetch Shortest span" << RESET << " --" << std::endl;
	try
	{
		a->shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "ERROR: " << RESET << e.what() << '\n';
	}
	std::cout << "-- " << GOLD << "Filling remaining slots" << RESET << " --" << std::endl;
	a->fillSpan();
	std::cout << "Span " << GREEN << "A" << RESET << " (up to 5 slots)" << std::endl;
	a->print();
	std::cout << "-- " << GOLD << "Adding just one more..." << RESET << " --" << std::endl;
	try
	{
		a->addNumber(-1);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "ERROR: " << RESET << e.what() << '\n';
	}
	std::cout << "-- " << GOLD << "Fetch Spans" << RESET << " --" << std::endl;
	std::cout << "Longest span " << GREEN << "A" << RESET << ": " << a->longestSpan() << std::endl;
	std::cout << "Shortest span " << GREEN << "A" << RESET << ": " << a->shortestSpan() << std::endl;
	
	
	putHeader("Testing on Epic Span(1 mi)");
	Span b = Span(1000000);
	std::cout << "-- " << GOLD << "Filling slots" << RESET << " --" << std::endl;
	b.fillSpan();
	std::cout << "Span " << BLUE << "B" << RESET << " (up to a million slots)" << std::endl;
	std::cout << RED << "WARNING: " << RESET "Do you wish to print " << BLUE << "B" << RESET << "? (yes/no)" << std::endl;
	std::string input;
	std::cout << "\e[38;5;48m$>\e[0m ";
	std::getline(std::cin, input);
	if (std::cin.eof() || input == "yes")
		b.print();
	std::cout << std::flush;
	std::cout << RED << "WARNING: " << RESET "Do you test operations on " << BLUE << "B" << RESET << "? (yes/no)" << std::endl;
	std::cout << "\e[38;5;48m$>\e[0m ";
	std::getline(std::cin, input);
	if (std::cin.eof() || input == "yes")
	{
		std::cout << "-- " << GOLD << "Fetch Spans" << RESET << " --" << std::endl;
		std::cout << "Longest span " << BLUE << "B" << RESET << ": " << b.longestSpan() << std::endl;
		std::cout << "Shortest span " << BLUE << "B" << RESET << ": " << b.shortestSpan() << std::endl;
	}
	std::cout << std::flush;
	delete a;
	return (0);
}
