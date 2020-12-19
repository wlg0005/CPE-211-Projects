// ****************************************
// Program Title: Project_06
// Project File: Project_06.cpp
// Name: Will Green
// Course Section: CPE-211-02
// Lab Section: 1
// Due Date: 10/06/20
// program description:
// This program takes user input for a file name
// and reads every character including tabs, spaces, and newlines
// 
// It counts the number of characters on a line that are letters,
// the number of characters on a line that are digits,
// and the number of other characters that are neither a letter or digit.
// 
// It then outputs on a line by line basis with the statistics,
// and includes total percentages of each type at the end.
//
// It provides error handling for files that fail to open
// and files that are empty.
//
// If a file fails to open, it loops until a valid file is provided.
// ****************************************
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>

using namespace std;

int main()
{
	ifstream InFile;
	string inputFile;
	int fileLength;

	int letterLineCount; // number of letters on a line
	int letterTotal; // total number of letters in the entire file
	float letterPercent; // percentage of characters that are letters

	int digitLineCount; // number of digits on a line
	int digitTotal; // total number of digits in the entire file
	float digitPercent; // percentage of characters that are digits

	int otherLineCount; // number of characters on a line that aren't a letter or digit
	int otherTotal; // total number of other characters
	float otherPercent; // percentage of other characters

	int lineNum; // keep track of which line we're on
	int lineTotal; // total number of characters on a line
	int total; // total number of characters in the entire file

	// Take input and attempt to open the file 	
	cout << "\nEnter in the name of the input file: ";
	cin >> inputFile;
	cout << inputFile << endl << endl;	
	
	InFile.open(inputFile.c_str());
	
	// If the file fails to open
	if(InFile.fail()) { 
		// Loop until a valid file is provided	
		while(InFile.fail()) {
			cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
			cout << "==> Input file failed to open properly!\n";
			cout << "==> Attempted to open file: " << inputFile << endl;
			cout << "==> Please try again...\n";
			cout << string(47,'*') << endl << endl;
			InFile.clear();
			cout << "Enter in the name of the input file: ";
			cin >> inputFile;
			cout << inputFile << endl << endl;
			
			InFile.open(inputFile.c_str());
		}
	}	
	
	// Check if file is empty
	InFile.seekg(0,ios::end); // Seek to the end of the file
	fileLength = InFile.tellg(); // Get the current position

	// If the length/current position is equal to 0 (i.e. the cursor didn't move)
	if(fileLength == 0) {
		// File is empty error
		cout << string(13,'*') << " Input File Is Empty " << string(13,'*') << endl;
		cout << "==> The input file is empty.\n";
		cout << "==> Terminating the program.\n";
		cout << string(47,'*') << endl << endl;
		
		return 1;
	}

	InFile.seekg(0); // If the fileLength isn't 0, then we return to the beginning and continue with the program.
	
	// Create header columns
	cout << left << setw(15) << "Line number" << setw(10) << setw(10) << "Letters" << setw(10) << "Digits" << setw(10) << "Other" << setw(10) << "Total" << endl;
	cout << left << setw(15) << "-----------" << setw(10) << setw(10) << "-------" << setw(10) << "------" << setw(10) << "-----" << setw(10) << "-----" << endl;
	
	letterTotal = digitTotal = otherTotal = total = 0; // start the totals at 0
	lineNum = 0; // start the number of lines at 0
	
	// for every line in the input file
	for(string line; getline(InFile,line);) {

		lineNum+=1; // increment the line number by 1
		line += '\n'; // since the getline() function removes all \n characters, we append them back
		letterLineCount = digitLineCount = otherLineCount = lineTotal = 0; // reset the line counts to 0 for each line
		
		// for every character on a line
		for(int i = 0; i < line.length(); i++) {
			
			// if the current character is a letter
			if(isalpha(line[i])) {
				// increment letter counts
				letterLineCount += 1; 
				letterTotal += 1;
			
			// if the current character is a digit
			} else if(isdigit(line[i])) {
				// increment digit counts
				digitLineCount += 1;
				digitTotal += 1;

			// if the current character is neither a letter or digit
			} else { 
				// increment other counts
				otherLineCount += 1;
				otherTotal += 1;
			}
	
		}
		
		lineTotal = letterLineCount + digitLineCount + otherLineCount; // add the totals of each type on a line to get the total characters on a line
		total += lineTotal; // add the line total to the complete total
		
		// output that is generated for each line
		cout << left << setw(15) << lineNum << setw(10) << letterLineCount << setw(10) << digitLineCount << setw(10) << otherLineCount << lineTotal << endl; 
	}

	// Calculate the percentage of each type of character
	letterPercent = ((float)letterTotal / total) * 100;
	digitPercent = ((float)digitTotal / total) * 100;
	otherPercent = ((float)otherTotal / total) * 100;
	
	// Output the totals and percents	
	cout << string(50,'-') << endl;
	cout << left << setw(15) << "Totals" << setw(10) << letterTotal << setw(10) << digitTotal << setw(10) << otherTotal << setw(10) << total << endl;
	cout << fixed << setprecision(2); 
	cout << left << setw(15) << "Percent" << setw(10) << letterPercent << setw(10) << digitPercent << setw(10) << otherPercent << endl << endl;	
	return 0;
}
