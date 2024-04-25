#include <iostream>
#include <sstream>
#include <fstream>
#include "String.h"

void RunFunctionSelection();
int RunStringFunctionTests();
void PrintFunctionList();

int main() {
	RunStringFunctionTests();

	// Extra stuffff.
	//RunFunctionSelection();

	return 0;
}

int RunStringFunctionTests() {
	bool resultLength, resultCharacterAt, resultEqualTo, resultAppend, resultPrepend, resultToLower, resultToUpper, resultFind, resultFindIndex, resultReplace;

	String workingString("Lorum ipsum!");
	

	// Test Length()
	resultLength = workingString.Length() == 12;

	// Test CharacterAt()
	resultCharacterAt = workingString.CharacterAt(7) == 'p';

	// Test EqualTo()
	resultEqualTo = workingString.EqualTo("Lorum ipsum!");

	// Test Append()
	resultAppend = workingString.Append("Appendment") == "Lorum ipsum!Appendment";
	workingString = "Lorum ipsum!";

	// Test Prepend()
	resultPrepend = workingString.Prepend("Prependment") == "PrependmentLorum ipsum!";
	workingString = "Lorum ipsum!";

	// Test ToLower()
	resultToLower = workingString.ToLower() == "lorum ipsum!";
	workingString = "Lorum ipsum!";

	// Test ToUpper()
	resultToUpper = workingString.ToUpper() == "LORUM IPSUM!";
	workingString = "Lorum ipsum!";

	// Test Find()
	resultFind = workingString.Find("rum") == 2;

	// Test Find() - From index
	resultFindIndex = workingString.Find(5, "sum") == 8;

	// Test Replace()
	workingString = "Lorum ipsum! Lorum ipsum!";
	resultReplace = workingString.Replace("rum", "replacement") == "Loreplacement ipsum! Loreplacement ipsum!";
	workingString = "Lorum ipsum!";


	// Print results to console.
	std::cout << "Test Results:" << std::endl;
	std::cout << (resultLength ? "Successful: Test Length()" : "Failed: Test Length()") << std::endl;
	std::cout << (resultCharacterAt ? "Successful: Test CharacterAt()" : "Failed: Test CharacterAt()") << std::endl;
	std::cout << (resultEqualTo ? "Successful: Test EqualTo()" : "Failed: Test EqualTo()") << std::endl;
	std::cout << (resultAppend ? "Successful: Test Append()" : "Failed: Test Append()") << std::endl;
	std::cout << (resultPrepend ? "Successful: Test Prepend()" : "Failed: Test Prepend()") << std::endl;
	std::cout << (resultToLower ? "Successful: Test ToLower()" : "Failed: Test ToLower()") << std::endl;
	std::cout << (resultToUpper ? "Successful: Test ToUpper()" : "Failed: Test ToUpper()") << std::endl;
	std::cout << (resultFind ? "Successful: Test Find()" : "Failed: Test Find()") << std::endl;
	std::cout << (resultFindIndex ? "Successful: Test Find() (from index)" : "Failed: Test Find() (from index)") << std::endl;
	std::cout << (resultReplace ? "Successful: Test Replace()" : "Failed: Test Replace()") << std::endl;
	std::cout << std::endl;


	// Store results to file.
	std::fstream testLog;

	testLog.open("stringfunctiontest.log", std::ios::in | std::ios::out | std::ios::app);

	// If the file is not open, return.
	if (testLog.is_open()) {
		// Get and print the current time into the log file.
		time_t now = time(0);
		char formattedTime[26];
		ctime_s(formattedTime, sizeof(formattedTime), &now);

		testLog << formattedTime;

		testLog << (resultLength ? "Successful: Test Length()" : "Failed: Test Length()") << std::endl;
		testLog << (resultCharacterAt ? "Successful: Test CharacterAt()" : "Failed: Test CharacterAt()") << std::endl;
		testLog << (resultEqualTo ? "Successful: Test EqualTo()" : "Failed: Test EqualTo()") << std::endl;
		testLog << (resultAppend ? "Successful: Test Append()" : "Failed: Test Append()") << std::endl;
		testLog << (resultPrepend ? "Successful: Test Prepend()" : "Failed: Test Prepend()") << std::endl;
		testLog << (resultToLower ? "Successful: Test ToLower()" : "Failed: Test ToLower()") << std::endl;
		testLog << (resultToUpper ? "Successful: Test ToUpper()" : "Failed: Test ToUpper()") << std::endl;
		testLog << (resultFind ? "Successful: Test Find()" : "Failed: Test Find()") << std::endl;
		testLog << (resultFindIndex ? "Successful: Test Find() (from index)" : "Failed: Test Find() (from index)") << std::endl;
		testLog << (resultReplace ? "Successful: Test Replace()" : "Failed: Test Replace()") << std::endl;

		testLog << std::endl;

		testLog.close();

		std::cout << "Results saved to stringfunctiontest.log" << std::endl << std::endl;
	}
	else {
		std::cout << "Unable to print test results to log!" << std::endl << std::endl;
	}

	system("pause");

	return 0;
}

void RunFunctionSelection() {
	String workingString("");

GetInput:
	PrintFunctionList();

	// Create new String object and collect user input.
	String consoleInput;
	consoleInput.ReadFromConsole();

	// Convert string to int.
	std::stringstream stream(consoleInput.CStr());
	int streamValue;
	stream >> streamValue;

	// Run function depending on ID from user.
	switch (streamValue) {
		// Set the workingString to input from the console.
		case 1: {
			std::cout << "Please enter the text for the new String to contain:" << std::endl;
			workingString.ReadFromConsole();

			std::cout << "New String object created with contents: " << workingString.CStr() << std::endl << std::endl;
			break;
		}
		case 2: {
			std::cout << "Memory reference: " << (void*)workingString.CStr() << std::endl << std::endl;
			break;
		}
		case 3: {
			std::cout << "String length: " << workingString.Length() << std::endl << std::endl;
			break;
		}
		case 4: {
			std::cout << "Please enter the index to search:" << std::endl;
			consoleInput.ReadFromConsole();
			stream.clear();
			stream.str(consoleInput.CStr());
			stream >> streamValue;

			std::cout << "Character at index " << streamValue << " is " << workingString.CharacterAt(streamValue) << std::endl << std::endl;
			break;
		}
		case 5: {
			std::cout << "Please enter a string to compare against:" << std::endl;
			consoleInput.ReadFromConsole();

			if (workingString.EqualTo(consoleInput)) {
				std::cout << "Strings are equal!" << std::endl << std::endl;
			}
			else {
				std::cout << "Strings are not equal!" << std::endl << std::endl;
			}
			break;
		}
		case 6: {
			std::cout << "Please enter a string to append:" << std::endl;
			consoleInput.ReadFromConsole();

			workingString.Append(consoleInput);
			std::cout << "New string: " << workingString.CStr() << std::endl << std::endl;
			break;
		}
		case 7: {
			std::cout << "Please enter a string to prepend:" << std::endl;
			consoleInput.ReadFromConsole();

			workingString.Prepend(consoleInput);
			std::cout << "New string: " << workingString.CStr() << std::endl << std::endl;
			break;
		}
		case 8: {
			workingString.ToLower();
			std::cout << "Complete: " << workingString.CStr() << std::endl << std::endl;
			break;
		}
		case 9: {
			workingString.ToUpper();
			std::cout << "Complete: " << workingString.CStr() << std::endl << std::endl;
			break;
		}
		case 10: {
			std::cout << "Please enter a string to search for:" << std::endl;
			consoleInput.ReadFromConsole();
			
			size_t index = workingString.Find(consoleInput);
			if (index != SIZE_MAX) {
				std::cout << "Substring found at index " << index << std::endl << std::endl;
			}
			else {
				std::cout << "Substring not found..." << std::endl << std::endl;
			}
			break;
		}
		case 11: {
			std::cout << "Please enter a string to search for:" << std::endl;
			String substring = consoleInput.ReadFromConsole();
			std::cout << "Please enter a index to start from:" << std::endl;
			consoleInput.ReadFromConsole();
			stream.clear();
			stream.str(consoleInput.CStr());
			stream >> streamValue;
			int startIndex = streamValue;

			size_t index = workingString.Find(startIndex, substring);
			if (index != SIZE_MAX) {
				std::cout << "Substring found at index " << index << std::endl << std::endl;
			}
			else {
				std::cout << "Substring not found..." << std::endl << std::endl;
			}
			break;
		}
		case 12: {
			std::cout << "Please enter a string to find in the original string:" << std::endl;
			String searchString = consoleInput.ReadFromConsole();
			std::cout << "Please enter a string to replace with:" << std::endl;
			String replaceString = consoleInput.ReadFromConsole();

			workingString.Replace(searchString, replaceString);
			std::cout << "Complete: " << workingString.CStr() << std::endl << std::endl;
			break;
		}
		case 13: {
			workingString.WriteToConsole();
			std::cout << std::endl;
			break;
		}
		default: {
			std::cout << "\nError: Function doesn't exist!" << std::endl;
		}
	}
	goto GetInput;
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
	std::cout << "(10) Find substring index" << std::endl;
	std::cout << "(11) Find substring index starting from index" << std::endl;
	std::cout << "(12) Replace substring" << std::endl;
	std::cout << "(13) Write stored string to console" << std::endl;
	std::cout << "------------------------------------------------------\n" << std::endl;
}