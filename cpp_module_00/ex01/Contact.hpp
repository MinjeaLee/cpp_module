#include <iostream>

class Contact{
private:
	int index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phonenumber;
	std::string darkest_secret;
public:
	void setIndex(int index);
	void setFirstName(std::string first_name);
	void setLastName(std::string last_name);
	void setNickname(std::string nickname);
	void setPhoneNumber(std::string phonenumber);
	void setDarkestSecret(std::string darkest_secret);
	int getIndex();
	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	std::string getPhoneNumber();
	std::string getDarkestSecret();
};