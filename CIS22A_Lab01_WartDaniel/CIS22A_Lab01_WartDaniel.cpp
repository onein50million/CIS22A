/*
CIS 22A
Lab 1A: interview
Name: Daniel Wart
*/

#include <iostream>
#include <string>


int main(){
	int length = 5;
	std::string interview[5] = {
		"What is your name?",
		"What is your major at De Anza?",
		"Why are you taking this class?",
		"What other programming classes have you taken in the last 2 years?",
		"Where do you usually sit in this class?"};
	std::string answers[5] = {
		"My name is Daniel",
		"I am majoring in computer science",
		"I am taking this class to learn c++",
		"I took AP comp sci as a senior in high school",
		"I usually sit near the front" };
	for(int i = 0; i < 5; i++){
		std::cout<<"Question: "<<interview[i]<<"\nAnswer: "<<answers[i]<<"\n";
	}
	std::cin.get();
	return 0;
}