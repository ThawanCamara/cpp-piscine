#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), target("unknown") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("Presidential Pardon", 25, 5), target(other.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		target = other.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const
{
	return (target);
}

void PresidentialPardonForm::toExecute() const 
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}