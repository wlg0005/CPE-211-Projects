// ****************************************
// Program Title: Project_08 
// Project File: Project_08.cpp 
// Name: Will Green
// Course Section: CPE-211-02
// Lab Section: 1
// Due Date: 11/03/20
// program description:
// 
// The following program uses structures to process an input file which contains
// records of subscriber information for a magazine and determines whether any
// of the subscribers subscriptions has expired.
//
// There are 4 functions at work. The first function (OpenInput) simply opens the input 
// file and handles any errors related to opening it. The second function (OpenOutput) does
// the same thing but for an Output file that the user chooses.
//
// Then there is a function that processes the input file and stores
// the values into the correct structure members and returns each customer structure.
//
// In the main function, we determine how many subscribers are processed, how many
// have expired subscriptions, and if there are any that are expired, we output
// that customers information using the OutputExpired() function.
//
// ****************************************
#include <iostream>
#include <fstream>
#include <climits>
#include <string>
using namespace std;

// Hierarchical structure
struct SubscriberName {
	string first;
	string last;
	int ID;
};

struct Address {
	string street;
	string city;
	string state;
	int zip;
};

struct Date {
	string month;
	int day;
	int year;
};

struct RenewalInfo {
	int monthsLeft;
	Date lastNotice;
};

struct CustomerRecord {
    SubscriberName name;
    Address address;
    RenewalInfo renewalInfo;
};

// function prototypes
int OpenInput(ifstream &InFile);
void OpenOutput(ofstream &OutFile);

CustomerRecord ProcessInput(ifstream &InFile);
void OutputExpired(ofstream &OutFile, CustomerRecord customer);

// --------------------------------------------------------------------------------------------------

int main()
{
	int length; // hold the return value of openInput (fileLength)
    
    int numSubscribers; // number of subscribers processed in input file
    int numExpired; // number of expired subscribers in input file
    
    bool isExpired; // boolean for if the processed subscriber subscription has expired

	ifstream InFile; // input file stream
	ofstream OutFile; // output file stream
	
    //CustomerRecord* customer = new CustomerRecord(); // define CustomerRecord structure
    CustomerRecord customer;
//    CustomerRecord expiredCustomer;

	// open input file and pass return value to length variable to make sure file isn't empty
	length = OpenInput(InFile);
	
	OpenOutput(OutFile); // open output file
	
	// if the length of the file/current positon is 0 (i.e the cursor didn't move)
	if(length == 0) {
        
		// file is empty error
		cout << "===> Input file is empty. Program terminated\n\n";
		return 1;
	}
    
    // set counters to 0
    numSubscribers = 0;
    numExpired = 0;

    // While we're not at the end of the file
    while(!InFile.eof()) {

        customer = ProcessInput(InFile); // ProcessInput and store each returned customer in the customer variable
		
        if (!InFile.fail()) // ensure the file stream isn't in the fail state
		{
			// if the returned customer's months left on subscription is 0
			if (customer.renewalInfo.monthsLeft == 0) {

				// **SUPPOSED TO WRITE INFO OF EXPIRED USER TO OUTPUT FILE ** 
				numExpired++;
				OutputExpired(OutFile, customer);
			}
			numSubscribers++; // increment the number of users processed by 1
		}
        
    }
    
    // output
    cout << endl << string(47,'-') << endl;
    cout << "Number of subscribers processed: " << numSubscribers << endl;
    cout << "The number of expired subscriptions is: " << numExpired << endl;
    cout << string(47,'-') << endl << endl;

	return 0;
}

// --------------------------------------------------------------------------------------------------

int OpenInput(ifstream &InFile) {
	string inputFile; // name of input file
	int fileLength; // store the length of the file to later determine if file is empty

    // Get input for file name (inputFile)
	cout << endl << "Enter name of input file or Control-C to quit program: ";
	cin >> inputFile;
	cout << inputFile << endl << endl;
	
	InFile.open(inputFile.c_str()); // open the input file
	
    // While the input file stream is in the fail state
	while(InFile.fail()) {
	    
        // output error
		cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << inputFile << endl;
		cout << "==> Please try again...\n";
		cout << string(47,'*') << endl << endl;

		InFile.clear(); // clear the file stream

        // Get input for file name again
		cout << "Enter name of input file or Control-C to quit program: ";
		cin >> inputFile;
		cout << inputFile << endl;

		InFile.open(inputFile.c_str()); // open the input file
	}
	
	InFile.seekg(0,ios::end); // seek to the end of the file
	fileLength = InFile.tellg(); // get the current position of the cursor
    InFile.seekg(0); // seek back to the beginning of the file

	return fileLength; // return the fileLength to be used in the main function
}

// --------------------------------------------------------------------------------------------------

void OpenOutput(ofstream &OutFile) {
	string outputFile; // name of output file 
	
    // Get input for file name (outputFile)
	cout << "Enter name of output file or Control-C to quit program: ";
	cin >> outputFile;
	cout << outputFile << endl << endl;

	OutFile.open(outputFile.c_str()); // open the output file

    // while the output file stream is in the fail state
	while(OutFile.fail()) {
						
        // output error
		cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
		cout << "==> Output file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << outputFile << endl;
		cout << "==> Please try again...\n";
		cout << string(47,'*') << endl << endl;

		OutFile.clear(); // clear the file stream
		
        // Get input for file name again
        cout << "Enter name of output file or Control-C to quit program: ";
		cin >> outputFile;
		cout << outputFile << endl;

		OutFile.open(outputFile.c_str()); // open the output file
	} 
	
}

// --------------------------------------------------------------------------------------------------

CustomerRecord ProcessInput(ifstream &InFile) {

    CustomerRecord customer; // define CustomerRecord variable

    InFile >> customer.name.first; // read in the first name member
    
    // if the file stream is in the fail state, close the file stream and return false
    if(InFile.fail()) {
        return customer;
    }
    
    // read in the rest of the name members (last name and ID)
    InFile >> customer.name.last;
    InFile >> customer.name.ID;

    // output
    cout << "====> Processing Customer ID: " << customer.name.ID << endl;
    InFile.ignore(INT_MAX,'\n');

    // read in customer address info (street, city, state, zip)
    
    getline(InFile, customer.address.street,'\n');
    getline(InFile, customer.address.city,'\n');
    getline(InFile, customer.address.state,'\n');
    InFile >> customer.address.zip;
    InFile.ignore(INT_MAX,'\n');

    // read in how many months left the customer has on their subscription
    // and the date of the their last renewal notice
    InFile >> customer.renewalInfo.monthsLeft;
    InFile >> customer.renewalInfo.lastNotice.month;
    InFile >> customer.renewalInfo.lastNotice.day;
    InFile >> customer.renewalInfo.lastNotice.year;
    
    return customer; // return customer struct
}

void OutputExpired(ofstream &OutFile, CustomerRecord customer) {
    
    // Output to file
    OutFile << string(55,'*') << endl;
    
    OutFile << customer.name.first << " " << customer.name.last << "(" << customer.name.ID << ")\n";
    
    OutFile << customer.address.street << endl;
    OutFile << customer.address.city << ", " << customer.address.state << " " << customer.address.zip << endl;
    
    OutFile << "The last renewal notice was sent on ";
    OutFile << customer.renewalInfo.lastNotice.month << " ";
    OutFile << customer.renewalInfo.lastNotice.day << ", ";
    OutFile << customer.renewalInfo.lastNotice.year << endl;
    OutFile << string(55,'*') << endl << endl;
} 

