#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "error, your programm must have 3 param, filename, string1 and string2\n";
		return (1);
	}
	std::ifstream source(argv[1]);
	std::string outfile = argv[1];
	outfile += ".replace";
	std::ofstream dest(outfile.c_str());

	if (!source || !dest)
	{
		std::cout << "error during the open\n";
		return (1);
	}
	std::ostringstream buf;
	buf << source.rdbuf();
	std::string temp = buf.str();

	std:: string final;
	int pos = temp.find(argv[2], 0);

	while (1)
	{
		
		if (pos == std::string::npos)
			break;
	}

}
