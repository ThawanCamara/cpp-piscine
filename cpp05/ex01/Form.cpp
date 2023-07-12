#include "Form.hpp"

#define PINK		"\e[38;5;13m"
#define RESET 		"\e[0m"

Form::Form() :  name("unnamed"), isSigned(false), signGrade(75), executeGrade(33){}

Form::Form(std::string name, unsigned int signGrade, unsigned int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	checkGrade();
}

Form::Form(const Form& other) : name(other.getName()), isSigned(other.getSignStatus()), signGrade(other.getExecuteGrade()), executeGrade(other.getExecuteGrade()) {
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		Form tmp(other);
		*this = tmp;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Destroying form " << getName() << std::endl;
}

Form::GradeTooHighException::GradeTooHighException() : std::logic_error(std::string(PINK).append("Grade is too high").append(RESET)) {}

Form::GradeTooLowException::GradeTooLowException() : std::logic_error(std::string(PINK).append("Grade is too low").append(RESET)) {}

Form::SignedException::SignedException() : std::logic_error(std::string(PINK).append("The form is already signed").append(RESET)) {}


void Form::checkGrade() {
	if (signGrade > LOWESTGRADE || executeGrade > LOWESTGRADE)
		throw GradeTooLowException();
	if (signGrade < HIGHESTGRADE || executeGrade < HIGHESTGRADE)
		throw GradeTooHighException();
}

void Form::beSigned(Bureaucrat b) {
	if(b.getGrade() > signGrade)
		throw GradeTooLowException();
	if(isSigned == true)
		throw SignedException();
	isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &obj) {
	os << "Form: " << obj.getName() << "\nSign Grade:"<< obj.getSignGrade()<< "\nExecute Grade:"<<obj.getExecuteGrade()<<"\nStatus: "<< (obj.getSignStatus() ? "signed" : "unsigned")<<std::endl;
	return (os);
}

std::string Form::getName() const {
	return (name);
}

bool Form::getSignStatus() const {
	return (isSigned);
}

int Form::getSignGrade() const {
	return (signGrade);
}

int Form::getExecuteGrade() const {
	return (executeGrade);
}
