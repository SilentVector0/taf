#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	public:
				Fixed();
				Fixed(const Fixed &f);
				Fixed	&operator=(const Fixed &f);
				~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
				Fixed(const int _var);
				Fixed(const float _var);
		float	toFloat( void ) const;

	private:
		int					_fix;
		static const int	fractional = 8;
};

#endif
