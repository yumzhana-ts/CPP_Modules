#include <iostream>

int main(int argc, char **argv)
{
	int i;
	int l;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			l = 0;
			while (argv[i][l])
			{
				if(std::isalpha(argv[i][l]))
					argv[i][l] = std::toupper(argv[i][l]);
				std::cout << argv[i][l];
				l++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}