// ****************************************
// Program Title: Project_09 
// Project File: Project_09.cpp
// Name: Will Green
// Course Section: CPE-211-02
// Lab Section: 1
// Due Date: 11/19/20
// program description: 
//
// The following program takes an input file which contains
// the number of floating points in the file, and the subsequent
// float point numbers.
//
// 4 Functions are performed to perform the following statistics on the array:
//
// 1) Sort the array from least to greatest (Sort())
// 2) Calculate the average of the numbers in the array (Average())
// 3) Calculate the median of the numbers in the array (Median())
// 4) Calculate the variance of the numbers in the array (Variance())
//
// Error handling is in place for invalid input files, invalid characters
// in the input file, missing numbers in the input file, and no array size specified.
//
// Statistics of the array are outputted.
// ****************************************
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

// function prototypes
int OpenInput(ifstream &InFile);
void ReadInput(ifstream &InFile, float numbers[], int size);

void Sort(float numbers[], int size); // sort the array
float Average(float numbers[], int size); // calculate average of array
float Median(float numbers[], int size); // calculate median of array
float Variance(float numbers[], int size, float avg); // calculate variance of array

int main()
{
    const int MAX_ARR_SIZE = 50;
    int fileLength; // hold the return value of openInput (fileLength)
    int arrSize; // size of array
    float avg; // average of numbers in array
    float median; // median of numbers in array
    float var; // variance of numbers in array
    float sd; // standard deviation of numbers

    ifstream InFile; // define input file stream

    fileLength = OpenInput(InFile); // open the input file and store the length of the file

    // if the length returned from the OpenInput function is 0, output file is empty error
    if(fileLength == 0) {

        // file is empty error
        cout << string(15,'*') << " Empty Input File " << string(15,'*') << endl;
        cout << "==> Input file is empty.\n";
        cout << "==> Program terminated.\n";
        cout << string(48,'*') << endl << endl; 
        return 1;
    }

    InFile >> arrSize; // read in the first number (size of array)
    
    // if we're in the fail state after trying to read the first number, output error
    if(InFile.fail()) {
        cout << string(15,'*') << " File Read Error " << string(15,'*') << endl;
        cout << "==> Error occurred reading the number of values\n";
        cout << "==> present in the input file.\n";
        cout << "==> Program terminated.\n";
        cout << string(47,'*') << endl << endl;
    }

    float numbers[arrSize]; // define an array which has a size of the first number read

    ReadInput(InFile, numbers, arrSize); // read numbers from input file and store in numbers array
    
    Sort(numbers,arrSize); // sort the array

    avg = Average(numbers, arrSize); // calculate the average
    median = Median(numbers, arrSize); // calculae the median
    var = Variance(numbers, arrSize, avg); // calculate the variance
    sd = sqrt(var); // calculate the standard deviation 

    // if we're still not in the fail state, output    
    if (!InFile.fail()) { 
        cout << string(15,'*') << " File Statistics " << string(15,'*') << endl;
        cout << string(47,'*') << endl;
        cout << left << setw(25) << setfill('.') << "Number of Values" << arrSize << endl;
        cout << left << setw(25) << setfill('.') << "Average" << avg << endl;
        cout << left << setw(25) << setfill('.') << "Median" << median << endl;
        cout << left << setw(25) << setfill('.') << "Variance" << var << endl;
        cout << left << setw(25) << setfill('.') << "Standard Deviation" << sd << endl;
        cout << string(47,'*') << endl << endl;
    }

	return 0;
}

// -------------------------------------------------------------------------------------------
// Open the input file. Output error if invalid input file, loop until valid file is provided.
// -------------------------------------------------------------------------------------------
int OpenInput(ifstream &InFile) {

    string inputFile; // name of input file
    int fileLength; // store the length of the file to to later dermine if fily is empty

    // Get input for file name (inputFile)
    cout << endl << "Enter the name of the input file (ctrl-c to exit): ";
    cin >> inputFile;
    cout << inputFile << endl << endl;

    InFile.open(inputFile.c_str()); // open the input file

    // While the input file stream is in the fail state
    while(InFile.fail()) {

        // output error
        cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
        cout << "==> Input file could not be opened.\n";
        cout << "==> " << inputFile << " is an invalid file!!\n";
        cout << "==> Try Again.\n";
        cout << string(47,'*') << endl << endl;

        InFile.clear(); // clear the file stream

        // Get input for the file name again
        cout << "Enter the name of the input file (ctrl-c to exit): ";
        cin >> inputFile;
        cout << inputFile << endl;

        InFile.open(inputFile.c_str()); // open the input file
    }

    InFile.seekg(0,ios::end); // seek to the end of the file
    fileLength = InFile.tellg(); // get the current position of the cursor
    InFile.seekg(0); // seek back to the beginning of the file

    return fileLength; // return the fileLength to be used in the main function
}

// -------------------------------------------------------------------------------------------
// read input file and store numbers in array. Output errors and exit if invalid character or
// no number is provided.
// -------------------------------------------------------------------------------------------
void ReadInput(ifstream &InFile, float numbers[], int size) {
   
    // for each number in the input file
    for(int i = 0; i < size; i++) {

        InFile >> numbers[i]; // store the number in the numbers array

        // output errors if in the fail state
        if(InFile.fail() && (numbers[i] == 0)) {
            cout << string(15,'*') << " File Read Error " << string(15,'*') << endl;
            cout << "==> Error occurred reading in number #" << i+1 << endl;
            cout << "==> Invalid Character found in file.\n";
            cout << "==> Program terminated.\n";
            cout << string(47,'*') << endl << endl;
            return;
        } else if (InFile.fail()) {
            cout << string(15,'*') << " File Read Error " << string(15,'*') << endl;
            cout << "==> Error occurred trying to reading in number #" << i+1 << endl;
            cout << "==> Number was not present in the input file.\n";
            cout << "==> Program terminated.\n";
            cout << string(47,'*') << endl << endl; 
            return;
        } 
   } 
} 

// -------------------------------------------------------------------------------------------
// Sort the array using sort function provided in #include <algorithm>
// -------------------------------------------------------------------------------------------
void Sort(float numbers[], int size) {
    
    // sort the array
    float temp;

    for(int i = 0; i < size; i++) {

        for(int j = 0; j < size-i-1; j++) {

            if (numbers[j] > numbers[j+1]) {

                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    
}

// -------------------------------------------------------------------------------------------
// Calculate and return the average of the numbers in the array
// -------------------------------------------------------------------------------------------
float Average(float numbers[], int size) {

    float sum; // sum of the numbers in the array
    float avg; // average of the numbers in the array

    sum = 0; // set the sum to 0

    // for all the numbers in the array
    for(int i = 0; i < size; i++) {
        sum += numbers[i]; // add the number to sum
    }

    avg = sum / (float)size; // calculate the average

    return avg;
}

// -------------------------------------------------------------------------------------------
// Calculate and return the median of the numbers in the array
// -------------------------------------------------------------------------------------------
float Median(float numbers[], int size) {
 
    float median;

    // if there's an even amount of numbers
    if (size % 2 == 0) {
        median = (numbers[size / 2 - 1] + numbers[size / 2]) / 2; // calculate the median
    } else { // if there's an odd amount of numbers
        median = numbers[size / 2]; // calculate the median
    }
    
    return median; // return median
}

// -------------------------------------------------------------------------------------------
// Calculate and return the variance of the numbers in the array
// -------------------------------------------------------------------------------------------
float Variance(float numbers[], int size, float avg) {
 
    float sum; // sum of squared differences from the mean
    float var; // variance (sum / number of elements)

    sum = 0; // set sum to 0
    
    // for the entire array
    for(int i = 0; i < size; i++) {

        // calculate the squared differences from the mean and add to sum
        sum += (pow((numbers[i] - avg),2));   
    }
    
    var = sum / size; // calculate variance

    return var; // return variance
}
