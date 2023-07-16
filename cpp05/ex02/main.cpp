#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

#define RESET 		"\e[0m"
#define BOLD 		"\e[1m"
#define GRAY 		"\e[38;5;8m"
#define RED 		"\e[38;5;9m"
#define GREEN		"\e[38;5;10m"
#define YELLOW		"\e[38;5;11m"
#define BLUE		"\e[38;5;12m"
#define PINK		"\e[38;5;13m"
#define TEAL		"\e[38;5;14m"
#define ORANGE		"\e[38;5;214m"
#define SILVER		"\e[38;5;7m"
#define GOLD		"\e[38;5;220m"
#define LGREEN		"\e[38;5;42m"
#define B_GRAY		"\e[1;38;5;8m"
#define B_RED		"\e[1;38;5;9m"
#define B_GREEN		"\e[1;38;5;10m"
#define B_YELLOW	"\e[1;38;5;11m"
#define B_BLUE		"\e[1;38;5;12m"
#define B_PINK		"\e[1;38;5;13m"
#define B_TEAL		"\e[1;38;5;14m"
#define B_ORANGE	"\e[1;38;5;214m"
#define B_SILVER	"\e[1;38;5;7m"
#define B_GOLD		"\e[1;38;5;220m"

void putHeader(std::string msg)
{
	std::cout << std::endl << "===== " <<  std::string(GOLD) << msg << RESET << " =====" << std::endl;
}

int main(void)
{
	std::string name;
	putHeader("Creating Forms");
	ShrubberyCreationForm a("Empathy Experiment Towards Plantile Beings");
	RobotomyRequestForm b("Robotomy For Dummies");
	PresidentialPardonForm c("Execute me pls");
    Bureaucrat	HighBureucrat("High Bureaucrat", 1);
	Bureaucrat	MediumBureucrat("Medium Bureaucrat", 43);
	Bureaucrat	LowBureucrat("Low Bureaucrat", 140);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	
	std::cout << "\n\n->Low Bureaucrat will never sign this :("<<std::endl;
	LowBureucrat.executeForm(c);
	HighBureucrat.signForm(c);
	LowBureucrat.executeForm(c);
	HighBureucrat.executeForm(c);

	std::cout << "\n\n->Medium Bureaucrat cant execute but High Bureaucrat can help"<<std::endl;
	MediumBureucrat.executeForm(b);
	HighBureucrat.signForm(b);
	MediumBureucrat.executeForm(b);

	std::cout << "\n\n->Execute After grade increment"<<std::endl;
	LowBureucrat.executeForm(a);
	HighBureucrat.signForm(a);
	LowBureucrat.increaseGrade();
	LowBureucrat.increaseGrade();
	LowBureucrat.increaseGrade();
	LowBureucrat.executeForm(a);
	return (0);
}