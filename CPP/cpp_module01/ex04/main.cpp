#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int main (int argc, char **argv)
{
	std::string			outfile;
	std::ostringstream	buf;
	std::string			temp;
	std:: string		final;
	size_t				occ;
	size_t				pos = 0;
	std::string			s1;
	std::string			s2;

	if (argc != 4)
	{
		std::cerr << "error, your programm must have 3 param, filename, string1 and string2\n";
		return (1);
	}
	if (!argv[2] || argv[2][0] == '\0')
	{
		std::cerr << "error, your string 1 is empty\n";
		return (1);
	}
	s1 = argv[2];
	s2 = argv[3];
	std::ifstream source(argv[1]);
	if (!source)
		return (std::cerr << "error during the source open\n", 1);
	outfile = argv[1];
	outfile += ".replace";
	std::ofstream dest(outfile.c_str());
	if (!dest)
		return (std::cerr << "error during the dest open\n", 1);
	buf << source.rdbuf();
	temp = buf.str();
	occ = temp.find(argv[2], 0);
	while (occ != std::string::npos)
	{
		final += temp.substr(pos, occ - pos);
		final.append(s2);
		pos = occ + s1.length();
		occ = temp.find(argv[2], pos);
	}
	final += temp.substr(pos);
	dest << final;
}

/*
Test:
./Brain inexistant.txt "haha" "bubu" (file inexistant: error)
./Brain empty.txt "haha" "bubu" (file vide: rien de remplacé)
./Brain test.txt "" "b" (s1 vide: error)
./Brain test.txt "a" "" (s2 vide: remplacé par rien)
./Brain test.txt "a" "bb" "" (trop arg: error)
./Brain test.txt "a" (trop peu arg: error)
*/
