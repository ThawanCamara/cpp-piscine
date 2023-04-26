#include "Harl.hpp"
#include <iostream>

int main(void)
{
	std::string input;
	Harl harl;

	while (1)
	{
		std::cout << "Enter Complain Level:" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof() || input == "EXIT")
			break ;
		harl.complain(input);
	}

	return (0);
}
