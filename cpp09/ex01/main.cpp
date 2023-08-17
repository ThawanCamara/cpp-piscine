/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:53:51 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/17 08:56:43 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

#include "colors.hpp"

void putHeader(std::string msg)
{
	std::cout << std::endl << "===== " <<  std::string(GOLD) << msg << RESET << " =====" << std::endl;
}

int main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Error: " << "Invalid input." << std::endl;
		return (1);
	}
	putHeader("RPN Tests");
	try
	{
		std::cout << RPN::evaluateStack(argv[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
