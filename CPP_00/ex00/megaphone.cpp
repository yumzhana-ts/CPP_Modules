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
				std::cout << (char)toupper(argv[i][l]);
				l++;
			}
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}