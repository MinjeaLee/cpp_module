#include "Harl.hpp"

int main(){
	Harl harl;

	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");
	harl.complain("EXIT");

	return 0;
}