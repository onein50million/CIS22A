//TODO: Format output
//TODO: Money formatting
//TODO: Name block
//TODO: Price input
#include <iostream>
#include <iomanip>
#include <string>


const double kTaxRate = 0.0925;
int main(){
	double sandwich_cost;
	double fries_cost;
	double soda_cost;

	int num_sandwiches;
	int num_fries;
	int num_sodas;

	double subtotal;
	double discount_rate;
	double discount_amount;
	double tax;
	double total;

	//Get user input
	std::string input;
	//Amounts
	std::cout << "Number of sandwiches\n";
	std::getline(std::cin, input);
	num_sandwiches = stoi(input);

	std::cout << "Number of medium fries\n";
	std::getline(std::cin, input);
	num_fries = stoi(input);

	std::cout << "Number of medium sodas\n";
	std::getline(std::cin, input);
	num_sodas = stoi(input);
	//Prices
	std::cout << "Price of sandwiches\n";
	std::getline(std::cin, input);
	sandwich_cost = stoi(input);

	std::cout << "Price of medium fries\n";
	std::getline(std::cin, input);
	fries_cost = stoi(input);

	std::cout << "Price of medium sodas\n";
	std::getline(std::cin, input);
	soda_cost = stoi(input);

	// begin calculations
	subtotal = num_sandwiches * sandwich_cost +
		num_fries * fries_cost +
		num_sodas * soda_cost;

	// multiply 0.05, the discount amount, by the number of sodas and fries represented as a boolean value
	discount_rate = 0.05 * (num_fries ? 1 : 0) + 0.05 * (num_sodas ? 1 : 0);

	discount_amount = subtotal * discount_rate;
	tax = (subtotal - discount_amount) * kTaxRate;
	total = subtotal - discount_amount + tax;

	std::cout << "Ordered" << num_sandwiches << " sandwiches, " << num_fries << " fries, " << num_sodas << " sodas" << "\n";
	std::cout << "Subtotal: " << subtotal << "\nDiscount: " << discount_amount << "\nTax: " << tax << "\nTotal: " << total;
	std::cin.get();
	return 0;
}