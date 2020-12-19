// ****************************************
// Program Title: Project_05
// Project File: Project_05.cpp
// Name: Will Green
// Course Section: CPE-211-02
// Lab Section: 1
// Due Date: 09/27/20
// program description:
// This program reads three numbers from an input file, that are placed after the characters
// A, B, and C. It then finds the sum and average of the numbers, and writes the values to
// an output file. It handles errors for invalid input/output file and invalid command line arguments.
// ****************************************
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[ ])
{	
	if (argc != 3) {
		cout << endl << string(9,'*') << " Command Line Argument Error " << string(9,'*') << endl;
		cout << "==> Incorrect number of Command Line Arguments!\n";
		cout << "==> Command for running the program is:\n";
		cout << "==> ./Project_05 inputFileName outputFileName\n";
		cout << string(47,'*') << endl << endl;
		return 1;
	}	

	ifstream InFile;
	string inputFile;

	ofstream OutFile;
	string outputFile;
	
	float num1;
	float num2;
	float num3;
	float sum;
	float avg;
	string avgRating;

	inputFile = argv[1];
	outputFile = argv[2];

	InFile.open(inputFile.c_str());
	cout << "\nOpening Input File: " << inputFile << endl;

	if(InFile.fail()) {
		cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
		cout << "==> Input file failed to open properly!!" << endl;
		cout << "==> Attempted to open file: " << inputFile << endl;
		cout << "==> Terminating program!!!" << endl;
		cout << string(47,'*') << endl << endl;
		return 1;
	}

	OutFile.open(outputFile.c_str());
	cout << "\nOpening Output File: " << outputFile << endl << endl;

	if (OutFile.fail()) {
		cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
		cout << "==> Output file failed to open properly!\n";
		cout << "==> Attempted to open file: " << outputFile << endl;
		cout << "==> Terminating the program!!!\n";
		cout << string(47,'*') << endl << endl;
		return 1;
	}

	InFile.ignore(256,'A');
	InFile >> num1;

	InFile.ignore(256,'B');
	InFile >> num2;

	InFile.ignore(256,'C');
	InFile >> num3;	
	
	InFile.close();

	if (num1 < 0 || num2 < 0 || num3 < 0) {
		cout << string(15,'*') << " Negative Number " << string(15,'*') << endl;

		if (num1 < 0) {
			cout << "==> First number is less than 0\n";
		}
	
		if (num2 < 0) {
			cout << "==> Second number is less than 0\n";	
		}

		if (num3 < 0) {
			cout << "==> Third number is less than 0\n";
		}
	
		cout << "==> All numbers should be positive\n";
		cout << "==> Terminating program!!!\n";
		cout << string(47,'*') << endl << endl;

		return 1;	
	}
	
	sum = num1 + num2 + num3;
	avg = sum / 3;

	OutFile << fixed << setprecision(2);	

	OutFile << string(47,'*') << endl;
	OutFile << left << setw(35) << "The numbers read are: " << num1 << " " << num2 << " " << num3 << endl;
	OutFile << left << setw(35) << "The sum of the numbers is: " << sum << endl;
	OutFile << left << setw(35) << "The average of these numbers is: " << avg << endl;
	
	if (avg >= 75) {
		avgRating = "High";
	} else if (avg < 75 && avg >= 25) {
		avgRating = "Medium";
	} else {
		avgRating = "Low";
	}	 	

	OutFile << left << setw(35) << "This average is: " << avgRating << endl;
	OutFile << string(47,'*') << endl; 
	OutFile.close();
	return 0;
}
