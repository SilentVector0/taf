#include "PhoneBook.hpp"

int main ()
{
	PhoneBook p;
	std::string input;

	std::cout << "Welcome to your phonebook. Available commands: ADD, SEARCH, EXIT.\n";
	while (1)
	{
		std::cout << '>';
		std::getline(std::cin, input);
		if (input == "ADD")
			p.Add();
		else if (input == "SEARCH")
			p.Search();
		else if (input == "EXIT")
			p.Exit();
	}
}
