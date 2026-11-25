#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
	public:
					FragTrap();
					FragTrap(const FragTrap &f);
		FragTrap	&operator=(const FragTrap &f);
					~FragTrap();

};

#endif