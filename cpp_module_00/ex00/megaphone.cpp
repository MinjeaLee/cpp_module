#include <iostream>

int main(int argc, char **argv){
	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return 0;
	}	
	for (int i = 1; i < argc; i++){
		for(int j = 0; argv[i][j]; j++){
			if (argv[i][j] == ' '){
				std::cout << argv[i][j];
			}
			else{
				std::cout << (char)std::toupper(argv[i][j]);
			}
		}
	}	
	std::cout << std::endl;
	return 0;
}