#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string type);
		Weapon(const Weapon&);
		Weapon& operator=(const Weapon&);
		~Weapon();

		std::string	getType();
		void		setType(std::string type); 

	private:
		std::string _type;
};

#endif
