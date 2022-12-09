#include "Day.h"
#include <iostream>
#include <string>
using namespace std; //STD Name-space where Library is compiled


// Constructor
Day::Day(int d) {
    day = d;
}

// Print number that was converted to a day of the year
void Day::print(string str) {
    cout << endl << day << " == " << str << endl;
}

// Convert number to day of the year
string Day::num2Day() {

    string s1, s2, str;
    int date;

    if (day >= 1 && day <= 31) { // Jan 31
        s1 = (month[0]);
        date = day;
        
    } else if (day >= 32 && day <= 59) { // Feb 28
        s1 = (month[1]);
        date = day - 31;
        
    } else if (day >= 60 && day <= 90) { // march 31
        s1 = (month[2]);
        date = day - 59;
        
    } else if (day >= 91 && day <= 120) { // April 30
        s1 = (month[3]);
        date = day - 90;
        
    } else if (day >= 121 && day <= 151) { // May 31
        s1 = (month[4]);
        date = day - 120;
        
    } else if (day >= 152 && day <= 181) { // June 30
        s1 = (month[5]);
        date = day - 151;
        
    } else if (day >= 182 && day <= 212) { // July 31
        s1 = (month[6]);
        date = day - 181;
        
    } else if (day >= 213 && day <= 243) { // August 31
        s1 = (month[7]);
        date = day - 212;
        
    } else if (day >= 244 && day <= 273) { // September 30
        s1 = (month[8]);
        date = day - 243;
        
    } else if (day >= 274 && day <= 304) { // October 31
        s1 = (month[9]);
        date = day - 273;
        
    } else if (day >= 305 && day <= 334) { // November 30
        s1 = (month[10]);
        date = day - 304;
        
    } else if (day >= 335 && day <= 365) { // December 31
        s1 = (month[11]);
        date = day - 334;
        
    } else {s1 = "error in month ";}


    str = s1;
    
    cout << date << endl;

    return str;
}

