#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed &operator=(Fixed const &other);

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;
};