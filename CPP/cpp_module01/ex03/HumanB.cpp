#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _nameB(name), _wB(NULL){}

void	HumanB::setWeapon(Weapon &w)
{
	_wB = &w;
}

void HumanB::attack()
{
	if (_wB == NULL)
	{
		std::cout << "error, empty weapon\n";
		return;
	}
	std::cout << _nameB << " attacks with their " << _wB->GetType() << '\n';
}
