#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &w);
		void	attack();

	private:
		std::string _nameA;
		Weapon &_wA;
};

#endif
