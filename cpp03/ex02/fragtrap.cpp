#include "fragtrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->health = 100;
	this->energy = 100;
	this->damage = 30;
	
	std::cout << "\033[38;5;228mConstructor: NEW FRAGTRAP SPAWNED AAAAAAAAAAAAAAAAAHHH\033[0m" << std::endl;
	std::cout << "\033[38;5;220mName:\033[0m" << name << std::endl;
	std::cout << "\033[38;5;28mH:" << health << " \033[38;5;57mE:" << energy << " \033[38;5;88mD:" << damage << "\033[0m" << std::endl;
	std::cout << "\033[38;5;228m|______End of Constructor______|\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap: Copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHealth(other.getHealth());
		this->setEnergy(other.getEnergy());
		this->setDamage(other.getDamage());
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "\033[38;5;250mDestructor: FRAGTRAP " << this->name << " was utterly destroyed in the most horrific way imaginable...\033[0m" << std::endl;
	std::cout << "\033[38;5;250m|______End of Destructor______|\033[0m" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	std::cout << "\033[38;5;110mFragTrap: Attempt: Attack: \033[0m" << this->name << " is trying to attack" << std::endl;
	if (!this->tryPerformAction("Attack"))
		return ;
	std::cout << "\033[38;5;11mFragTrap: Event: Attack: \033[0m" << this->name << " attacks " << target << ", causing " << this->getDamage() << " points of damage!" << std::endl;
}

void FragTrap::highFiveGuys(void)
{
	std::cout << "\033[38;5;114mFragTrap: Event: GuardGate: \033[0m" << this->name << " is now guarding the gate. OMG!" << std::endl;
}
