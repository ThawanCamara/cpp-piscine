/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:37:07 by tde-souz          #+#    #+#             */
/*   Updated: 2023/07/27 12:37:30 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

# define HIGHESTGRADE 1
# define LOWESTGRADE 150

# define PINK		"\e[38;5;13m"
# define ORANGE		"\e[38;5;214m"
# define RESET 		"\e[0m"

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
