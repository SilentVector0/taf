#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack()
{
	if (_weapon == NULL)
	{
		std::cout << "error: no weapon setup for the moment\n";
		return;
	}
	std::cout << _name << " attacks with their " << _weapon->getType() << '\n';
}
