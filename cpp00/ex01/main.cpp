#include <iostream>
#include <iomanip>
#include "Phonebook.hpp"

void debugFillList(Phonebook &phonebook);

enum Options
{
	OptionAdd,
	OptionSearch,
	OptionExit,
	OptionInvalid
};

Options selectOption(const std::string &input)
{
	if (input == "ADD" || input == "add") return (OptionAdd);
	else if (input == "SEARCH" || input == "search") return (OptionSearch);
	else if (input == "EXIT" || input == "exit") return (OptionExit);
	else return (OptionInvalid);
}

int	main(int argc, char *argv[])
{
	Options option = OptionInvalid;
	Phonebook phonebook;
	std::string input;

	(void)argc;
	if (argv[1] && argv[1] == std::string("debug"))
		debugFillList(phonebook);
	while (option != OptionExit)
	{
		std::cout << "\e[38;5;48m$>\e[0m ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		std::cout << std::flush;
		option = selectOption(input);
		switch (option)
		{
			case (OptionAdd):
				phonebook.addList();
				break ;
			case (OptionSearch):
				phonebook.searchList();
				break ;
			default:
				break ;
		}
	}
	return (0);
}

std::string tableFill[8][255] = 
{
	{"Louis", "Lane", "Batman", "99512-7760", "She is not batman"},
	{"Thales", "DeMileto", "Tata", "98213-1775", "He is not from Mileto"},
	{"Louis", "Lane", "Bat-maninha", "99512-7760", "She is not batman"},
	{"Louis", "Lane", "Batman", "99512-7760", "She is not batman"},
	{"Louisaaaaaaaaa", "Lane", "Batman", "99512-7760", "She is not batman"},
	{"Louis", "Lane", "Batman", "99512-7760", "She is not batman"},
	{"Louis", "Lane", "Batman", "99512-7760", "She is not batman"},
	{"Louis", "Lane", "Batman", "99512-7760", "She is not batman"}
};

void debugFillList(Phonebook &phonebook)
{
	
	for (int i = 0; i < 8; i++)
	{	
		phonebook.getList()[i].setFirstname(tableFill[i][0]);
		phonebook.getList()[i].setLastname(tableFill[i][1]);
		phonebook.getList()[i].setNickname(tableFill[i][2]);
		phonebook.getList()[i].setPhoneNumber(tableFill[i][3]);
		phonebook.getList()[i].setDarkestSecret(tableFill[i][4]);
		phonebook.increaseAmountOfContacts();
	}
}
