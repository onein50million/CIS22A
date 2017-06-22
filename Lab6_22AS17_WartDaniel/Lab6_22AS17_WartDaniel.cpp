//Daniel Wart
//Lab 6: Reverse file
//CIS 22A
#include <iostream>
#include <fstream>
#include <string>
int main(){
	const int kMaxSize = 1024;
	char forward_text[kMaxSize];
	std::string file_name;
	std::ifstream forward_file;
	std::ofstream reverse_file;
	std::cout << "Name of file to be reversed, 1024 characters maximum: \n";

	while (true){
		std::cin.clear();
		std::getline(std::cin,file_name);
		forward_file.open(file_name);
		if (!forward_file)
			std::cout << "Invalid name\n";
		else
			break;
	}

	int num_characters = 0;
	char input;
	while (forward_file.get(input) && num_characters < 1024){
		forward_text[num_characters] = input;
		num_characters++;
	}
	std::cout << "File outputting to 'Reverse of " << file_name << "'\n";
	reverse_file.open("Reverse of " + file_name);

	//output the last char in the array first until we reach the first index
	for (int i = num_characters-1; i >= 0; i--){
		reverse_file << forward_text[i];
	}
	forward_file.close();
	reverse_file.close();
	std::cin.get();
	return 0;
}