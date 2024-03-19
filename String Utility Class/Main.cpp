#include <iostream>
#include <sstream>
#include "String.h"

void PrintFunctionList();

int main() {
	String workingString;

	PrintFunctionList();

	// Create new String object and collect user input.
	String consoleInput;
	consoleInput.ReadFromConsole();
	
	// Convert string to int.
	std::stringstream stream(consoleInput.CStr());
	int functionID;
	stream >> functionID;

	// Run function depending on ID from user.
	switch (functionID) {
		// Set the workingString to input from the console.
		case 1: {
			std::cout << "\nPlease enter the text for the new String to contain:" << std::endl;
			workingString.ReadFromConsole();

			std::cout << "New String object created with contents: " << workingString.CStr() << std::endl;
			break;
		}
		default: {

			std::cout << "\nError: Function doesn't exist!" << std::endl;
			return -1;
		}
	}

	return 0;
}

void PrintFunctionList() {
	std::cout << "------- Please select a function below to run. -------" << std::endl;
	std::cout << "(1) Create new String object" << std::endl;
	std::cout << "(2) Get String memory reference" << std::endl;
	std::cout << "(3) Get string length" << std::endl;
	std::cout << "(4) Get character at index" << std::endl;
	std::cout << "(5) Check if string is equal to other String object" << std::endl;
	std::cout << "(6) Append to string" << std::endl;
	std::cout << "(7) Prepend to string" << std::endl;
	std::cout << "(8) Make string lower case" << std::endl;
	std::cout << "(9) Make string upper case" << std::endl;
	std::cout << "(10) Find substring" << std::endl;
	std::cout << "(11) Find substring starting from index" << std::endl;
	std::cout << "(12) Replace substring" << std::endl;
	std::cout << "(13) Set string from console input" << std::endl;
	std::cout << "(14) Write stored string to console" << std::endl;
	std::cout << "------------------------------------------------------\n" << std::endl;
}