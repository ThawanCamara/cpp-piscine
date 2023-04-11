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
		static Fixed& min(Fixed& lvalue, Fixed& rvalue);
		static Fixed& max(Fixed& lvalue, Fixed& rvalue);
		static const Fixed& min(const Fixed& lvalue, const Fixed& rvalue);
		static const Fixed& max(const Fixed& lvalue, const Fixed& rvalue);

		Fixed operator+(const Fixed& other);
		Fixed operator-(const Fixed& other);
		Fixed operator*(const Fixed& other);
		Fixed operator/(const Fixed& other);
		Fixed operator++(void);
		Fixed operator++(int);
		Fixed operator--(void);
		Fixed operator--(int);
	
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
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
