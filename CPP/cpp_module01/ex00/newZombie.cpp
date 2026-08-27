#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie* Z1;

	Z1 = new Zombie();
	Z1->SetName(name);
	return (Z1);
}
