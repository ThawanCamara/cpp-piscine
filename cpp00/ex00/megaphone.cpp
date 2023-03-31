#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
	if (!argv[1])
		std::cout << "* LOUD AND UNBEREABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; argv[i]; i++)
		{
			for (int j = 0; j < strlen(argv[i]); j++)
				argv[i][j] = toupper(argv[i][j]);
		std::cout << argv[i];
		}
		std::cout << std::endl;
	}
	return (0);
}
