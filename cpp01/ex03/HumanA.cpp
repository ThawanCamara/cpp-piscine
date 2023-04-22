#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void)
{
	std::cout << getName() << " attacks with their " << getWeapon()->getType() << std::endl;
}

std::string	HumanA::getName()
{
	return (name);
}

Weapon* HumanA::getWeapon()
{
	return (weapon);
}

void HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
