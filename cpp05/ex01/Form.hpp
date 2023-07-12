#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

# define HIGHESTGRADE 1
# define LOWESTGRADE 150

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, unsigned int signGrade, unsigned int executeGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		class GradeTooHighException : public std::logic_error
		{
			public:
				GradeTooHighException();
		};
		class GradeTooLowException : public std::logic_error
		{
			public:
				GradeTooLowException();
		};
		class SignedException : public std::logic_error
		{
			public:
				SignedException();
		};
		void checkGrade();
		void beSigned(Bureaucrat b);

		std::string getName() const;
		bool getSignStatus() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;
};

std::ostream	&operator<<(std::ostream &os, const Form &obj);

#endif
