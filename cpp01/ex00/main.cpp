#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie* zombie1 = newZombie("Steve");
	zombie1->announce();
	//newZombie("Kleo")->announce();

	randomChump("Josh");
	delete zombie1;
	return (0);
}
