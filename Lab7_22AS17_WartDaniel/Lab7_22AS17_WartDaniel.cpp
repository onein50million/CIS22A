#include <iostream>
#include <string>
#include <iomanip>

void LowerString(std::string & input){
	for (int i = 0; i < input.length(); i++){
		tolower(input[i]);
	}
}

int main(){

	bool file_entry;
	std::string input;
	std::cout << "Would you like to enter scores via file input?\n";
	std::getline(std::cin, input);
	LowerString(input);
	std::cout << input;
	if (input == "yes"){
		std::cout << "GOOD\n";
	}

	std::cin.get();
	return 0;
}