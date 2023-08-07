#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		virtual ~ClapTrap();

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName(void) const { return name; } ;
		unsigned int	getHealth(void) const { return health; };
		unsigned int	getEnergy(void) const { return energy; };
		unsigned int	getDamage(void) const { return damage; };
		unsigned int	getActionEnergyCost(void) const { return actionEnergyCost; };
		
		void		setName(std::string name) { this->name = name; };
		void		setHealth(const int value) { health = value; };
		void		setEnergy(const int value) { energy = value; };
		void		setDamage(const int value) { damage = value; };

		int			tryPerformAction(std::string);

	protected:
		std::string	name;
		unsigned int	health;
		unsigned int	energy;
		unsigned int	damage;
		static const int actionEnergyCost = 1;
};

#endif
