#include <iostream>

int main(){
	std::string brain = "HI THIS IS BRAIN";
	std::string *brainPtr = &brain;
	std::string &brainRef = brain;

	std::cout << "brain_addr : " << &brain << std::endl;
	std::cout << "brainPtr_addr : " << brainPtr << std::endl;
	std::cout << "brainRef_addr : " << &brainRef << std::endl;

	std::cout << "brain: " << brain << std::endl;
	std::cout << "brainPtr: " << *brainPtr << std::endl;
	std::cout << "brainRef: " << brainRef << std::endl;

	return (0);
}