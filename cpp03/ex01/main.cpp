#include "ScavTrap.hpp"
#include <iostream>

void printClapInfo(ClapTrap& trap);

int main(void)
{
	ClapTrap	trap1("Dizz");
	ScavTrap	trap2("Fuzz");
	ScavTrap	trap3 = trap2;

	trap3.setName("Wuzz");
	trap1.attack(trap2.getName());
	trap2.takeDamage(trap1.getDamage());
	//std::cout << "\033[38;5;97m" << trap1.getName() << "\033[0m" << ": I need to repair 10 times!" << std::endl;
	//for (int i = 0; i < 10 ; i++)
	//	trap1.beRepaired(1);
	printClapInfo(trap1);
	trap2.attack(trap1.getName());
	trap1.takeDamage(trap2.getDamage());
	trap3.guardGate();
	printClapInfo(trap1);
	printClapInfo(trap2);
	printClapInfo(trap3);
	trap1.attack(trap2.getName());
	return (0);
}

void printClapInfo(ClapTrap& trap)
{
	std::cout << "\033[38;5;220m______________________________\033[0m"<< std::endl;
	std::cout << "\033[38;5;228m" << trap.getName() << " Status:\033[0m" << std::endl; 
	std::cout << "\033[38;5;220mHealth:\033[0m" << trap.getHealth() << std::endl;
	std::cout << "\033[38;5;220mEnergy:\033[0m" << trap.getEnergy() << std::endl;
	std::cout << "\033[38;5;220mDamage:\033[0m" << trap.getDamage() << std::endl;
	std::cout << "\033[38;5;220m______________________________\033[0m"<< std::endl;

}
