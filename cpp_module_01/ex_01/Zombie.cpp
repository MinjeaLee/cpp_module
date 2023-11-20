#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " destroyed" << std::endl;
}

void Zombie::announce()
{
	std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

void randomChump(std::string name)
{
	Zombie zombie;
	zombie.setName(name);
	zombie.announce();
}

Zombie *newZombie(std::string name)
{
	Zombie *zombie = new Zombie();
	zombie->setName(name);
	// zombie->announce();
	return (zombie);
}
