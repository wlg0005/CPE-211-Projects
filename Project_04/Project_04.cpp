// ****************************************
// Program Title: Project_04
// Project File: Project_04.cpp
// Name: Will Green
// Course Section: CPE-211-02
// Lab Section: 1
// Due Date: 09/13/20
// Program description:
// 
// The following program prompts the user for the name of an input file
// that contains values for the initial velocity (in m/s) and the starting
// angle (in degrees) of a projectile.
//
// The program then checks to make sure the input file is valid.
// If it is valid, the program continues, otherwise it terminates.
//
// The program reads values from the input file and stores them in initVelocity and initAngle.
// And then calculates and outputs 4 values: 1) Time to max height. 2) Time to max distance. 3) Max height and
// 4) Max distance. 
// ****************************************

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{	
	ifstream InFile; // Define file stream to read from file
	string inputFile; // string to store file name
	
	// Define constants
	const double PI = 3.14159265;
	const double G = 9.80665; // Gravity (m/s^2)
	
	// Define variables
	double initVelocity; // Initial velocity of projectile (m/s)
	double initAngle; // Initial angle of projectile (degrees)
	double maxHeightTime; // Time for projectile to reach maximum height
	double maxDistanceTime; // Time for projectile to hit ground
	double maxHeight; // Maximum height of projectile
	double maxDistance; // Distance travelled by projectile
	
	// Ask for user to input file name containing values for initVelocity and initAngle
	cout << endl << string(30,'*') << endl;
	cout << "***** Projectile Motion" << endl;
	cout << string(30,'*') << endl << endl;
	cout << "Enter the name of the input file: ";
	cin >> inputFile;
	cout << inputFile << endl << endl;
	
	// open input file
	InFile.open(inputFile.c_str());
	
	// Ensure file stream is valid (the input file exists)
	// Program terminates if file stream is invalid 
	if(InFile.fail())
	{
		cout << string(47,'*') << endl;
		cout << "==> Input file failed to open properly!\n";
		cout << "==> Name of file opened: " << inputFile << endl;
		cout << "==> Terminating program!!!\n";
		cout << string(47,'*') << endl;
		return 1;
	}
	
	// Read input file and store corresponding values in initVelocity and initAngle
	InFile >> initVelocity >> initAngle;
	
	// Output starting values
	cout << "Initial Velocity(in m/s): " << initVelocity << endl << endl;
	cout << "Starting angle(in degrees): " << initAngle << endl << endl;
	
	// Perform Calculations
	// Convert initAngle to radians to be used for formulas.
	initAngle = initAngle*PI/180;

	// Time to reach maximum height calculation
	maxHeightTime = (initVelocity * sin(initAngle)) / G;

	// Time to reach maximum distance calculation
	maxDistanceTime = (2 * initVelocity * sin(initAngle)) / G;

	// Maximum height calculation
	maxHeight = (pow(initVelocity,2) * pow(sin(initAngle),2)) / (2*G);

	// Maximum distance calculation 	
	maxDistance = initVelocity * maxDistanceTime * cos(initAngle);	
	
	// Output manipulators to ensure values display three decimal places.
	cout << fixed << setprecision(3);
	
	// Output calculations
	cout << "Results:" << endl << "--------" << endl;
	cout << left << setw(25) << "Time to max height:" << maxHeightTime << " seconds" << endl;
	cout << left << setw(25) << "Time to max distance:" << maxDistanceTime << " seconds" << endl;
	cout << left << setw(25) << "Maximum height:" << maxHeight << " meters" << endl;
	cout << left << setw(25) << "Maximum distance:" << maxDistance << " meters" << endl << endl;

	return 0;
}
