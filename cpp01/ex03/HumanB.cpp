#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void	HumanB::attack(void)
{
	std::cout << getName() << " attacks with their " << getWeapon()->getType() << std::endl;
}
