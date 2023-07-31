#ifndef INTERN_HPP
# define INTERN_HPP

# include <AForm.hpp>
# include <PresidentialPardonForm.hpp>
# include <RobotomyRequestForm.hpp>
# include <ShrubberyCreationForm.hpp>
# include <iostream>

# define RESET 		"\e[0m"
# define ORANGE		"\e[38;5;214m"


class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		AForm *makeForm(std::string formName, std::string formTarget);
		class InvalidFormException : public std::logic_error
		{
			public:
				InvalidFormException();
		};

	private:
		AForm *makeShrubberyCreation(const std::string formTarget);
		AForm *makePresidentialPardon(const std::string formTarget);
		AForm *makeRobotomyRequest(const std::string formTarget);

};

#endif
