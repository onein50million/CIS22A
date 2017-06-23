//Daniel Wart
//Lab 7: student score calculation
//CIS22A
/*

ask user what type of input
if file input, read from file, otherwise read from commandline
read first line as int, put into num_scores
for i = 0; i < num_scores; i++:
	student_names[i] = getline
	student_scores[i] = getline as int
calculate the maximum, minimum, and mean of the two arrays:
	for int i = 0; i < num_scores; i ++:
		if student_scores[i] < minimum
			minimum = student_scores[i]
			etc...
Output to both a file and command line:
	max, min, mean, and the whether or not each student is the max, min, or above the mean
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

//nice to have, but will probably fail with unicode inputs
void LowerString(std::string &);

int FileData();
int CLIData();

//Removes some repetitve code
int GetInt(std::istream & input_stream, int &);
int GetInt(std::ifstream & input_stream, int &);

void ProcessScores(int & , int & , int & , int & , double & );
void Output(int &, int &, int &, int &, double &);

const int kMaxScores = 1 << 10; //bitwise is fun, equivalent to 1024
//these are global because basically every function uses them
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
	if (file_entry == "yes"){
		if (FileData()){
			return 1; //happens if the file can't be parsed
		}
	}
	else{
		CLIData();
	}
	int  lowest, lowest_index, highest, highest_index;
	double  mean;
	ProcessScores(lowest, lowest_index, highest, highest_index, mean);
	Output(lowest, lowest_index, highest, highest_index, mean);
	std::cin.get();
	return 0;
}
//File input and combined parser
int GetInt(std::ifstream & input_stream, int & output){
	std::string input;
	std::getline(input_stream, input);
	try{
		output = stoi(input);
	}
	catch (std::invalid_argument){
		std::cout << "File contains invalid data.";
		input_stream.close();
		return 1; //can't ask user to change value, so we have to quit
	}
}
//Command line input and combined parser
int GetInt(std::istream & input_stream, int & output){
	std::string input;
	while (true){
		std::getline(input_stream, input);
		try{
			output = stoi(input);
			return 0;
		}
		catch (std::invalid_argument){
			std::cout << "Invalid number.\n";
		}
	}
}
//won't work with unicode chars
void LowerString(std::string & input){
	for (int i = 0; i < input.length(); i++){
		input[i] = tolower(input[i]);
	}
}
//Gets input from files
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
	int score;
	GetInt(test_scores, num_scores);
	for(int i = 0; i < num_scores; i++){
		std::getline(test_scores, name);
		GetInt(test_scores, score);
		student_names[i] = name;
		student_scores[i] = score;
	}
	test_scores.close();
	return 0;
}
//Command Line Interface, similair to FileData, except it outputs some messages
int CLIData(){
	std::cout << "How many test scores are there (maximum of 1024)?\n";
	GetInt(std::cin, num_scores);
	if (num_scores < 1)
		num_scores = 1;
	if (num_scores > kMaxScores)
		num_scores = kMaxScores;
	std::string name;
	int score;
	for (int i = 0; i < num_scores; i++){
		std::cout << "What is the name of student " << (i + 1) << "?\n";
		std::getline(std::cin, name);
		std::cout << "What is the score of student (maximum of 100) " << (i + 1) << "?\n";
		GetInt(std::cin, score); //command line version
		student_names[i] = name;
		if (score < 0)
			score = 0;
		if (score > 100)
			score = 100;
		student_scores[i] = score; //stops scores from being to big
	}
	return 0;
}
//relatively simple, just iterates over the two arrays and checks if the current value is larger or smaller.
void ProcessScores(int & lowest, int & lowest_index, int & highest, int & highest_index, double & mean){
	lowest = highest = student_scores[0];
	lowest_index = highest_index = 0;
	int sum = 0;
	for (int i = 0; i < num_scores; i++){
		if (student_scores[i] < lowest){
			lowest = student_scores[i];
			lowest_index = i;
		}
		if (student_scores[i] > highest){
			highest = student_scores[i];
			highest_index = i;
		}
		sum += student_scores[i];
	}
	mean = sum / static_cast<double>(num_scores);
}

void Output(int & lowest, int & lowest_index, int & highest, int & highest_index, double & mean){
	int width = 13;
	int name_width = 20; //I found that the names were the longest parts, so I created a seperate width variable
	std::cout << "Number of scores: " << num_scores << '\n';
	std::cout << "Lowest score: " << lowest << '\n';
	std::cout << "Highest score: " << highest << '\n';
	std::cout << "Mean score: " << mean << '\n';
	std::cout << std::left
		<< std::setw(name_width) << "Name"
		<< std::setw(width) << "Score"
		<< std::setw(width) << "Is lowest"
		<< std::setw(width) << "Is highest"
		<< std::setw(width) << ">= Mean"
		<< '\n';
	for (int i = 0; i < num_scores; i++){
		std::cout
			<< std::setw(name_width) << student_names[i]
			<< std::setw(width) << student_scores[i]
			<< std::setw(width) << (i == lowest_index ? 'Y' : 'N')
			<< std::setw(width) << (i == highest_index ? 'Y' : 'N')
			<< std::setw(width) << (student_scores[i] >= mean ? 'Y' : 'N')
			<< '\n';
	}
	std::ofstream output_file("StudentScores.txt");
	std::cout << "Log file is StudentScores.txt";

	//Copy pasted from above, not sure how to make it cleaner
	output_file << "Number of scores: " << num_scores << '\n';
	output_file << "Lowest score: " << lowest << '\n';
	output_file << "Highest score: " << highest << '\n';
	output_file << "Mean score: " << mean << '\n';
	output_file << std::left
		<< std::setw(name_width) << "Name"
		<< std::setw(width) << "Score"
		<< std::setw(width) << "Is lowest"
		<< std::setw(width) << "Is highest"
		<< std::setw(width) << ">= Mean"
		<< '\n';
	for (int i = 0; i < num_scores; i++){
		output_file
			<< std::setw(name_width) << student_names[i]
			<< std::setw(width) << student_scores[i]
			<< std::setw(width) << (i == lowest_index ? 'Y' : 'N')
			<< std::setw(width) << (i == highest_index ? 'Y' : 'N')
			<< std::setw(width) << (student_scores[i] >= mean ? 'Y' : 'N')
			<< '\n';
	}
	output_file.close();
}