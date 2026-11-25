#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
				ScavTrap();
				ScavTrap(const ScavTrap &c);
		ScavTrap &operator=(const ScavTrap &c);
				~ScavTrap();
				ScavTrap(std::string name);
		void 	guardGate();
		void 	attack(const std::string& target);
};

#endif
