#include "Bureaucrat.hpp"

#define PINK		"\e[38;5;13m"
#define RESET 		"\e[0m"

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
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
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
		std::cerr << name << " could't sign " << form.getName() << ". Reason for this unfathomable act of despicable disrespect: " << e.what() << std::endl;
	}
	
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		std::cout << name << " executed " << form.getName() << std::endl;
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << name << " could't execute " << form.getName() << ". Reason for this unfathomable act of despicable disrespect: " << e.what() << std::endl;
	}
	
}
