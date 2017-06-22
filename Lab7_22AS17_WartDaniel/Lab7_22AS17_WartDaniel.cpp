#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

void LowerString(std::string &);
//Returns 0 if successful
int FileData();
int CLIData();
template <T>
T ReadFile(std::ifstream, T);

const int kMaxScores = 1 << 10;

int num_scores = 0;
std::string student_names[kMaxScores];
int student_scores[kMaxScores];

int main(){
	std::string file_entry;
	std::cout << "Would you like to enter scores via file input?\n";
	while (true){
		std::getline(std::cin, file_entry);
		LowerString(file_entry);
		if (file_entry == "yes" || file_entry == "no")
			break;
		else
			std::cout << "Invalid answer\n";
	}
	if (file_entry == "yes")
		FileData();
	else
		CLIData();
	std::cin.get();
	return 0;
}
template <T>
T ReadFile(std::ifstream file_stream, T output){
	std::string input;
	std::getline(file_stream, input);
	try{
		score = stoi(input);
	}
	catch (std::invalid_argument){
		std::cout << "File contains invalid scores. Exiting...\n";
		test_scores.close();
		return 1;
	}
}

void LowerString(std::string & input){
	for (int i = 0; i < input.length(); i++){
		input[i] = tolower(input[i]);
	}
}
int FileData(){
	std::ifstream test_scores;
	std::string file_name;
	std::cout << "Enter file name: ";
	while (true){
		std::getline(std::cin, file_name);
		test_scores.open(file_name);
		if (test_scores)
			break;
		else
			std::cout << "Invalid file name\n";
	}
	std::string name;
	std::string input;
	int score;
	while (true){
		std::getline(test_scores, name);
		std::getline(test_scores, input);
		try{
			score = stoi(input);
		}
		catch (std::invalid_argument){
			std::cout << "File contains invalid scores. Exiting...\n";
			test_scores.close();
			return 1;
		}
		student_names[num_scores] = name;
		student_scores[num_scores] = score;
	}
	return 0;
}
int CLIData(){
	return 0;
}