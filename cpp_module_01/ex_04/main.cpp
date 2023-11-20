#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv){
	if (argc != 4){
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	if (argv[2][0] == '\0' || argv[3][0] == '\0'){
		std::cout << "Empty string" << std::endl;
		return (1);
	}
	std::ifstream file(argv[1]);
	if (!file.is_open()){
		std::cout << "File not found" << std::endl;
		return (1);
	}
	std::string from = argv[2];
	std::string to = argv[3];
	std::string line;

	std::ofstream new_file(std::string(argv[1]) + ".replace");
	while (std::getline(file, line)){
		std::string::size_type pos = 0;
		while ((pos = line.find(from, pos)) != std::string::npos){
			line.erase(pos, from.length());
			line.insert(pos, to);
			pos += to.length();
		}
		new_file << line << std::endl;
	}
	file.close();
	new_file.close();
}