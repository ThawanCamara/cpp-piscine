/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:37:04 by tde-souz          #+#    #+#             */
/*   Updated: 2023/07/27 12:37:24 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.getName()), grade(other.getGrade()) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat(){
}

const std::string Bureaucrat::getName() const{
	return name;
}

int Bureaucrat::getGrade() const 
{
	return grade;
}

void Bureaucrat::setGrade(unsigned int grade)
{
	if (grade < HIGHESTGRADE)
		throw GradeTooHighException();
	else if (grade > LOWESTGRADE)
		throw GradeTooLowException();
	this->grade = grade;
}

void Bureaucrat::increaseGrade()
{
	if (grade - 1 < HIGHESTGRADE)
		throw GradeTooHighException();
	setGrade(grade - 1);
}

void Bureaucrat::decreaseGrade()
{
	if (grade + 1 > LOWESTGRADE)
		throw GradeTooLowException();
	setGrade(grade + 1);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::logic_error(std::string(PINK).append("Grade is too high, maximum is 1").append(RESET)) {}

Bureaucrat::GradeTooLowException::GradeTooLowException() : std::logic_error(std::string(PINK).append("Grade is too low, minimum is 150").append(RESET)) {}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout<<name<<" signed "<<form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << name << " could't sign " << form.getName() << "." << ORANGE << "\nReason:" << RESET << "\t" << e.what() << std::endl;
	}
	
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << name << " could't execute " << form.getName() << "." << ORANGE << "\nReason:" << RESET << "\t" << e.what() << std::endl;
	}
	
}
