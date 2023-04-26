#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
	std::cout << "\033[38;5;118mConstructor : Harl\033[0m" << std::endl;
}

Harl::~Harl()
{
	std::cout << "\033[38;5;9mDestructor  : Harl\033[0m" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string tableLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*options[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == tableLevels[i])
			(this->*options[i])();
	}
}

void Harl::debug(void)
{
	std::cout << "\033[38;5;169mI love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!\033[0m" << std::endl;
}

void Harl::info(void)
{
	std::cout << "\033[38;5;149mI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\033[0m" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "\033[38;5;159mI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\033[0m" << std::endl;
}

void Harl::error(void)
{
	std::cout << "\033[38;5;209mThis is unacceptable! I want to speak to the manager now.\033[0m" << std::endl;
}

