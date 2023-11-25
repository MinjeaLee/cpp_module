#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = copy.type;
	this->brain = new Brain(*copy.getBrain());
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &copy)
	{
		if (this->brain)
			delete this->brain;
		this->type = copy.type;
		this->brain = new Brain(*copy.getBrain());
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

Brain* Dog::getBrain() const
{
	return (this->brain);
}