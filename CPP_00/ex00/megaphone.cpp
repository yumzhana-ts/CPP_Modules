#include <iostream>

int main(int argc, char** argv)
{
	int i;
	int l;

	i = 1;
	l = 0;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while(argv[i])
	{
		while(argv[i][l])
		{
			std::cout << (char)toupper(argv[i][l]);
			l++;
		}
		i++;
	}
	return(0);
}