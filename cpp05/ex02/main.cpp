#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>
#include <unistd.h>

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
	putHeader("Constructors");
	ShrubberyCreationForm formTree("Empathy Experiment Towards Plantile Beings");
	RobotomyRequestForm formRobot("Robotomy For Dummies");
	PresidentialPardonForm formPardon("Execute me pls");
    Bureaucrat	ceo("Ceo", 1);
	Bureaucrat	senior("Senior", 34);
	Bureaucrat	junior("Junior", 139);
	std::cout << ceo << std::endl;
	std::cout << senior << std::endl;
	std::cout << junior << std::endl;
	
	putHeader("Execute: Exception Tests");
	junior.executeForm(formPardon);
	senior.signForm(formPardon);
	ceo.signForm(formPardon);
	junior.executeForm(formPardon);
	senior.executeForm(formPardon);
	ceo.executeForm(formPardon);

	putHeader("Execute: Robotomy Tests");
	ceo.signForm(formRobot);
	junior.executeForm(formRobot);
	senior.executeForm(formRobot);
	ceo.executeForm(formRobot);
	ceo.executeForm(formRobot);
	ceo.executeForm(formRobot);

	putHeader("Execute: After Grade Increase");
	junior.executeForm(formTree);
	ceo.signForm(formTree);
	junior.executeForm(formTree);
	std::cout << BLUE << "Increasing Junior's grade by 2" << RESET << std::endl;
	junior.increaseGrade();
	junior.increaseGrade();
	junior.executeForm(formTree);
	putHeader("Destructors");
	return (0);
}