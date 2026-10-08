#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "constructor call\n";
	_fix = 0;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "copy constructor call\n";
	_fix = f._fix;
}

Fixed	&Fixed::operator=(const Fixed &f)
{
	std::cout << "operator call\n";
	if (this != &f)
	{
		_fix = f._fix;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "destructor call\n";
}