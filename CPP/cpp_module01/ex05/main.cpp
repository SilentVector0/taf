#include "Harl.hpp"

int main()
{
	Harl h1;

	std::cout << "test DEBUG\n";
	h1.complain("DEBUG");
	std::cout << "test INFO\n";
	h1.complain("INFO");
	std::cout << "test WARNING\n";
	h1.complain("WARNING");
	std::cout << "test ERROR\n";
	h1.complain("ERROR");
	std::cout << "test empty\n";
	h1.complain("");
	std::cout << "test Wrong arg\n";
	h1.complain("faux");
	std::cout << "test Wrong syntax (DEBUG with space)\n";
	h1.complain("DEBUG  ");
	std::cout << "test Wrong syntax (debug)\n";
	h1.complain("debug");
}