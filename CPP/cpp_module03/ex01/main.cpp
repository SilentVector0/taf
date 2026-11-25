#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <climits>

int main (void)
{
	int i = 0;

	ClapTrap c1;
	ClapTrap c2("tobias");
	ClapTrap c3(c2);

	ScavTrap s1;
	ScavTrap s2("jojo");
	ScavTrap s3(s2);
	ScavTrap s4("test");

	c1.attack("tobias");
	c2.takeDamage(0);
	c2.beRepaired(10);
	c2.attack("toto");
	c1.takeDamage(0);

	s1.attack("jojo");
	s2.takeDamage(20);
	s2.beRepaired(10);
	s2.attack("momo");
	s1.takeDamage(20);
	s1.guardGate();
	s2.guardGate();
	s2 = s4;
	s2.attack("jojo");
	while (i < 50)
	{
		s1.attack("jojo");
		i++;
	}
	s1.takeDamage(100);
}
