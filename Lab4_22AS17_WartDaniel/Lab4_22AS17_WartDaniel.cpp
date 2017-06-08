#include <fstream>
#include <iostream>
#include <string>

int main(){
	std::ifstream source_file;
	std::string source_name;
	std::ofstream destination_file;
	std::string destination_name;

	std::cout << "Enter a file name to copy\n";
	while (true){
		std::getline(std::cin ,source_name);
		source_file.open(source_name, std::ios::binary);
		if (!source_file)
			std::cout << "Invalid file\n";
		else
			break;
	}
	std::cout << "Enter an output location and name\n";
	std::getline(std::cin, destination_name);
	destination_file.open(destination_name, std::ios::binary);
	char transfer;
	while (source_file.get(transfer)){
		destination_file << transfer;
	}
	source_file.close();
	destination_file.close();
	std::cin.get();
	return 0;
}