/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:53:51 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/06 18:10:19 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colors.hpp"
#include "joker.hpp"

void putHeader(std::string msg)
{
	std::cout << std::endl << "===== " <<  std::string(GOLD) << msg << RESET << " =====" << std::endl;
}

typedef struct s_Data
{
	std::string name;
	int	age;
	float money;
}	Data;

int main(void)
{
	std::string input;
	
	putHeader("Available Data");
	int a = 42;
	int b = 300;
	std::string s1 = "abacate";
	std::string s2 = "mordor";
	Data c;
	Data d;
	c.name = "ola";
	d.name = "aios";
	swap(c, d);
	std::cout << "c = " << c.name << std::endl; 
	std::cout << "d = " << d.name << std::endl; 

	std::cout << "a = " << a << std::endl; 
	std::cout << "b = " << b << std::endl;
	std::cout << "s1 = " << s1 << std::endl; 
	std::cout << "s2 = " << s2 << std::endl;
	putHeader("Funtion: Swap");
	::swap(a, b);
	::swap(s1, s2);
	std::cout << "a = " << a << std::endl; 
	std::cout << "b = " << b << std::endl;
	std::cout << "s1 = " << s1 << std::endl; 
	std::cout << "s2 = " << s2 << std::endl;
	std::cout << B_RED << "Reverting to original data" << RESET << std::endl;
	::swap(a, b);
	::swap(s1, s2);
	putHeader("Funtion: Min");
	std::cout << "Min value between " << a << " and " << b << " is " << ::min(a, b) << std::endl; 
	std::cout << "Min value between " << s1 << " and " << s2 << " is " << ::min(s1, s2) << std::endl; 
	putHeader("Funtion: Max");
	std::cout << "Max value between " << a << " and " << b << " is " << ::max(a, b) << std::endl; 
	std::cout << "Max value between " << s1 << " and " << s2 << " is " << ::max(s1, s2) << std::endl; 
}
