/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:38:13 by tde-souz          #+#    #+#             */
/*   Updated: 2023/07/27 12:38:25 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreation", 145, 137), target("undefined") { }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm("ShrubberyCreation", 145, 137),target(other.getTarget()){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if(this != &other){
		target = other.getTarget();
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return target;
}

void ShrubberyCreationForm::toExecute() const
{
	std::ofstream file;
	std::string filename = target + "_shrubbery";
	file.open(filename.c_str());
	file  << "             *             " << std::endl;
	file  << "            ***            " << std::endl;
	file  << "           *****           " << std::endl;
	file  << "          *******          " << std::endl;
	file  << "         *********         " << std::endl;
	file  << "        ***********        " << std::endl;
	file  << "       *************       " << std::endl;
	file  << "             |             " << std::endl;
	file.close();
}