#include <iostream>
#include "Header.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
using namespace std;

const std::string file = "CS210_Project_Three_Input_File.txt";
/*
* 4 menu options
* option one is to Prompt a user to input the item, or word, they wish to look for. Return a numeric value for the frequency of the specific word.
* option two is Print the list with numbers that represent the frequency of all items purchased.
The screen output should include every item (represented by a word) 
paired with the number of times that item appears in the input file, 
CS210_Project_Three_Input_File.txt.
* option three is to print the same words as in option two but in a histogram using asterisks
* option four is to quit
*/

void WordProcessor::wordCounter(const string& file) {
	//open file
	ifstream inputFile(file);
	//word counting
	string word;
	while (inputFile >> word) {
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		++wordCount[word];
	}
	inputFile.close();
}

void WordProcessor::displayUserInputCount() const{
	string userWord;
	//loop for input
	while (true) {
		cout << "Enter produce to check its frequency. Or type 'exit' to return to the menu." << endl;
		cin >> userWord;
		//exit loop
		if (userWord == "exit") {
			menuOptions();
			break;
		}

		transform(userWord.begin(), userWord.end(), userWord.begin(), ::tolower);

		auto it = wordCount.find(userWord); 
		if (it != wordCount.end()) {
			cout << userWord << " " << it->second << endl; // user input checked agains map
		}
		else {
			cout << userWord << " does not exist in the file." << endl; // input validation???
		}
	}

}

void WordProcessor::displayHistCount() const {
	for (const auto& pair : wordCount) {// loop iterates through words
		cout << pair.first; // outputs word
		for (int i = 0; i < pair.second; i++) {// iterates through values
			cout << " *"; // asterisks for values
		}
		cout << endl;
	}
	menuOptions(); // return to menu
}

void WordProcessor::displayIntCount() const {
	for (const auto& pair : wordCount) { //displays count for all produce
		cout << pair.first << " " << pair.second << endl;
	}
	menuOptions();// return to menu
}

void WordProcessor::menuOptions() const {
	int choice;

	cout << "*** Corner Grocer ***" << endl;
	cout << "1: Check Frquency of Chosen Item" << endl;
	cout << "2: Show Frequency of all Items" << endl;
	cout << "3: Show Frequency of all Items using a Histogram" << endl;
	cout << "4: Exit" << endl;
	cin >> choice;
	
	switch (choice) {// nice little switch for the menu
	case 1:
		displayUserInputCount();
		break;
	case 2:
		displayIntCount();
		break;
	case 3:
		displayHistCount();
		break;
	case 4:
		return;
	default:
		cout << "Invalid choice. Please enter a number 1-4." << endl;
		break;
	}
}

void WordProcessor::dataBackup(const string& outputFile){
	ofstream outFile(outputFile);

	for (const auto& pair : wordCount) {
		outFile << pair.first << " " << pair.second << endl;//writing to the outfile
	}

	outFile.close();
	cout << "Backup written to '" << outputFile << "' on program start." << endl;// confirmation 
}
