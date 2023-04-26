#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << "Debug:\tZombie:\t" << _name;
	std::cout << " was \e[38;5;9mdestroyed\e[0m" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName()
{
	return (_name);
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
