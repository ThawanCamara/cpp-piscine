/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:53:55 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/06 10:53:56 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <colors.hpp>
#include <ScalarConverter.hpp>

void putHeader(std::string msg)
{
	std::cout << std::endl << "===== " <<  std::string(GOLD) << msg << RESET << " =====" << std::endl;
}

int main(void)
{
	std::string input;

	putHeader("Provide input for conversion");
	while (true)
	{
		std::cout << "\e[38;5;48m$>\e[0m ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input == "exit")
			break ;
		std::cout << std::flush;
		try
		{
			ScalarConverter::convert(input);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "ERROR: " << RESET << e.what() << '\n';
		}
	}
	

	return (0);
}