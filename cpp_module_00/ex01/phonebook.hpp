#include <iostream>
#include <string>
#include <iomanip>

class Contact{
	public:
		int index;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phonenumber;
		std::string darkest_secret;
};

class PhoneBook {
	public :
		int index;
		Contact contacts[8];
		void initContact();
		void clearContact();
		int addContact();
		void printIndexRange();
		int searchContact();
		void printLine(std::string str);
		void printAllContacts();
		void printSelectedContact(int index);
};
