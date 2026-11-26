#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <climits>

int main (void)
{
	{
		ClapTrap c1;
		ClapTrap c2("tobias");
		ClapTrap c3(c2);

		c1.attack("tobias");
		c2.takeDamage(0);
		c2.beRepaired(10);
		c2.attack("toto");
		c1.takeDamage(0);
	}
	std::cout << "\n";
	{
		ScavTrap s1;
		ScavTrap s2("jojo");
		ScavTrap s3(s2);
		ScavTrap s4("test");

		s1.attack("jojo");
		s2.takeDamage(20);
		s2.beRepaired(10);
		s2.attack("momo");
		s1.takeDamage(20);
		s1.guardGate();
		s2.guardGate();
		s2 = s4;
		s2.attack("jojo");
		s1.takeDamage(100);
	}
	std::cout << "\n";
	{
		FragTrap f1;
		FragTrap f2("frag1");
		FragTrap f3(f2);
		FragTrap f4("frag2");

		f1.highFivesGuys();
		f1.attack("frag2");
		f4.takeDamage(30);
		f2 = f1;
	}
}
