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
		~Weapon(){};

		std::string	getType() { return (type); };
		void		setType(std::string type) { this->type = type; };

	private:
		std::string type;
};

#endif
