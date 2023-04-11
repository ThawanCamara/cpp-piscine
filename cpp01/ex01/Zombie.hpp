#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
 
#include <string>

class Zombie
{
	public:
		Zombie(){};
		Zombie(const Zombie&);
		Zombie& operator=(const Zombie&);
		~Zombie();

		void	announce(void);

		std::string getName() { return (name); };
		void		setName(std::string name) { this->name = name; };

	private:
		std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif
