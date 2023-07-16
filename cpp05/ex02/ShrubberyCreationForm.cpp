#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

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