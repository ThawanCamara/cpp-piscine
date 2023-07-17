#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	amountOfContacts = 0;
}

Phonebook::~Phonebook()
{
}

Contact* Phonebook::getList()
{
	return (contactList);
}

int Phonebook::getAmountOfContacts()
{
	return (amountOfContacts);
};

const std::string prompt_table[] = 
{
	"First name: ",
	"Last name: ",
	"Nickname: ",
	"Phone Number: ",
	"Darkest Secret: "
};

std::string getInput(std::string prompt)
{
	std::string input = "";

	while (input.empty())
	{
		std::cout << prompt << std::flush;
		std::getline(std::cin, input);
	}
	return (input);
}

void Phonebook::addList(void)
{
	std::cout << "-- Adding a new \e[38;5;201mcontact\e[0m to the phonebook --" << std::endl;
	for (int i = 7; i >= 1; --i)
	{	
		contactList[i].setFirstname(contactList[i - 1].getFirstname());
		contactList[i].setLastname(contactList[i - 1].getLastname());
		contactList[i].setNickname(contactList[i - 1].getNickname());
		contactList[i].setPhoneNumber(contactList[i - 1].getPhoneNumber());
		contactList[i].setDarkestSecret(contactList[i - 1].getDarkestSecret());
	}
	contactList[0].setFirstname(getInput(prompt_table[0]));
	contactList[0].setLastname(getInput(prompt_table[1]));
	contactList[0].setNickname(getInput(prompt_table[2]));
	contactList[0].setPhoneNumber(getInput(prompt_table[3]));
	contactList[0].setDarkestSecret(getInput(prompt_table[4]));
	increaseAmountOfContacts();
}

std::string cropString(std::string input)
{
	if (input.length() > 10)
	{
		input.resize(10);
		input.replace(9, 1, ".");
	}
	return (input);
}

void Phonebook::searchList(void)
{
	int key;
	std::string input;

	if (!contactList[0].getFirstname().empty())
	{
		std::cout << "-- This is your current \e[38;5;201mContacts\e[0m list --"  << std::endl;
		std::cout << "|";
		std::cout << "\e[38;5;220m";
		std::cout << std::right << std::setw(10) << "Index";
		std::cout << "\e[0m";
		std::cout << "|";
		std::cout << "\e[38;5;220m";
		std::cout << std::right << std::setw(10) << "First Name";
		std::cout << "\e[0m";
		std::cout << "|";
		std::cout << "\e[38;5;220m";
		std::cout << std::right << std::setw(10) << "Last Name";
		std::cout << "\e[0m";
		std::cout << "|";
		std::cout << "\e[38;5;220m";
		std::cout << std::right << std::setw(10) << "Nick Name";
		std::cout << "\e[0m";
		std::cout << "|";
		std::cout << std::endl;
		for (int i = 0; i < 8; i++)
		{
			Contact &contact = contactList[i];
	
			if (!contact.getFirstname().empty())
			{
				std::cout << "|" << std::right << std::setw(10) << i + 1 << "|";
				std::cout << std::right << std::setw(10) << cropString(contact.getFirstname()) << "|";
				std::cout << std::right << std::setw(10) << cropString(contact.getLastname()) << "|";
				std::cout << std::right << std::setw(10) << cropString(contact.getNickname()) << "|";
				std::cout << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Your \e[38;5;201mContacts\e[0m list seems empty. Try adding some people to it" << std::endl;
		return ;
	}
	std::cout << "Which \e[38;5;201mContact\e[0m are you looking for? \e[38;5;86m[1-" << getAmountOfContacts() << "]\e[0m" << std::endl;
	std::getline(std::cin, input);
	key = atoi(input.c_str());
	//if (key < 1 || key > 8)
	if (key < 1 || key > getAmountOfContacts())
	{
		std::cout << "Index out of range, could not retrieve information" << std::endl;
		return ;
	}
	else if (contactList[key - 1].getFirstname().empty())
	{
		std::cout << "Proper index was provided, but there is no information to retrieve yet" << std::endl;
	}
	else
	{
		std::cout << "First Name: " << contactList[key - 1].getFirstname() << std::endl;
		std::cout << "Last Name: " << contactList[key - 1].getLastname() << std::endl;
		std::cout << "Nickname: " << contactList[key - 1].getNickname() << std::endl;
		std::cout << "Phone Number: " << contactList[key - 1].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contactList[key - 1].getDarkestSecret() << std::endl;
	}
}

void	Phonebook::increaseAmountOfContacts()
{
	if (amountOfContacts < 8)
		amountOfContacts++;
}
