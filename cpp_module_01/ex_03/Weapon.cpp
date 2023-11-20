#include "Weapon.hpp"

void Weapon::setType(std::string type) {
	this->type = type;
}

const std::string &Weapon::getType() {
	return (this->type);
}

Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::~Weapon() {
}