#include "PhoneBook.hpp"

void PhoneBook::initContact()
{
	this->index = 0;
	for (int i = 0; i < 8; i++)
	{
		clearContact();
	}
}

void PhoneBook::clearContact()
{
	for (int i = 0; i < 8; i++)
	{
		contacts[i].setIndex(0);
		contacts[i].setFirstName("");
		contacts[i].setLastName("");
		contacts[i].setNickname("");
		contacts[i].setPhoneNumber("");
		contacts[i].setDarkestSecret("");
	}
}

int PhoneBook::addContact()
{
	std::string input;
	this->contacts[index % 8].setIndex(index);
	first_name:
	std::cout << "Enter first name : ";
	if (!std::getline(std::cin, input))
		return 0;
	if (input.empty())
	{
		std::cout << "Invalid input." << std::endl;
		goto first_name;
	}
	this->contacts[index % 8].setFirstName(input);
	last_name:
	std::cout << "Enter last name : ";
	if (!std::getline(std::cin, input))
		return 0;
	if (input.empty())
	{
		std::cout << "Invalid input." << std::endl;
		goto last_name;
	}
	this->contacts[index % 8].setLastName(input);
	nickname:
	std::cout << "Enter nickname : ";
	if (!std::getline(std::cin, input))
		return 0;
	if (input.empty())
	{
		std::cout << "Invalid input." << std::endl;
		goto nickname;
	}
	this->contacts[index % 8].setNickname(input);
	phonenumber:
	std::cout << "Enter phone number : ";
	if (!std::getline(std::cin, input))
		return 0;
	if (input.empty())
	{
		std::cout << "Invalid input." << std::endl;
		goto phonenumber;
	}
	this->contacts[index % 8].setPhoneNumber(input);
	darkest_secret:
	std::cout << "Enter darkest secret :";
	if (!std::getline(std::cin, input))
		return 0;
	if (input.empty())
	{
		std::cout << "Invalid input." << std::endl;
		goto darkest_secret;
	}
	this->contacts[index % 8].setDarkestSecret(input);

	index++;
	return 1;
}

void PhoneBook::printIndexRange()
{
	std::cout << "Please enter the index (";
	if (index == 1)
	{
		std::cout << "0): ";
	}
	else if (index < 8)
	{
		std::cout << "0-" << index - 1 << "): ";
	}
	else
	{
		std::cout << "0-7): ";
	}
}

int PhoneBook::searchContact()
{
	std::string input;
	int input_index;

	if (this->index == 0)
	{
		std::cout << "No contact." << std::endl;
		return 1;
	}
	printAllContacts();
SERACH:
	printIndexRange();
	if (!std::getline(std::cin, input))
		return 0;
	if (input.empty())
	{
		std::cout << "Invalid index." << std::endl;
		goto SERACH;
	}
	if (isNumber(input) && !input.empty())
	{
		input_index = std::stoi(input);
	}
	else
	{
		std::cout << "Invalid index." << std::endl;
		goto SERACH;
	}
	if (index < 8 && (input_index < 0 || input_index >= this->index))
	{
		std::cout << "Invalid index." << std::endl;
		goto SERACH;
	}
	else if (index >= 8 && !(0 <= input_index && input_index <= 7))
	{
		std::cout << "Invalid index." << std::endl;
		goto SERACH;
	}

	printSelectedContact(input_index);

	return 1;
}

void PhoneBook::printLine(std::string str)
{
	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9) << ".";
	}
	else
	{
		std::cout << std::setw(10) << str;
	}
}

void PhoneBook::printAllContacts(){
	// system("clear");
	std::cout << index << std::endl;
	for (int i = 0; i < 45; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
	std::cout << "|";
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|" << std::endl;
	for (int i = 0; i < 45; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
	if (index > 8){

		for (int i = 0; i < 8; i++)
		{
			std::cout << "|";
			printLine(std::to_string(contacts[i].getIndex() % 8));
			std::cout << "|";
			printLine(contacts[i].getFirstName());
			std::cout << "|";
			printLine(contacts[i].getLastName());
			std::cout << "|";
			printLine(contacts[i].getNickname());
			std::cout << "|" << std::endl;
		}
	}
	else{
		for (int i = 0; i < index; i++)
		{
			std::cout << "|";
			printLine(std::to_string(contacts[i].getIndex() % 8));
			std::cout << "|";
			printLine(contacts[i].getFirstName());
			std::cout << "|";
			printLine(contacts[i].getLastName());
			std::cout << "|";
			printLine(contacts[i].getNickname());
			std::cout << "|" << std::endl;
		}
	}

	for (int i = 0; i < 45; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
}

void PhoneBook::printSelectedContact(int index){
	std::cout << "first name : " << contacts[index % 8].getFirstName() << std::endl;
	std::cout << "last name : " << contacts[index % 8].getLastName() << std::endl;
	std::cout << "nickname : " << contacts[index % 8].getNickname() << std::endl;
	std::cout << "phone number : " << contacts[index % 8].getPhoneNumber() << std::endl;
	std::cout << "darkest secret : " << contacts[index % 8].getDarkestSecret() << std::endl;
}

bool PhoneBook::isNumber(std::string str){
	for (int i = 0; str[i]; i++){
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}