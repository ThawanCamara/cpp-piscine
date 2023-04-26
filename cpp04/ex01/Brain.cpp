/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 09:34:23 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/24 16:48:56 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
	totalIdeas = 0;
}

Brain::Brain(const Brain& other)
{
	*this = other;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < other.getTotalIdeas(); i++)
		{
    		ideas[i] = other.ideas[i];
		}
		totalIdeas = other.getTotalIdeas(); 
	}
	return (*this);
}

Brain::~Brain()
{
}

void Brain::makeMyMind(const std::string idea)
{
	if (totalIdeas < 100)
	{
		ideas[totalIdeas] = idea;
		++totalIdeas;
	}
	else
		std::cout << "Not enough brain cells" << std::endl;
}

void Brain::readMyMind() const
{
	for (int i = 0; i < totalIdeas; i++)
	{
		std::cout << "Idea " << i + 1 << ") " << ideas[i] << std::endl;
	}
}

const std::string* Brain::getIdeas() const
{
	return (ideas);
}

int	Brain::getTotalIdeas() const
{
	return (totalIdeas);
}
