#include "Weapon.hpp"

class HumanB {
	private :
		std::string name;
		Weapon *weapon;
	public :
		HumanB(std::string name);
		HumanB::HumanB(std::string name, Weapon &weapon);
		~HumanB();
		void attack();
		void setWeapon(Weapon &weapon);
};