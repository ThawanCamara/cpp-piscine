#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
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
	putHeader("Constructors");
	Intern	intern;
	Bureaucrat	senior("Senior", 34);

	putHeader("Intern creates a Shrubbery Creation Form");
	try
	{
		AForm *treeForm = intern.makeForm("Shrubbery Creation", "barkbuilder");
		if (treeForm != NULL)
		{
			senior.executeForm(*treeForm);
			senior.signForm(*treeForm);
			senior.executeForm(*treeForm);
		}
		delete treeForm;
	}
	catch(const std::exception& e)
	{
		std::cerr << ORANGE << "Reason: " << RESET << e.what() << std::endl;
	}

	putHeader("Intern creates a Bear Rebellion Form");
	try
	{
		AForm *bearForm = intern.makeForm("Bear Rebellion", "bearbrabo");
		if (bearForm != NULL)
		{
			senior.signForm(*bearForm);
			senior.executeForm(*bearForm);
		}
		//delete bearForm;
	}
	catch(const std::exception& e)
	{
		std::cerr << ORANGE << "Reason: " << RESET << e.what() << std::endl;
	}

	putHeader("Just some more bureaucratic work");
	try
	{
		AForm *roboto = intern.makeForm("robotomy request", "bender");
		if (roboto != NULL)
		{
			senior.executeForm(*roboto);
			senior.signForm(*roboto);
			senior.executeForm(*roboto);
		}
		delete roboto;
	}
	catch(const std::exception& e)
	{
		std::cerr << ORANGE << "Reason: " << RESET << e.what() << std::endl;
	}
	return (0);
}