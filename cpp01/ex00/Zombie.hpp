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

		//void	announce(void) { std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; };
		void	announce(void);
		//Zombie*	newZombie(std::string name);
		//void	randomChump(std::string name);

		std::string getName() { return (name); };
		void		setName(std::string name) { this->name = name; };

	private:
		std::string name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
