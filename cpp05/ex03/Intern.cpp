#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	const std::string availableForms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*formFactories[]) (const std::string) = {
		&Intern::makeShrubberyCreation,
		&Intern::makeRobotomyRequest,
		&Intern::makePresidentialPardon
	};

	int len = formName.length();
	for (int i = 0; i < len; i++) formName[i] = std::tolower(formName[i]);
	for (int i = 0; i < 3; i++)
	{
		if (formName == availableForms[i])
		{
			std::cout << "Intern creates " << ORANGE << formName << RESET << std::endl;
			return ((this->*formFactories[i])(formTarget));
		}
	}
	std::cerr << "Intern could not create " << formName << std::endl;
	throw InvalidFormException();
}

Intern::InvalidFormException::InvalidFormException() : std::logic_error(std::string(PINK).append("Unknown form type").append(RESET)) {}

/* 
 * Factory Functions
 */

AForm *Intern::makeShrubberyCreation(const std::string formTarget)
{
	return (new ShrubberyCreationForm(formTarget));
}

AForm *Intern::makePresidentialPardon(const std::string formTarget)
{
	return (new PresidentialPardonForm(formTarget));
}

AForm *Intern::makeRobotomyRequest(const std::string formTarget)
{
	return (new RobotomyRequestForm(formTarget));
}
