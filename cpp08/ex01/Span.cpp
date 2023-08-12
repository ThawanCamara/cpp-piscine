/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:20:53 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/09 07:10:26 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : array(0), slots(0) {};

Span::Span(unsigned int n) : array(0), slots(n) {}

Span::~Span() {}

Span::Span(const Span& other) : array(other.array), slots(other.slots) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		array = other.array;
		slots = other.slots;
	}
	return (*this);
}

unsigned int Span::getSlots() const { return (slots); }

void Span::addNumber(const int n)
{
	if (slots > 0 && slots--)
		array.push_back(n);
	else
		throw std::length_error("Maximum limit has been reached");
}

int Span::shortestSpan()
{
	if (array.size() < 2)
		throw std::length_error("Too few numbers in Span");
	std::vector<int> t = array;
	std::sort(t.begin(), t.end());
	std::vector<int>::const_iterator min1 = t.begin();
	std::vector<int>::const_iterator min2 = t.begin() + 1;
	return (*min2 - *min1);
}

int Span::longestSpan() const
{
	if (array.size() < 2)
		throw std::length_error("Too few numbers in Span");
	// try block required. According to cpp reference allocation may fail
	try
	{
		std::vector<int>::const_iterator min = std::min_element(array.begin(), array.end());
		std::vector<int>::const_iterator max = std::max_element(array.begin(), array.end());
		return (*max - *min);
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

void Span::fillSpan()
{
	std::set<int> uniq;
	int remaining_slots = slots;
	static int roll = 1;
	
	if (roll == 1 && roll++)
		std::srand(static_cast<unsigned int>(std::time(0)));
	while (slots > 0)
	{
		int n = (std::rand() % remaining_slots + 1) * (std::rand() % 200);
		if (uniq.find(n) == uniq.end())
		{
			uniq.insert(uniq.begin(), n);
			addNumber(n);
		}
	}
}

// print container modified to work with const
void Span::print() const
{
	printContainer(array);
}
