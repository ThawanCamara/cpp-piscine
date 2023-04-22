#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie zombie0;
	zombie0.setName("Boi Magia");
	Zombie* zombie1 = newZombie("Steve");
	zombie0.announce();
	zombie1->announce();
	//newZombie("Kleo")->announce();

	randomChump("Josh");
	delete zombie1;
	return (0);
}
