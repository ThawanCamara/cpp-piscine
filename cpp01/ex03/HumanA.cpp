#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

void	HumanA::attack(void)
{
	std::cout << getName() << " attacks with their " << getWeapon()->getType() << std::endl;
}
