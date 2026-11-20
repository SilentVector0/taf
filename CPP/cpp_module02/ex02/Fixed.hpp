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
		Fixed			&operator=(const Fixed &f);
						~Fixed();
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
						Fixed(const int _var);
						Fixed(const float _var);
		float			toFloat( void ) const;
		int				toInt( void ) const;
		bool			operator<(const Fixed &f) const;
		bool			operator>(const Fixed &f) const;
		bool			operator>=(const Fixed &f) const;
		bool			operator<=(const Fixed &f) const;
		bool			operator==(const Fixed &f) const;
		bool			operator!=(const Fixed &f) const;
		Fixed			operator+(const Fixed &f) const;
		Fixed			operator-(const Fixed &f) const;
		Fixed			operator*(const Fixed &f) const;
		Fixed			operator/(const Fixed &f) const;
		Fixed			operator++(const int);
		Fixed			&operator++();
		Fixed			operator--(const int);
		Fixed			&operator--();
		static Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

	private:
		int					_fix;
		static const int	fractional = 8;
};

std::ostream	&operator<<(std::ostream& flux, const Fixed &f);

#endif
