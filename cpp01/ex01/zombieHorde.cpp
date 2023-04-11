#include <string>
#include <sstream>
#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::ostringstream ss; 
		ss << i + 1;
		std::string str = ss.str();
		horde[i].setName(name + " " + str);
	}
	return (horde);
}
