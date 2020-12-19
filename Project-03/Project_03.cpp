// ****************************************
// Program Title: Project_03
// Project File: Project_03.cpp
// Name: Will Green
// Course Section: CPE-211-02
// Lab Section: 1
// Due Date: 09/04/20
// Description of Project_03:
//
// The following program takes input from the user for
// a starting balance, an interest rate, and the number of years
// to compound for. 
//
// It then calculates the balance after performing
// simple, monthly, daily, and continous interest. 
//
// It also calculates the effective interest rate for each compound type,
// which is the interest rate that achieves the same earnings as compound interest
// but can be used with the simple interest formula.
//
// Lastly, the program outputs all of the calculations to the user.
// ****************************************

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	// ------ Define variables ------
	double startingBalance;
	double interestRate;
	double years;
	
	double simpleInterest;
	double monthlyCompound;
	double dailyCompound;
	double continousCompound;
	
	double effRateMonthly;
	double effRateDaily;
	double effRateContinuous;
	
	double effRateBalanceMonthly;
	double effRateBalanceDaily;
	double effRateBalanceContinuous;
	
	// ------------------------------
	
	// ------ Take user input for variables and echo print value back ------
	cout << "Input the starting balance: ";
	cin >> startingBalance;
	cout << startingBalance << endl;
	
	cout << "Input the interest rate (Ex: 5 for 5%): ";
	cin >> interestRate;
	cout << interestRate << endl;
	
	cout << "Input the number of years: ";
	cin >> years;
	cout << years << endl << endl;
	
	cout<<setprecision(2)<<fixed; // Set precision of 2 to all double values
	
	// Output reiterating what was inputted
	cout << "For a principle of $" << startingBalance << endl;
	cout << "at an interest rate of " << interestRate << "%" << endl;
	cout << "for a period of " << years << " years," << endl;
	cout << "the final account balance would be: " << endl << endl;
	
	interestRate = interestRate / 100; // Convert interestRate into a decimal to be used for formulas.
	
	// ------------------------------------------------------------------------
	
	// ------ Perform calculations ------
	
	// Simple interest calculations
	simpleInterest = startingBalance * (1 + (years * interestRate)); // Balance after performing simple interest
	
	// Monthly compound calculations
	monthlyCompound = startingBalance * (pow(1 + (interestRate / 12),12*years)); // Balance after compounding monthly
	effRateMonthly = (pow(1 + (interestRate / 12),years*12) - 1)/years; // Effective interest rate for compounding monthly
	effRateBalanceMonthly = startingBalance * (1+(years*effRateMonthly)); // Balance using simple interest formula with effective interest rate
	
	// Daily compound calculations
	dailyCompound = startingBalance * (pow(1 + (interestRate / 365),365*years)); // Balance after compounding daily
	effRateDaily = (pow(1 + (interestRate / 365),years*365) - 1)/years; // Effective interest rate for compounding daily
	effRateBalanceDaily = startingBalance * (1+(years*effRateDaily)); // Balance using simple interest formula with effective interest rate
	
	// Continuous compound calculations
	continousCompound = startingBalance * pow(exp(1),interestRate * years); // Balance after compounding continuously
	effRateContinuous = (pow(exp(1),interestRate*years) - 1) / years; // Effective interest rate for compounding continuously
	effRateBalanceContinuous = startingBalance * (1+years*effRateContinuous); // Balance using simple interest formula with effective interest rate
	
	// ------------------------------
	
	// ------ Output ------ 
	// Simple Interest output
	cout << "Simple Interest:" << endl;
	cout << "\tBalance = $" << simpleInterest << endl << endl;
	
	// Monthly compound output
	cout << "Compounded Monthly:" << endl;
	cout << "\tBalance = $" << monthlyCompound << endl;
	cout << "\tThe Effective Simple Interest Rate: " << effRateMonthly*100 << "%" << endl;
	cout << "\tBalance using Simple Interest at the Effective Rate = $" << effRateBalanceMonthly << endl << endl;
	
	// Daily compound output
	cout << "Compounded Daily:" << endl;
	cout << "\tBalance = $" << dailyCompound << endl;
	cout << "\tThe Effective Simple Interest Rate: " << effRateDaily*100 << "%" << endl;
	cout << "\tBalance using Simple Interest at the Effective Rate = $" << effRateBalanceDaily << endl << endl;
	
	// Continuously compound output
	cout << "Compounded Continuously:" << endl; 
	cout << "\tBalance = $" << continousCompound << endl;
	cout << "\tThe Effective Simple Interest Rate: " << effRateContinuous*100 << "%" << endl;
	cout << "\tBalance using Simple Interest at the Effective Rate = $" << effRateBalanceContinuous << endl;
	
	// ------------------
	return 0;
}
