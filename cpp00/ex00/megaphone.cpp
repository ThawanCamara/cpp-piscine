#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	(void)argc;
	if (!argv[1])
		std::cout << "* LOUD AND UNBEREABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (size_t i = 1; argv[i]; i++)
		{
			for (size_t j = 0; j < strlen(argv[i]); j++)
				argv[i][j] = toupper(argv[i][j]);
			std::cout << argv[i];
		}
		std::cout << std::endl;
	}
	return (0);
}
