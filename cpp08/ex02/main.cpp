/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:53:51 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/09 08:01:16 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "MutantStack.hpp"
#include "colors.hpp"
#include "utils.hpp"

void putHeader(std::string msg)
{
	std::cout << std::endl << "===== " <<  std::string(GOLD) << msg << RESET << " =====" << std::endl;
}

int main(void)
{
	putHeader("True Stack");
	std::stack<int> s;
	std::cout << "-- " << GOLD << "Pushing numbers: 5, 8 and 11" << RESET << " --" << std::endl;
	s.push(5);
	std::cout << "Pushing: " << "5" << std::endl;
	s.push(8);
	std::cout << "Pushing: " << "8" << std::endl;
	s.push(11);
	std::cout << "Pushing: " << "11" << std::endl;
	std::cout << "-- " << GOLD << "No iterators. Only access the topmost" << RESET << " --" << std::endl;
	std::cout << "Output from top(): " << s.top() << std::endl;
	std::cout << "-- " << GOLD << "But we can see that it has more elements" << RESET << " --" << std::endl;
	std::cout << "Output from size(): " << s.size() << std::endl;
	//printContainer(s); // This line does not compile since stacks cannot iterate
	putHeader("Mutant Stack");
	MutantStack<int> *m = new MutantStack<int>;
	std::cout << "-- " << GOLD << "Pushing numbers: 5, 8 and 11" << RESET << " --" << std::endl;
	m->push(5);
	std::cout << "Pushing: " << "5" << std::endl;
	m->push(8);
	std::cout << "Pushing: " << "8" << std::endl;
	m->push(11);
	std::cout << "Pushing: " << "11" << std::endl;
	std::cout << "-- " << GOLD << "We can access the topmost element" << RESET << " --" << std::endl;
	std::cout << "Output from top(): " << m->top() << std::endl;
	std::cout << "-- " << GOLD << "While also being able to iterate" << RESET << " --" << std::endl;
	printContainer(*m);
	putHeader("Mutant Stack Copy Constructor");
	MutantStack<int> *m2 = m;
	MutantStack<int> m3(*m2);
	printContainer(*m2);
	printContainer(m3);
	delete m;
	return (0);
}
