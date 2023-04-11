#ifndef HUMBNB_HPP
# define HUMBNB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		HumanB(const HumanB&);
		HumanB& operator=(const HumanB&);
		~HumanB(){};

		void		attack(void);
		std::string	getName() { return (name); };
		Weapon		*getWeapon() { return (weapon); };
		void		setWeapon(Weapon &weapon) { this->weapon = &weapon; };

	private:
		std::string	name;
		Weapon		*weapon;
};

#endif
