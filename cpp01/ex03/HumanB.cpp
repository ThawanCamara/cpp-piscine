#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::attack(void)
{
	std::cout << getName() << " attacks with their " << getWeapon()->getType() << std::endl;
}

std::string	HumanB::getName()
{
	return (name);
}

Weapon* HumanB::getWeapon()
{
	return (weapon);
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
