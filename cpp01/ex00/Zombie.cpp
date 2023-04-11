#include <iostream>
#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << "Debug:\tZombie:\t" << name;
	std::cout << " was \e[38;5;9mdestroyed\e[0m" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
