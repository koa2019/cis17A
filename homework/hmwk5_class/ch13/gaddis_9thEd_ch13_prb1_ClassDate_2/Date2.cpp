/* 
 * File:   Date.cpp
 * Author: Danielle Fernandez
 * Created on November 9, 2022, 8:18 PM
 * Purpose: Card Class Implementation
 */

//User Libraries
#include "Date2.h"

//System Libraries
#include <iostream>   //Input/Output Library
#include <string>
using namespace std; //STD Name-space where Library is compiled




Date::Date() { // default constructor    
    month = 0;
    day = 0;
    year = 0;
}

Date::Date(int m, int d, int y) { // default constructor   
    month = m;
    day = d;
    year = y;
}

// Mutator functions
//void Date::setMonth(int m) {
//    month = m;
//}
//
//void Date::setDay(int d) {
//    day = d;
//}
//
//void Date::setYear(int y) {
//    year = y;
//}


void Date::formatUS(int month, int day, int year) {
    
    string mon = 
            month == 1 ? "January" :
            month == 2 ? "February" :
            month == 3 ? "March" :
            month == 4 ? "April" :
            month == 5 ? "May" :
            month == 6 ? "June" :
            month == 7 ? "July" :
            month == 8 ? "August" :
            month == 9 ? "September" :
            month == 10 ? "October" :
            month == 11 ? "November" : "December";
    
    cout << mon << " " << day << ", " << year << endl;
}

void Date::formatEU(int month, int day, int year) {
    
    string mon = 
            month == 1 ? "January" :
            month == 2 ? "February" :
            month == 3 ? "March" :
            month == 4 ? "April" :
            month == 5 ? "May" :
            month == 6 ? "June" :
            month == 7 ? "July" :
            month == 8 ? "August" :
            month == 9 ? "September" :
            month == 10 ? "October" :
            month == 11 ? "November" : "December";
    
    cout << day << " " << mon << " " << year << endl;
}
