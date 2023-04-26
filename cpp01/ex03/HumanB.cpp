#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
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
	return (_name);
}

Weapon* HumanB::getWeapon()
{
	return (_weapon);
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
