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
		~HumanA();

		void		attack(void);
		std::string	getName();
		Weapon		*getWeapon();
		void		setWeapon(Weapon &weapon);

	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif
