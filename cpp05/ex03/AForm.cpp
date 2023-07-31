/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:36:41 by tde-souz          #+#    #+#             */
/*   Updated: 2023/07/30 17:02:55 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :  name("unnamed"), isSigned(false), signGrade(75), executeGrade(33){}

AForm::AForm(std::string name, unsigned int signGrade, unsigned int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	checkGrade();
}

AForm::AForm(const AForm& other) : name(other.getName()), isSigned(other.getSignStatus()), signGrade(other.getExecuteGrade()), executeGrade(other.getExecuteGrade()) {
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		isSigned = other.getSignStatus();
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << RED << "Destroying" << RESET << " form " << getName() << std::endl;
}

AForm::GradeTooHighException::GradeTooHighException() : std::logic_error(std::string(PINK).append("Grade is too high").append(RESET)) {}

AForm::GradeTooLowException::GradeTooLowException() : std::logic_error(std::string(PINK).append("Grade is too low").append(RESET)) {}

AForm::SignedException::SignedException() : std::logic_error(std::string(PINK).append("The form is already signed").append(RESET)) {}

AForm::NotSignedException::NotSignedException() : std::logic_error(std::string(PINK).append("The form is not signed").append(RESET)) {}

void AForm::checkGrade() {
	if (signGrade > LOWESTGRADE || executeGrade > LOWESTGRADE)
		throw GradeTooLowException();
	if (signGrade < HIGHESTGRADE || executeGrade < HIGHESTGRADE)
		throw GradeTooHighException();
}

void AForm::beSigned(Bureaucrat b) {
	if(b.getGrade() > signGrade)
		throw GradeTooLowException();
	if(isSigned == true)
		throw SignedException();
	isSigned = true;
}

void AForm::execute(Bureaucrat const &b) const {
	if (isSigned == false)
		throw AForm::NotSignedException();
	else if (b.getGrade() > executeGrade)
		throw AForm::GradeTooLowException();
	toExecute();
}

std::ostream &operator<<(std::ostream &os, const AForm &obj) {
	os << "Form: " << obj.getName() << "\nSign Grade:"<< obj.getSignGrade()<< "\nExecute Grade:"<<obj.getExecuteGrade()<<"\nStatus: "<< (obj.getSignStatus() ? "signed" : "unsigned")<<std::endl;
	return (os);
}

std::string AForm::getName() const {
	return (name);
}

bool AForm::getSignStatus() const {
	return (isSigned);
}

int AForm::getSignGrade() const {
	return (signGrade);
}

int AForm::getExecuteGrade() const {
	return (executeGrade);
}
