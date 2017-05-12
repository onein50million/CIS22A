/*
Daniel Wart CIS 22A Spring 2017
EC1 - Extra Credit Simple Calculator
*/

#include <iostream>
#include <string>
#include <cmath>

int calculate(char op, int num1, int num2){
	switch (op){
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '/': return num1 / num2;
	case '*': return num1 * num2;
	case '%': return num1 % num2;
	case '^': return std::pow(num1, num2);
	default: return 0;
	}
}

int main(){

	int number1, number2;
	char calcOperator;
	std::string input;
	std::cout << "Enter operator as + - / * % ^\n";
	std::getline(std::cin, input);
	calcOperator = input.at(0); //getline returns a string so we need to get the first character

	std::cout << "First Integer: ";
	std::getline(std::cin, input);
	number1 = stoi(input);

	std::cout << "Second Integer: ";
	std::getline(std::cin, input);
	number2 = stoi(input);

	std::cout << "Result: " << calculate(calcOperator, number1, number2) << "\n";
	std::cout << "Hit <Enter> to quit";
	std::cin.get();
	return 0;
}


