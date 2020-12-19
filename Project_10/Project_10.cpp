// **************************************************************
// **************************************************************
//
// **********  DO NOT MODIFY ANYTHING IN THIS SECTION
//
// solution cpp file for project 10
// all helper function definitions go in this file

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Project_10.h"

using namespace std;

// **************************************************************
// **************************************************************
//
// **************************************************************
// **********   PUT ALL FUNCTION DEFINITIONS BELOW THIS COMMENT
//
// Function definitions start here. 

// ************** CONTRUCTORS **************

// default constructor which sets the date to 1/1/1900
Date::Date() {
    month = 1;
    day = 1;
    year = 1900;
}

// paramaterized constructor which sets the date to user provided values
Date::Date(int initMonth, int initDay, int initYear) {
    month = initMonth;
    day = initDay;
    year = initYear;
}

// paramaterized constructor for user provided month and year, sets the day to 1
Date::Date(int initMonth, int initYear) {
    month = initMonth;
    day = 1;
    year = initYear;
}

// ************** TRANSFORMERS **************

// allows the user to set/change the date object
void Date::SetDate(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
}

// increment the date by 1, handles going to the next month/year
void Date::IncrementDate() {
    
    day++;

    switch(month) {
        case JAN:
            if (day > 31) {
                day = 1;
                month++;
            }
            break;
        case FEB:
            if (day > 28) {
                day = 1;
                month++;
            }
            break;
        case MAR:
            if (day > 31) {
                day = 1;
                month++;
            }
            break;
        case APR:
            if (day > 30) {
                day = 1;
                month++;
            }
            break;
        case MAY:
            if (day > 31) {
                day = 1;
                month++;
            }
            break;
        case JUN:
            if (day > 30) {
                day = 1;
                month++;
            }
            break;
        case JUL:
            if (day > 31) {
                day = 1;
                month++;
            }
            break;
        case AUG:
            if (day > 31) {
                day = 1;
                month++;
            }
            break;
        case SEP:
            if (day > 30) {
                day = 1;
                month++;
            }
            break;
        case OCT:
            if (day > 31) {
                day = 1;
                month++;
            }
            break;
        case NOV:
            if (day > 30) {
                day = 1;
                month++;
            }
            break;
        case DEC:
            if (day > 31) {
                day = 1;
                month = 1;
                year++;
            }
             break;
    }
}
// ************** OBSERVERS *******************

// Write the date in number format (MM//DD/YYYY)
void Date::WriteNumberFormat() const {
    if (month < 10 || day < 10) {
        cout << setfill('0') << setw(2) << right << month << "/" << setw(2) << right << day << "/" << year << endl;
    } else {
        cout << month << "/" << day << "/" << year << endl;
    }
}

// write the date in name format (MONTH DAY, YEAR)
void Date::WriteNameFormat() const {
    string output;

    // string for half of the format, since we only really need to convert the month into its name
    output = to_string(day) + ", " + to_string(year) + "\n";

    switch(month) {
        case JAN:
            cout << "January " << output;
            break;
        case FEB:
            cout << "February " << output;
            break;
        case MAR:
            cout << "March " << output;
            break;
        case APR:
            cout << "April " << output;
            break;
        case MAY:
            cout << "May " << output;
            break;
        case JUN:
            cout << "June " << output;
            break;
        case JUL:
            cout << "July " << output;
            break;
        case AUG:
            cout << "August " << output;
            break;
        case SEP:
            cout << "September " << output;
            break;
        case OCT:
            cout << "October " << output;
            break;
        case NOV:
            cout << "November " << output;
            break;
        case DEC:
            cout << "December " << output;
            break;
        }
}

// determine if two date objects are the same
bool Date::SameDate(Date otherDate) const {
    if(otherDate.month == month && otherDate.day == day && otherDate.year == year) {
        return true;
    } else {
        return false;
    }
}
