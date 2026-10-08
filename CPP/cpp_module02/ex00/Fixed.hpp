#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed	&operator=(const Fixed &f);
		~Fixed();

	private:
		int					_fix;
		static const int	fractional = 8;
};

#endif