#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
{
	_name = name;
	_weapon = &weapon;
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
	return (_name);
}

Weapon* HumanA::getWeapon()
{
	return (_weapon);
}

void HumanA::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
