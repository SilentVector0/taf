#include " ClapTrap.hpp"
#include <iostream>

//!Forme canonique ───────────────────────────────────────────────────────────────

ClapTrap::ClapTrap(): _name("toto"), _hitPoint(10), _energyPoint(10), _attackDamega(0)
{
	std::cout << "constructor call\n";
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoint(10), _energyPoint(10), _attackDamega(0)
{
	std::cout << "constructor with name call\n";
}

ClapTrap::ClapTrap(const ClapTrap &c): _name(c._name), _hitPoint(c._hitPoint), _energyPoint(c._energyPoint), _attackDamega(c._attackDamega)
{
	std::cout << "copy constructor call\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
{
	if (this == &c)
		return(*this);
	std::cout << "operator= call\n";
	this->_name = c._name;
	this->_hitPoint = c._hitPoint;
	this->_energyPoint = c._energyPoint;
	this->_attackDamega = c._attackDamega;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor call\n";
}

void ClapTrap::attack(const std::string& target)
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
	std::cout << "ClapTrap ", _name, " attacks ", target, " causing ", _attackDamega, " points of damage!";

}
