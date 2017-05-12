/*
CIS 22A
Lab 1B: Formatted list of cities
Name: Daniel Wart
*/
//Data from https://en.wikipedia.org/w/index.php?title=List_of_United_States_cities_by_population&oldid=695421625
#include <iostream>
#include <iomanip>
#include <string>

int main(){

	const int COLUMNS = 8;
	const int ROWS = 5;
	const int COLUMN_WIDTHS[COLUMNS] = { 5, 13, 6, 14, 12, 7, 10, 12 }; //Allows variable column width

	std::string titles[COLUMNS] = { "Rank", "Name", "State", "2014 estimate", "2010 Census", "Change", "2014 area", "2010 density" };
	std::string data[ROWS][COLUMNS] = {
		{ "1", "New York", "NY", "8,491,079", "8,175,133", "+3.86%", "302.6", "27,012" },
		{ "2", "Los Angeles", "CA", "3,928,864", "3,792,621", "+3.59%", "468.7", "8,092" },
		{ "3", "Chicago", "IL", "2,722,389", "2,695,598", "+0.99%", "227.6", "11,842" },
		{ "4", "Houston", "TX", "2,239,558", "2,100,263", "+6.63%", "599.6", "3,501" },
		{ "5", "Philadelphia", "PA", "1,560,297", "1,526,006", "+2.25%", "134.1", "11,379" }
	};

	std::cout << "List of cities in the United States sorted by population\n";
	std::cout << "Area is in square miles, density is in people per square miles\n\n";
	std::cout << std::left; //Left align following text

	//Output titles
	for (int i = 0; i < COLUMNS; i++){
		std::cout << std::setw(COLUMN_WIDTHS[i]) << titles[i]; 
	}
	std::cout << "\n";

	//Output data from table
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
			std::cout << std::setw(COLUMN_WIDTHS[j]) << data[i][j];
		}
		std::cout << "\n";
	}
	std::cin.get();
	return 0;
}

