// ****************************************
// Program Title: Project_07
// Project File: Project_07.cpp
// Name: Will Green
// Course Section: CPE-211-02
// Lab Section: 1
// Due Date: 10/22/20
// program description:
// 
// The following program has functions for the following tasks:
// 1.) Approximating pi using the Monte Carlo Method
// 2.) Simulating the odds of a coin being flipped
// 3.) Simulating the odds of a five-sided dice being rolled.
//
// It prompts the user to input a seed
// which is the starting point for the random number generator.
// And then outputs a menu and takes input for the users choice.
// Based off the users choice, it performs one of the functions 
// above. This continues until the user chooses the exit option.
//
// It handles invalid input errors for integers and characters.
// ****************************************

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <string>

using namespace std;

void menu(); // print out the menu
int obtainInteger(); // obtain an integer to be used as menu choice
void approxPI(); // approximate pi using the monte carlo method
void coinOdds(); // simulate the odds of flipping a coin
void dieOdds(); // simulate the odds of rolling a five-sided dice

int main() {

	int seed; // seed for random number generator
	int choice; // menu choice

	// Setup the random number generator starting point by obtaining a seed
	cout << endl << "Enter in the seed(integer > 0) for the random number generator: ";
	cin >> seed;
	cout << seed << endl; // echo print out the value entered
	srand(seed); // use the seed entered to initialize the generator

	do {
		menu(); // print menu
		choice = obtainInteger(); // obtain an integer and store in choice variable
		
		switch(choice) { // depending on the value of choice
			case 1:
				approxPI(); // approximate pi using monte carlo method
				break;
			case 2:
				coinOdds(); // simulate the odds of flipping a coin
				break;
			case 3:
				dieOdds(); // simulate the odds of rolling a five-sided dice
				break;
			case 4:
				break; // exit the program
			default:
				// invalid integer supplied for choice
				cout << endl << string(15,'*') << " Invalid Integer " << string(15,'*') << endl;
				cout << "==> Invalid integer entered.\n";
				cout << "==> Please try again...\n";
				cout << string(47,'*') << endl;
				break;
		}
	} while(choice != 4); // terminate loop when user chooses to exit

	cout << "\nExit selected. Exiting the program now...\n\n";

	return 0;
}

// print out the menu
void menu() {
				
	cout << endl << string(24,'*') << endl;
	cout << string(5,'*') << " Menu Options " << string(5,'*') << endl;
	cout << string(24,'*') << endl;
	cout << "1) Approximate PI\n";
	cout << "2) Flip a fair coin\n";
	cout << "3) Toss a fair 5-sided die\n";
	cout << "4) Exit\n";
	cout << string(24,'*') << endl << endl;
}

// obtain and integer and handle invalid character errors
int obtainInteger() {
	
	int integer; // integer corresponding to a menu choice
	char invalidChar;
	
	// take input for their choice 
	cout << "Enter your choice: ";
	cin >> integer;

	while(cin.fail()) {
		
		cin.clear(); // reset file stream
		cin.ignore(numeric_limits<streamsize>::max(),'\n'); // remove any remaining info in the input stream
		
		// print error message
		cout << endl << string(14,'*') << " Invalid Character " << string(14,'*') << endl;
		cout << "==> Invalid character(s) entered.\n";
		cout << "==> Please try again...\n";
		cout << string(47,'*') << endl;
		
		menu(); // print menu 
		cout << "Enter your choice: "; // ask for input again
		cin >> integer;
	}

	cout << integer << endl; // echo print
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); // ensure file stream is empty
	return integer; // return the integer (choice)
		
}

// Monte Carlo Method for finding PI
void approxPI() {
	int iter; // number of iterations
	double x,y,position; // x,y and position of coordinate relative to circle
	int count; // number of times the position falls within circle
	double pi; // value to hold our estimate of pi

	// take input for number of iterations
	cout << "\nMonte Carlo Method for finding PI has been selected\n\n";
	cout << "Number of iterations: ";
	cin >> iter;
	cout << iter << endl << endl; // echo print
	
	count = 0; // set count to 0

	// for a specified number of iterations
	for(int i=0; i < iter; i++) {

		// calculate a x and y value that are between 0 and 1
		x = double(rand()) / double(RAND_MAX);
		y = double(rand()) / double(RAND_MAX);

		// calculate position of x,y relative to circle
		position = sqrt(pow(x,2) + pow(y,2));
		
		// if the position falls within the circle, increment by 1
		if(position <= 1) {
			count++;
		}		
	}
	
	// since the area of the circle divided by the area of the box is PI/4
	// we multiply by 4 to get our estimate of pi	
	pi = (double)count / iter*4;

	// output
	cout << fixed << setprecision(6);
	cout << string(10,'*') << " Option 1: Calculating PI " << string(10,'*') << endl;
	cout << "For " << iter << " iterations, pi is about " << pi << endl;
	cout << string(46,'*') << endl;			
}

// Simulate the odds of flipping a coin
void coinOdds() {

	int numFlips; // number of coin flips to perform
	double flip; // value of flip
	int headsCount, tailsCount; // number of heads and number of tails
	double headsPercentage, tailsPercentage; // percentage of heads and percentage of tails
	
	// take input for how many times to flip coin
	cout << "\nFlipping of a fair coin has been selected\n\n";
	cout << "How many flips of the coin? ";
	cin >> numFlips;
	cout << numFlips << endl << endl;

	// set counts to 0
	headsCount = tailsCount = 0;
	
	// for a specified number of flips
	for(int i=0; i < numFlips; i++) {
		
		// generate a number between 0 and 1
		flip = double(rand()) / double(RAND_MAX);
		
		// increment heads or tails count based off flip value
		if(flip <= 0.5) {
			tailsCount++;
		} else if(flip > 0.5) {
			headsCount++;
		}
	}
	
	// calculate percentages
	headsPercentage = ((double)headsCount / numFlips) * 100;
	tailsPercentage = ((double)tailsCount / numFlips) * 100;
	
	// output
	cout << fixed << setprecision(4);
	cout << string(10,'*') << " Option 2: Flipping a Coin " << string(10,'*') << endl;
	cout << "For " << numFlips << " flips of a fair coin:\n";
	cout << "Heads percentage: " << headsPercentage << endl;
	cout << "Tails percentage: " << tailsPercentage << endl;
	cout << string(47,'*') << endl;
}

// Simulate the odds of rolling a five-sided dice
void dieOdds() {

	int numRolls; // number of dice rolls to perform
	double roll; // the value of the roll
	int side1Count, side2Count, side3Count, side4Count, side5Count; // number of times each side appears
	double side1Pcent, side2Pcent, side3Pcent, side4Pcent, side5Pcent; // percentage each side appears

	// take input for number of dice rolls to perform	
	cout << "\nTossing of a fair 5-sided die has been selected\n\n";
	cout << "How many times do you want to roll the die? ";
	cin >> numRolls;
	cout << numRolls << endl << endl; // echo print

	// set count values to 0
	side1Count = side2Count = side3Count = side4Count = side5Count = 0;
	
	// for a specified amount of rolls
	for(int i=0; i < numRolls; i++) {
		
		roll = double(rand()) / double(RAND_MAX); // calculate a number between 0 and 1
		
		// increment count for a specific side depending on the value of the roll
		if(roll < 0.2) {
			side1Count++;
		} else if(roll >= 0.2 && roll < 0.4) {
			side2Count++;
		} else if(roll >= 0.4 && roll < 0.6) {
			side3Count++;
		} else if(roll >= 0.6 && roll < 0.8) {
			side4Count++;
		} else if(roll >= 0.8) {
			side5Count++;
		}
	}
	
	// Calculate percentages
	side1Pcent = ((double)side1Count / numRolls) * 100;
	side2Pcent = ((double)side2Count / numRolls) * 100;
	side3Pcent = ((double)side3Count / numRolls) * 100;
	side4Pcent = ((double)side4Count / numRolls) * 100;
	side5Pcent = ((double)side5Count / numRolls) * 100;

	// Output
	cout << fixed << setprecision(4);
	cout << string(10,'*') << " Option 3: Tossing a Die " << string(10,'*') << endl;
	cout << "For " << numRolls << " rolls of a fair die:\n";
	cout << "Side 1 percentage: " << side1Pcent << endl;
	cout << "Side 2 percentage: " << side2Pcent << endl;
	cout << "Side 3 percentage: " << side3Pcent << endl;
	cout << "Side 4 percentage: " << side4Pcent << endl;
	cout << "Side 5 percentage: " << side5Pcent << endl;
	cout << string(45,'*') << endl;
}
