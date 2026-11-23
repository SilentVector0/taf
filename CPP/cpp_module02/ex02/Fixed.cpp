#include "Fixed.hpp"

//!constru ───────────────────────────────────────────────────────────────

Fixed::Fixed()
{
	_fix = 0;
}

Fixed::Fixed(const Fixed &f)
{
	_fix = f._fix;
}

Fixed::Fixed(const int _var)
{
	_fix = (_var << fractional);
}

Fixed::Fixed(const float _var)
{
	int	num;

	num = 1 << fractional;
	_fix = int(roundf(_var * num));
}

//!operator_and_destruc ───────────────────────────────────────────────────────────────

Fixed	&Fixed::operator=(const Fixed &f)
{
	if (this != &f)
	{
		_fix = f._fix;
	}
	return (*this);
}

bool	Fixed::operator<(const Fixed &f) const
{
	return (this->_fix < f._fix);
}

bool	Fixed::operator>(const Fixed &f) const
{
	return (this->_fix > f._fix);
}

bool	Fixed::operator>=(const Fixed &f) const
{
	return (this->_fix >= f._fix);
}

bool	Fixed::operator<=(const Fixed &f) const
{
	return (this->_fix <= f._fix);
}

bool	Fixed::operator==(const Fixed &f) const
{
	return (this->_fix == f._fix);
}

bool	Fixed::operator!=(const Fixed &f) const
{
	return (this->_fix != f._fix);
}

Fixed	Fixed::operator+(const Fixed &f) const
{
	Fixed	res;

	res.setRawBits(this->_fix + f._fix);
	return(res);
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	Fixed	res;

	res.setRawBits(this->_fix - f._fix);
	return (res);
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	Fixed	res;
	int		num;

	num = 1 << fractional;
	res.setRawBits((this->_fix * f._fix) / num);
	return (res);
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	Fixed	res;
	int		num;


	if (f._fix == 0)
	{
		std::cerr << "error, divide a number by 0 is not allowed\n";
		return (res);
	}
	num = 1 << fractional;
	res.setRawBits((this->_fix * num) / f._fix);
	return (res);
}

Fixed	Fixed::operator++(const int)
{
	Fixed	res;

	res.setRawBits(this->_fix);
	this->setRawBits(res._fix + 1);
	return (res);
}

Fixed	&Fixed::operator++()
{
	this->setRawBits(this->_fix + 1);
	return (*this);
}

Fixed	Fixed::operator--(const int)
{
	Fixed	res;

	res.setRawBits(this->_fix);
	this->setRawBits(this->_fix - 1);
	return (res);
}

Fixed			&Fixed::operator--()
{
	this->setRawBits(this->_fix - 1);
	return (*this);
}

Fixed::~Fixed(){}

//!min_max ───────────────────────────────────────────────────────────────

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

//!get_set ───────────────────────────────────────────────────────────────

int		Fixed::getRawBits(void) const
{
	return (_fix);
}

void	Fixed::setRawBits(int const raw)
{
	_fix = raw;
}

//!other ───────────────────────────────────────────────────────────────

float	Fixed::toFloat(void) const
{
	float	num;

	num = 1 << fractional;
	return (_fix / num);
}

int Fixed::toInt(void) const
{
	return (_fix / (1 << fractional));
}

std::ostream	&operator<<(std::ostream& flux, const Fixed &f)
{
	flux << f.toFloat();
	return (flux);
}
