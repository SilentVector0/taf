#include "ClapTrap.hpp"
#include <climits>

int main (void)
{
	ClapTrap c1;
	ClapTrap c2("tobias");
	ClapTrap c3(c2);

	c1.attack("tobias");
	c2.takeDamage(1);
	c2.beRepaired(10);
	c2.attack("toto");
	c1.takeDamage(1);
	c2.attack("toto");
	c2.attack("toto");
	c2.beRepaired(UINT_MAX);
	c2.attack("toto");
	c2.attack("toto");
	c2.attack("toto");
	c2.attack("toto");
	c2.attack("toto");
	c2.attack("toto");
	c2.attack("toto");
}
