/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:53:51 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/11 18:05:13 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <map>

#include "BitcoinExchange.hpp"
#include "Date.hpp"

#include "colors.hpp"
#include "utils.hpp"

void putHeader(std::string msg)
{
	std::cout << std::endl << "===== " <<  std::string(GOLD) << msg << RESET << " =====" << std::endl;
}

int main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Error: " << "could not open file." << std::endl;
		return (1);
	}
	putHeader("Exchange Tests");
	try
	{
		BitcoinExchange exchange("data.csv");
		// BitcoinExchange exchange2(exchange);
		// exchange2.printDatabase();
		exchange.makeExchange(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
