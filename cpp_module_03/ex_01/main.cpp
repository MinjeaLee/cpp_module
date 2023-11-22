#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap a("A");
	ScavTrap b("B");

	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(3);

	b.attack("A");
	a.takeDamage(10);
	a.beRepaired(10);

	b.guardGate();

	return (0);
}