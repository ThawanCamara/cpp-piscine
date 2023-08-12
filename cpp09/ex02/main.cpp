/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:53:51 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/12 14:20:40 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

#include "colors.hpp"


void putHeader(std::string msg)
{
	std::cout << std::endl << "===== " <<  std::string(GOLD) << msg << RESET << " =====" << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: " << "Invalid input." << std::endl;
		return (1);
	}
	try
	{
		putHeader("PmergeMe Tests");
		PmergeMe::evaluate(argv + 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
