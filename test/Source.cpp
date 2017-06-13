//Daniel Wart
//Lab 5: lab 3 with file output
//CIS 22A

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>

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
			test_stream << "Invalid Input\n";
		}
	}
}

int main(){

	std::stringstream test_stream;

	//inputs
	double property_value;
	bool senior_citizen;
	bool quarterly_payments;
	int num_properties;
	std::string input;

	//processed
	double taxable_value;
	double tax_amount;
	double payment;

	//files
	std::ofstream log_file;
	log_file.open("property_tax.log");
	test_stream << "The following information will be written into property_tax.log";
	test_stream << "How many properties should be generated?\n";
	GetInput(std::cin, num_properties);

	for (int i = 0; i < num_properties; i++){
		test_stream << "What is the value of the property?\n";
		GetInput(std::cin, property_value);
		test_stream << "Is the owner a senior citizen?\n";
		std::getline(std::cin, input);
		senior_citizen = input.compare("Yes") == 0 ? true : false;

		if (senior_citizen){
			test_stream << "Is the payment quarterly or annually?\n";
			std::getline(std::cin, input);
			quarterly_payments = input.compare("Quarterly") == 0 ? true : false;
		}
		else{
			quarterly_payments = false;
		}
		test_stream << "\n";
		taxable_value = property_value*0.6;
		if (senior_citizen){
			taxable_value *= 0.9;
		}
		tax_amount = (taxable_value / 100.0)*2.5;
		if (quarterly_payments){
			payment = tax_amount / 4.0;
		}
		else{
			payment = tax_amount;
		}

		//Formatting of output
		int width = 30;
		test_stream << std::setprecision(2) << std::setw(width) << std::fixed;
		test_stream << std::left << std::setw(width) << "Value of property: " << std::right << std::setw(width) << '$' << property_value << '\n';
		test_stream << std::left << std::setw(width) << "Taxable portion: " << std::right << std::setw(width) << '$' << property_value*0.6 << '\n';
		test_stream << std::left << std::setw(width) << "Senior citizen: " << std::right << std::setw(width) << (senior_citizen ? 'Y' : 'N') << '\n';
		if (senior_citizen){
			test_stream << std::left << std::setw(width) << "Senior citizen exemption: " << std::right << std::setw(width) << '$' << property_value*0.6*0.1 << '\n';
		}
		test_stream << std::left << std::setw(width) << "Net taxable portion: " << std::right << std::setw(width) << '$' << taxable_value << '\n';
		test_stream << std::left << std::setw(width) << "Tax amount: " << std::right << std::setw(width) << '$' << tax_amount << '\n';
		test_stream << std::left << std::setw(width) << "Number of payments: " << std::right << std::setw(width) << (quarterly_payments ? '4' : '1') << '\n';
		if (quarterly_payments){
			test_stream << std::left << std::setw(width) << "Quarterly payment: " << std::right << std::setw(width) << '$' << payment << '\n';
		}
		test_stream << '\n';
	}
	log_file << test_stream.rdbuf();
	log_file.close();
	std::cin.get();
	return 0;
}
