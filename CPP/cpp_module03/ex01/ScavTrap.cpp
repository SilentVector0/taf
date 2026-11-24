#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap("momo")
{
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamega = 20;
	std::cout << "ScavTrap constructor call\n";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamega = 20;
	std::cout << "ScavTrap constructor with name call\n";
}

ScavTrap::ScavTrap(const ScavTrap &c): ClapTrap(c)
{
	std::cout << "ScavTrap copy constructor call\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &c)
{

}
