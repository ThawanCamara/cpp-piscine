#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const int fixedPoint);
		Fixed(const float fixedPoint);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		friend std::ostream& operator<<(std::ostream&, const Fixed&);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		int toInt() const;
		float toFloat() const;
		
	private:
		int fixedPoint;
		static const int fraction = 8;		
};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif
