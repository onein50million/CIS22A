// CIS 22A
// Lab 2: McDonald's Receipt
// Name: Daniel Wart

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>


template <class T>
void GetInput(std::istream &stream, T &output);
std::string CenterText(std::string input, int width);
int main(){
	double sandwich_cost;
	double fries_cost;
	double soda_cost;
	double tax_rate;

	int num_sandwiches;
	int num_fries;
	int num_sodas;

	double subtotal;
	double discount_rate;
	double discount_amount;
	double tax;
	double total;

	//User input
	//Amounts
	std::cout << "Number of sandwiches\n";
	GetInput(std::cin, num_sandwiches);
	std::cout << "Number of medium fries\n";
	GetInput(std::cin, num_fries);
	std::cout << "Number of medium sodas\n";
	GetInput(std::cin, num_sodas);

	//Prices
	std::cout << "Price of sandwiches\n";
	GetInput(std::cin, sandwich_cost);
	std::cout << "Price of medium fries\n";
	GetInput(std::cin, fries_cost);
	std::cout << "Price of medium sodas\n";
	GetInput(std::cin, soda_cost);
	std::cout << "Tax rate as a percent\n";
	GetInput(std::cin, tax_rate);
	tax_rate /= 100;


	//Calculations
	subtotal = num_sandwiches * sandwich_cost +
		num_fries * fries_cost +
		num_sodas * soda_cost;

	// multiply 0.05, the discount amount, by 1 or 0, depending on the amount of sodas/fries ordered
	if (num_sandwiches){
		discount_rate = 0.05 * (num_fries ? 1 : 0) + 0.05 * (num_sodas ? 1 : 0);
	}
	else{
		discount_rate = 0;
	}

	discount_amount = subtotal * discount_rate;
	tax = (subtotal - discount_amount) * tax_rate;
	total = subtotal - discount_amount + tax;

	//Output
	//Lines are 48 characters wide

	std::cout << std::left << std::setprecision(2) << std::fixed; //Used for monetary output

	//Header
	std::cout << "\n" << CenterText("McDonald's Restaurant", 48) << "\n";
	std::cout << CenterText("123 456 7890", 48) << "\n";
	std::cout << CenterText("123 Example Lane, CA 12345", 48) << "\n";
	std::cout << CenterText("May 10, 2017", 48) << "\n";
	std::cout << CenterText("Order number 432", 48) << "\n";

	std::cout << std::setw(44) << "QTY ITEM" << "TOTAL\n";
	if (num_sandwiches){
		std::cout << std::right << std::setw(3) << num_sandwiches << " "
			<< std::left << std::setw(40) << "SANDWICH" << num_sandwiches * sandwich_cost << "\n";
	}
	if (num_fries){
		std::cout << std::right << std::setw(3) << num_fries << " "
			<< std::left << std::setw(40) << "M. FRIES" << num_fries * fries_cost << "\n";
	}
	if (num_sodas){
		std::cout << std::right << std::setw(3) << num_sodas << " "
			<< std::left << std::setw(40) << "M. SODA" << num_sodas * soda_cost << "\n\n";
	}
	std::cout << std::left << std::setw(44) << "Subtotal" <<  subtotal << "\n";
	std::cout << std::left << std::setw(44) << "Combo Discount" << discount_amount << "\n\n";
	std::cout << std::left << std::setw(44) << "Tax" << tax << "\n\n";
	std::cout << std::left << std::setw(44) << "Total" << total << "\n\n";
	std::cout << CenterText("Thank you for eating at McDonald's",48) << "\n" << CenterText("Come back another time!",48) << "\n";
	std::cin.get();
	return 0;
}

//Gets input from input stream "stream" and outputs to generic type "output"
template <class T>
void GetInput(std::istream &stream, T &output){
	std::string input;
	bool success = false;
	while (!success){
		try{
			std::getline(stream, input);
			output = stoi(input);
			success = true;
		}
		catch (std::invalid_argument){
			std::cout << "Invalid Argument\n";
			success = false;
		}
	}
}
//Centers the text input
std::string CenterText(std::string input, int width){
	int length = input.length();
	int spacing = (std::fmax(0,width - length)) / 2;
	return std::string(spacing, ' ') +
		input +
		std::string(spacing, ' ');
}