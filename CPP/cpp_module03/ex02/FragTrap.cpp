#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("frag")
{
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamega = 30;
	std::cout << "FragTrap constructor call\n";
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamega = 30;
	std::cout << "FragTrap name constructor call\n";
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor call\n";
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Hey, high five\n";
}