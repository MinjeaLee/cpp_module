#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
	private :
		int index;
		Contact contacts[8];
		bool isNumber(std::string str);
		void printIndexRange();
		void printLine(std::string str);
		void printAllContacts();
		void printSelectedContact(int index);
	public :
		void initContact();
		void clearContact();
		int addContact();
		int searchContact();
};
