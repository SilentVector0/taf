#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		void	attack();
		void	setWeapon(Weapon &w);

	private:
		std::string _nameB;
		Weapon *_wB;
};

#endif
