#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	int amount = 7;
	Zombie *horde = zombieHorde(amount, "Devon");

	for (int i = 0; i < amount; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
