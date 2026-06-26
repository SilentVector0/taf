#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	int i = 1;

	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (argv[i])
	{
		int j = 0;
		while (argv[i][j])
		{
			std::cout << (char)toupper(argv[i][j]);
			j++;
		}
		// if (argv[i + 1])
		// {
		// 	std::cout << ' ';
		// }
		j = 0;
		i++;
	}
	std::cout << std::endl;
	return (0);
}