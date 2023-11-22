#include <iostream>
#include <math.h>

class Fixed
{
private:
	int fixedPointValue;
	static const int fractionalBits = 8;

public:
	Fixed(void);
	Fixed(Fixed const &src);
	Fixed(int const value);
	Fixed(float const value);

	~Fixed(void);

	Fixed &operator=(Fixed const &other);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);