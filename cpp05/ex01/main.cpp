#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>

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
	name = std::string(GREEN).append("Neat Form").append(RESET);
	Form f1(name, 15, 50);
	try
	{
		name = std::string(RED).append("Wrong Form").append(RESET);
		// Form f2(name, 15, -1);
		// std::cout << f2 << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	name = std::string(TEAL).append("Bob").append(RESET);
	Bureaucrat	b1(name, 22);
	name = std::string(BLUE).append("Marley").append(RESET);
	Bureaucrat	b2(name, 1);
	std::cout << b1;
	std::cout << b2;
	std::cout << f1 << std::endl;

	b1.signForm(f1);
	b2.signForm(f1);
	b2.signForm(f1);

	return (0);
}