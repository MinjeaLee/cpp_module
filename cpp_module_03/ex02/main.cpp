#include "FragTrap.hpp"

int main(){
	FragTrap a("A");
	FragTrap b("B");

	a.attack("B");
	b.takeDamage(3);
	b.beRepaired(3);

	b.attack("A");
	a.takeDamage(10);
	a.beRepaired(10);

	a.highFivesGuys();
	b.highFivesGuys();
	return (0);
}