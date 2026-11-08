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

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (_fix);
}
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_fix = raw;
}
