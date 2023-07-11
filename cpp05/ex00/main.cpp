#include "Bureaucrat.hpp"
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

	putHeader("Creating Bureaucrats");
	name = std::string(RED).append("Simpson").append(RESET);
	Bureaucrat a = Bureaucrat(name, 33);

	name = std::string(GREEN).append("Steeve").append(RESET);
	Bureaucrat *b = new Bureaucrat(name, 75);
	Bureaucrat c(a);
	Bureaucrat *d = b;
	a.setGrade(5);
	d->setGrade(146);

	std::cout << a;
	std::cout << *b;
	std::cout << c;
	std::cout << *d;

	putHeader("Testing Highest Grade");
	try {
		std::cout << "Increasing " << a.getName() << "'s Grade 4 times" << std::endl;
		for (int i = 0; i < 4; i++)
			a.increaseGrade();
		std::cout << a;
		std::cout << "Increasing " << d->getName() << "'s Grade one more time" << std::endl;
		a.increaseGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Weird stuff is going on..." << std::endl;
	}

	putHeader("Testing Lowest Grade");
	try {
		std::cout << "Decreasing " << d->getName() << "'s Grade 4 times" << std::endl;
		for (int i = 0; i < 4; i++)
			d->decreaseGrade();
		std::cout << *d;
		std::cout << "Decreasing " << d->getName() << "'s Grade one more time" << std::endl;
		d->decreaseGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Weird stuff is going on..." << std::endl;
	}

	putHeader("Creating wrong Bureaucrats");
	try {
		Bureaucrat e = Bureaucrat("failure", 151);
		// Bureaucrat f = Bureaucrat("failure", -1);
		// Bureaucrat *h = new Bureaucrat("failure", -1);
		// (void)h;
	}
	catch (std::exception &e)
	{
		std::cout << std::string(TEAL).append("Not a proper bureaucrat.").append(RESET) << std::endl;
	}
	delete b;
	return (0);
}