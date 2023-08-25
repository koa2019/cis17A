/* 
 * File:   Date.cpp
 * Author: Danielle Fernandez
 * Created on December, 5 2022, 6:18 PM
 * Purpose: Card Class Implementation
 */

//User Libraries
#include "Date2.h"

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>
#include <string>
using namespace std; //STD Name-space where Library is compiled


Date::Date() { // default constructor    
    month=0;
    day=0;
    year=0;   
}

Date::Date(int m, int d, int y) { // Constructor #2 
    setMonth(m);
    setDay(d);
    setYear(y);
}

// **************************
// Mutator functions
// set month member variable
// **************************
void Date::setMonth(int m) {
    
    if( m >= 1 && m <= 12 ) {month = m;} 
    else {throw InvalidMonth();}
}

// **************************
// set day member variable
// **************************
void Date::setDay(int d) {
    
    if( d >= 1 && d <= 31) {day = d;}
    
    else {throw InvalidDay();}
}

// **************************
// set year member variable
// **************************
void Date::setYear(int y) {
    
    if(y >= 1000 && y <= 9999) {year = y;}
    
    else {
        throw InvalidYr(); 
        exit(0);
    }
}

// **************************************
// change month from a number to a string
// **************************************
string Date::setMonString(int month) {
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
            month == 11 ? "November" : 
            month == 12 ? "December" : "Month";  
    return mon;
}

// **************************************
// print date in xx/xx/xxxx format
// **************************************
void Date::formatdigt(){   
    cout << setw(2) << setfill('0')
         << month << "/" 
         << setw(2) << day << "/" 
         << setw(2) << year << endl;
}

// **************************************
// print date in Month, Day Year format
// **************************************
void Date::formatUS(){
    string mnth = setMonString(month);
    cout << mnth << " " << setw(2) << setfill('0') << day << ", " << year << endl;
}

// **************************************
// print date in Day Month Year format
// **************************************
void Date::formatEU(){  
    string mnth = setMonString(month);
    cout << setw(2) << setfill('0') << day << " " << mnth << " " << year << endl;
}

