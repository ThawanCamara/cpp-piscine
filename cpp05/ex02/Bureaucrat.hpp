#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

# define HIGHESTGRADE 1
# define LOWESTGRADE 150

class AForm;

class Bureaucrat
{
	private:
		const std::string		name;
		unsigned int			grade;

	public:
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		const std::string		getName() const;
		int						getGrade() const;
		void					setGrade(unsigned int grade);
		void					increaseGrade();
		void					decreaseGrade();
		void					signForm(AForm& form);
		void					executeForm(AForm const &form);

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
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
