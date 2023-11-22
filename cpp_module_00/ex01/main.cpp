#include "PhoneBook.hpp"

int main(){
	std::string command;
	PhoneBook phonebook;

	phonebook.initContact();
	
	while (1){
		std::cout << "Enter a command: ";
		if (!std::getline(std::cin, command)){
			break;
		}
		if (command == "ADD"){
			if(!phonebook.addContact())
				break;
		}
		else if (command == "SEARCH"){
			phonebook.searchContact();
		}
		else if (command == "EXIT"){
			phonebook.clearContact();
			break;
		}
		else{
			std::cout << "Invalid command." << std::endl;
		}
	}

	return 0;
}