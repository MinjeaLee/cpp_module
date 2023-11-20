#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();
		ClapTrap	&operator=(const ClapTrap &copy);
		void		attack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		std::string	getName(void);
		void		setName(std::string name);
		unsigned int	getHitPoints(void);
		void		setHitPoints(unsigned int hitPoints);
		unsigned int	getEnergyPoints(void);
		void		setEnergyPoints(unsigned int energyPoints);
		unsigned int	getAttackDamage(void);
		void		setAttackDamage(unsigned int attackDamage);
};


#endif