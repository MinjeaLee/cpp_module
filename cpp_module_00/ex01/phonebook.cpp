#include "phonebook.hpp"

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
		contacts[i].index = 0;
		contacts[i].first_name.clear();
		contacts[i].last_name.clear();
		contacts[i].nickname.clear();
		contacts[i].phonenumber.clear();
		contacts[i].darkest_secret.clear();
	}
}

int PhoneBook::addContact()
{
	this->contacts[index % 8].index = index;
	first_name:
	std::cout << "Enter first name : ";
	if (!std::getline(std::cin, contacts[index % 8].first_name))
		return 0;
	if (contacts[index % 8].first_name.empty())
	{
		std::cout << "Invalid input." << std::endl;
		goto first_name;
	}
	last_name:
	std::cout << "Enter last name : ";
	if (!std::getline(std::cin, contacts[index % 8].last_name))
		return 0;
	if (contacts[index % 8].last_name.empty())
	{
		std::cout << "Invalid input." << std::endl;
		goto last_name;
	}
	nickname:
	std::cout << "Enter nickname : ";
	if (!std::getline(std::cin, contacts[index % 8].nickname))
		return 0;
	if (contacts[index % 8].nickname.empty())
	{
		std::cout << "Invalid input." << std::endl;
		goto nickname;
	}
	phonenumber:
	std::cout << "Enter phone number : ";
	if (!std::getline(std::cin, contacts[index % 8].phonenumber))
		return 0;
	if (contacts[index % 8].phonenumber.empty())
	{
		std::cout << "Invalid input." << std::endl;
		goto phonenumber;
	}
	darkest_secret:
	std::cout << "Enter darkest secret :";
	if (!std::getline(std::cin, contacts[index % 8].darkest_secret))
		return 0;
	if (contacts[index % 8].darkest_secret.empty())
	{
		std::cout << "Invalid input." << std::endl;
		goto darkest_secret;
	}

	// print this contact
	std::cout << "first name : " << contacts[index % 8].first_name << std::endl;
	std::cout << "last name : " << contacts[index % 8].last_name << std::endl;
	std::cout << "nickname : " << contacts[index % 8].nickname << std::endl;
	std::cout << "phone number : " << contacts[index % 8].phonenumber << std::endl;
	std::cout << "darkest secret : " << contacts[index % 8].darkest_secret << std::endl;


	index++;

	std::cout << strlen(contacts[0].first_name.c_str()) << std::endl;
	return 1;
}

void PhoneBook::printIndexRange()
{
	std::cout << "Please enter the index (";
	if (index == 1)
	{
		std::cout << "0): ";
	}
	else if (this->index < 8)
	{
		std::cout << "0-" << this->index - 1 << "): ";
	}
	else
	{
		std::cout << this->index - 8 << "-"<< this->index - 1 << "): ";
	}
}

int PhoneBook::searchContact()
{
	int input_index;

	if (this->index == 0)
	{
		std::cout << "No contact." << std::endl;
		return 1;
	}
	printAllContacts();

	printIndexRange();
	std::cin >> input_index;
	if (std::cin.fail())
	{
		std::cin.clear();													// 오류 상태 초기화
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 남아있는 버퍼 제거
		std::cout << "Invalid input." << std::endl;
		return 1;
	}
	getchar();
	// std::cout << input_index << std::endl;
	if (input_index < 0 || input_index >= this->index)
	{
		std::cout << "Invalid index." << std::endl;
		return 1;
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
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|";
		printLine(std::to_string(contacts[i].index));
		std::cout << "|";
		printLine(contacts[i].first_name);
		std::cout << "|";
		printLine(contacts[i].last_name);
		std::cout << "|";
		printLine(contacts[i].nickname);
		std::cout << "|" << std::endl;
	}

	for (int i = 0; i < 45; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
}

void PhoneBook::printSelectedContact(int index){
	std::cout << "first name : " << contacts[index % 8].first_name << std::endl;
	std::cout << "last name : " << contacts[index % 8].last_name << std::endl;
	std::cout << "nickname : " << contacts[index % 8].nickname << std::endl;
	std::cout << "phone number : " << contacts[index % 8].phonenumber << std::endl;
	std::cout << "darkest secret : " << contacts[index % 8].darkest_secret << std::endl;
}