#include <iostream>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << " --\e[38;5;11mVariables Addresses\e[0m-- " << std::endl;
	std::cout << "STR: " << &str << std::endl;
	std::cout << "PTR: " << &ptr << std::endl;
	std::cout << "REF: " << &ref << std::endl;
	std::cout << std::endl;
	std::cout << " --\e[38;5;11mVariable Values\e[0m-- " << std::endl;
	std::cout << "STR: " << str << std::endl;
	std::cout << "PTR: " << *ptr << std::endl;
	std::cout << "REF: " << ref << std::endl;
	return (0);
}
