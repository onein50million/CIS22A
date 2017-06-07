#include <fstream>
#include <iostream>
#include <string>

int main(){
	std::ifstream file_to_copy;
	std::string file_name;
	std::string output_name;
	std::cout << "Enter a file name to copy\n";
	while (true){
		std::getline(std::cin ,file_name);
		file_to_copy.open(file_name);
		if (!file_to_copy)
			std::cout << "Invalid file\n";
		else
			break;
	}
	std::cout << "Enter an output location and name\n";
	std::getline(std::cin, output_name);
	
	std::ofstream output_file;
	output_file.open(output_name);
	std::string transfer;
	while (file_to_copy){	
		transfer = "";
		file_to_copy >> transfer;
		output_file << transfer;
	}
	file_to_copy.close();
	output_file.close();
	std::cin.get();
	return 0;
}