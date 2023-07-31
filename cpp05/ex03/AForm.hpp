/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:36:47 by tde-souz          #+#    #+#             */
/*   Updated: 2023/07/30 17:03:04 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

# define HIGHESTGRADE 1
# define LOWESTGRADE 150
# define PINK		"\e[38;5;13m"
# define RED 		"\e[38;5;9m"
# define RESET 		"\e[0m"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name, unsigned int signGrade, unsigned int executeGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

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
		class NotSignedException : public std::logic_error
		{
			public:
				NotSignedException();
		};

		void checkGrade();
		void beSigned(Bureaucrat b);
		void execute(Bureaucrat const &b) const;

		std::string getName() const;
		bool getSignStatus() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

	protected:
		virtual void toExecute() const = 0;

	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;
};

std::ostream	&operator<<(std::ostream &os, const AForm &obj);

#endif
