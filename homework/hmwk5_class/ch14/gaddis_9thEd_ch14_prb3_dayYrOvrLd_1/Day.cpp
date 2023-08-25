#include "Day.h"
#include <iostream>
#include <string>
using namespace std; //STD Name-space where Library is compiled


// Default Constructor
Day::Day() {   
    isValid = true;
    month = "";
    day = 0;
}

// constructor #2
Day::Day(int mon, int d) {

    setMonth(mon);
    setDay(d);
    isValid = true;

    // verify # of days in Feb, April, June, Sept, Nov
    if (indx == 1 || indx == 3 || indx == 5 || indx == 8 || indx == 10) verify();
}

// constructor #3
Day::Day(string mon, int d) {
    month=mon;
    day=d;
}
    
    
// Private member function. Verify this month has that many days in it
void Day::verify() {

    switch (indx) {
        case 1: {
            if (day > 28) {
                isValid = false;
                cout << "\nError. " << month << "does not have " << day << " days in it.\n";
                return;
            }
            break;
        }
        default: {
            if (day > 30) {
                isValid = false;
                cout << "\nError. " << month << "does not have " << day << " days in it.\n";
                return;
            }
            break;
        }
    }
}

// set month
void Day::setMonth(int m){
    indx = m-1;
    month = mArray[indx];
}

// set value of day 
void Day::setDay(int d){
   day = d;         
}

// Private member function that adjusts the day after prefix and postfix
void Day::simplify() {
    if (month == "December " && day == 32) {
        setMonth(1);
        setDay(1);
    } else if (month == "January  " && day == 0) {
        setMonth(12);
        setDay(31);
    } else {
        return;
    }
}

// Overloaded ++Prefix
Day Day::operator++() {
    ++day;
    simplify();
    return *this;
}

// Overloaded Postfix++
Day Day::operator++(int) {
    Day temp(month,day);
    day++;
    simplify();
    return temp;  
}

// Overloaded --Prefix
Day Day::operator--() {
    day--;
    simplify();
    return *this;
}

// Overloaded Postfix--
Day Day::operator--(int) {
    Day temp(month,day);
    --day;
    simplify();
    return temp;    
}