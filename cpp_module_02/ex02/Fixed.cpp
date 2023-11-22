#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->fixedPointValue = 0;
}

Fixed::Fixed(Fixed const &src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const value){
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = value << this->fractionalBits;
}

Fixed::Fixed(float const value){
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = roundf(value * (1 << this->fractionalBits));
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}


Fixed& Fixed::operator=(Fixed const &other){
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other){
		this->fixedPointValue = other.getRawBits();
	}
	return *this;
}

bool Fixed::operator<(Fixed const &other) const {
	return this->fixedPointValue < other.getRawBits();
}

bool Fixed::operator>(Fixed const &other) const {
	return this->fixedPointValue > other.getRawBits();
}

bool Fixed::operator<=(Fixed const &other) const {
	return this->fixedPointValue <= other.getRawBits();
}

bool Fixed::operator>=(Fixed const &other) const {
	return this->fixedPointValue >= other.getRawBits();
}

bool Fixed::operator==(Fixed const &other) const {
	return this->fixedPointValue == other.getRawBits();
}

bool Fixed::operator!=(Fixed const &other) const {
	return this->fixedPointValue != other.getRawBits();
}

Fixed Fixed::operator+(Fixed const &other){
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(Fixed const &other){
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(Fixed const &other){
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const &other){
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(void){ // prefix
	this->fixedPointValue++;
	return *this;
}

Fixed &Fixed::operator--(void){ // prefix
	this->fixedPointValue--;
	return *this;
}

Fixed Fixed::operator++(int){ // postfix
	Fixed tmp(*this);
	this->fixedPointValue++;
	return tmp;
}

Fixed Fixed::operator--(int){ // postfix
	Fixed tmp(*this);
	this->fixedPointValue--;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	return a > b ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b){
	return a < b ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b){
	return a > b ? a : b;
}

int Fixed::getRawBits(void) const{
	return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw){
	this->fixedPointValue = raw;
}

float Fixed::toFloat(void) const{
	return (float)this->fixedPointValue / (float)(1 << this->fractionalBits);
}

int Fixed::toInt(void) const{
	return this->fixedPointValue >> this->fractionalBits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs){
	o << rhs.toFloat();
	return o;
}