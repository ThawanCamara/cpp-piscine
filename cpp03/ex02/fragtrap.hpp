#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "claptrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap();

		void attack(const std::string& target);
		void highFiveGuys(void);
};

#endif
