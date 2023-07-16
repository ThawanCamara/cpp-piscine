#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

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
	std::srand(std::time(0));
	std::cout << "\n******* Drilling noises, probably lack of demotivation ******" << std::endl;
	if (std::rand() % 2)
		std::cout << "Robotomy has found success in " << target << std::endl;
	else
		std::cout << "Robotomy wasted in " << target << std::endl;
}