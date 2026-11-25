#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("frag")
{
	std::cout << "fragTrap constructor call\n";
}

FragTrap::FragTrap(const FragTrap &f): ClapTrap(f)
{
	std::cout << "FragTrap copy constructor call\n";
}

FragTrap &FragTrap::operator=(const FragTrap &f)
{
	if (this == &f)
		return (*this);
	ClapTrap::operator=(f);
	std::cout << "FragTrap operator= call\n";
	return (*this);
}