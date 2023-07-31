/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:36:32 by tde-souz          #+#    #+#             */
/*   Updated: 2023/07/30 17:14:27 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), target("unnamed"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm("Robotomy Request", 72, 45), target(other.getTarget()){}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other){
	if(this != &other){
		target = other.getTarget();
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const
{
	return target;
}
	
void RobotomyRequestForm::toExecute() const {
	static int roll = 0;
	if (roll == 0 && ++roll)
		std::srand(static_cast<unsigned>(std::time(0)));
	std::cout << "\n******* Drilling noises ******" << std::endl;
	if (std::rand() % 2)
		std::cout << "Robotomy has found " << GREEN << "success" << RESET << " in " << target << std::endl;
	else
		std::cout << "Robotomy" << RED << " wasted " << RESET << "in " << target << std::endl;
}