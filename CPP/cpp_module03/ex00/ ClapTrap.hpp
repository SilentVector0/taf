#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	public:
			ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap &c);
			ClapTrap &operator=(const ClapTrap &c);
			~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
	std::string	_name;
	int			_hitPoint;
	int			_energyPoint;
	int			_attackDamega;
};

#endif
