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
	if (this == &c)
		return (*this);
	ClapTrap::operator=(c);
	std::cout << "operator Scavtrap call\n";
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "destructor ScavTrap call\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoint <= 0)
	{
		std::cout << "error, your energy is empty\n";
		return;
	}
	if (_hitPoint <= 0)
	{
		std::cout << "error, you are dead\n";
		return;
	}
	_energyPoint -= 1;
	std::cout << "ScavTrap " << _name << " drop a big rock on " << target << " causing " << _attackDamega << " Point of damage\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode\n";
}
