// CIS 22A
// Lab 3: Property Tax
// Name: Daniel Wart
/*
user input into num_properties(int)
for(i = 0; i < num_properties; i++):
	user input into property_value(double), senior_citizen(bool)
	if senior_citizen:
		user input into quarterly_payment(bool)
	taxable_value = property_value*0.6
	if senior citizen:
		payment = tax_amount / 4
	else:
		payment = tax_amount
	output right align, 2 decimal places:
		property_value
		property_value*0.6
		senior_citizen
		property_value*0.6*0.1
		taxable_value
		tax_amount
		payment
*/
#include <string>
#include <iostream>
#include <iomanip>

//Gets input from input stream "stream" and outputs to generic type "output"
template <class T>
void GetInput(std::istream & stream, T & output){
	std::string input;
	while (true){
		try{
			std::getline(stream, input);
			output = stoi(input);
			break;
		}
		catch (std::invalid_argument){
			std::cout << "Invalid Input\n";
		}
	}
}

int main(){

	//inputs
	double property_value;
	bool senior_citizen;
	bool quarterly_payements;
	int num_properties;
	std::string input;

	//processed
	double taxable_value;
	double tax_amount;
	double payment;
	std::cout << "How many properties should be generated?\n";
	GetInput(std::cin, num_properties);

	for (int i = 0; i < num_properties; i ++){
		std::cout << "What is the value of the property?\n";
		GetInput(std::cin, property_value);
		std::cout << "Is the owner a senior citizen?\n";
		std::getline(std::cin, input);
		senior_citizen = input.compare("Yes") == 0 ? true : false;

		if (senior_citizen){
			std::cout << "Is the payment quarterly or annually?\n";
			std::getline(std::cin, input);
			quarterly_payements = input.compare("Quarterly") == 0 ? true : false;
		}
		else{
			quarterly_payements = false;
		}
		std::cout << "\n";
		taxable_value = property_value*0.6;
		if (senior_citizen){
			taxable_value *= 0.9;
		}
		tax_amount = (taxable_value / 100.0)*2.5;
		if (quarterly_payements){
			payment = tax_amount / 4.0;
		}
		else{
			payment = tax_amount;
		}

		//Formatting of output
		int width = 30;
		std::cout << std::setprecision(2) << std::setw(width) << std::fixed;
		std::cout << std::left << std::setw(width) << "Value of property: " << std::right << std::setw(width) << '$' << property_value << '\n';
		std::cout << std::left << std::setw(width) << "Taxable portion: " << std::right << std::setw(width) << '$' << property_value*0.6 << '\n';
		std::cout << std::left << std::setw(width) << "Senior citizen: " << std::right << std::setw(width) << (senior_citizen ? 'Y' : 'N') << '\n';
		if (senior_citizen){
			std::cout << std::left << std::setw(width) << "Senior citizen exemption: " << std::right << std::setw(width) << '$' << property_value*0.6*0.1 << '\n';
		}
		std::cout << std::left << std::setw(width) << "Net taxable portion: " << std::right << std::setw(width) << '$' << taxable_value << '\n';
		std::cout << std::left << std::setw(width) << "Tax amount: " << std::right << std::setw(width) << '$' << tax_amount << '\n';
		std::cout << std::left << std::setw(width) << "Number of payments: " << std::right << std::setw(width) << (quarterly_payements ? '4' : '1') << '\n';
		if (quarterly_payements){
			std::cout << std::left << std::setw(width) << "Quarterly payment: " << std::right << std::setw(width) << '$' << payment << '\n';
		}
		std::cout << '\n';
	}


	std::cin.get();
	return 0;
}
