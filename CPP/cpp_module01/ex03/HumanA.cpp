#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : _nameA(name), _wA(w){}

void HumanA::attack()
{
	std::cout << _nameA << " attacks with their " << _wA.GetType() << '\n';
}
