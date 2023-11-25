#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = copy.type;
	// if (this->brain)
	// 	delete this->brain;
	this->brain = new Brain(*copy.getBrain());
	
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &copy) 
	{ 
		if (this->brain)
			delete this->brain;
		this->type = copy.type;
		this->brain = new Brain(*copy.getBrain());
	}
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (this->brain);
}