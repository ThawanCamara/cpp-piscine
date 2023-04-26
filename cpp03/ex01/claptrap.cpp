#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	health = 10;
	energy = 10;
	damage = 0;

	std::cout << "\033[38;5;228mConstructor: NEW CLAPTRAP SPAWNED AAAAAAAAAAAAAAAAAHHH\033[0m" << std::endl;
	std::cout << "\033[38;5;220mName:\033[0m" << name << std::endl;
	std::cout << "\033[38;5;220mHealth:\033[0m" << health << std::endl;
	std::cout << "\033[38;5;220mEnergy:\033[0m" << energy << std::endl;
	std::cout << "\033[38;5;220mDamage:\033[0m" << damage << std::endl;
	std::cout << "\033[38;5;228m|______End of Constructor______|\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap: Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.getName();
		this->health = other.getHealth();
		this->energy = other.getEnergy();
		this->damage = other.getDamage();
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[38;5;250mDestructor: CLAPTRAP " << this->name << " was utterly destroyed in the most horrific way imaginable...\033[0m" << std::endl;
	std::cout << "\033[38;5;250m|______End of Destructor______|\033[0m" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "\033[38;5;110mClapTrap: Attempt: Attack: \033[0m" << this->name << " is trying to attack" << std::endl;
	if (!this->tryPerformAction("Attack"))
		return ;
	std::cout << "\033[38;5;11mClapTrap: Event: Attack: \033[0m" << this->name << " attacks " << target << ", causing " << this->getDamage() << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "\033[38;5;9mClapTrap: Event: DamageTaken: \033[0m" << this->name << " has taken " << amount << " points of damage!" << std::endl;
	if (this->getHealth() < amount)
		this->setHealth(0);
	else
		this->setHealth(this->getHealth() - amount);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "\033[38;5;110mClapTrap: Attempt: Repair: \033[0m" << this->name << " is trying to repair" << std::endl;
	if (!this->tryPerformAction("Repair"))
		return ;
	std::cout << "\033[38;5;10mClapTrap: Event: Repair: \033[0m" << this->name << " recovered " << amount << " hit points through repair!" << std::endl;
	this->setHealth(this->getHealth() + amount);
}

int ClapTrap::tryPerformAction(std::string action)
{	
	int	energy = this->getEnergy();
	int	health = this->getHealth();

	if (health <= 0)
	{
		std::cout << "\033[38;5;172mClapTrap: Alert: Health:\033[0m " << this->getName() << " dead traps can't clap! " << action << " cannot be performed due to the excess of deathness!" << std::endl;
		return (0);
	}
	if (energy <= 0)
	{
		std::cout << "\033[38;5;172mClapTrap: Alert: Energy:\033[0m " << this->getName() << " on low energy! " << action << " cannot be performed due to a total lack of motivation!" << std::endl;
		return (0);
	}
	this->setEnergy(energy - this->getActionEnergyCost());
	return (1);
}

