#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		HumanA(const HumanA&);
		HumanA& operator=(const HumanA&);
		~HumanA(){};

		void		attack(void);
		std::string	getName() { return (name); };
		Weapon		*getWeapon() { return (weapon); };
		void		setWeapon(Weapon &weapon) { this->weapon = &weapon; };

	private:
		std::string	name;
		Weapon		*weapon;
};

#endif
