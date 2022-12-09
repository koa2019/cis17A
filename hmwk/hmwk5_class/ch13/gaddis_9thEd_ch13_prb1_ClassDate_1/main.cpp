/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created: 11-09-2022 @8:14 PM
 * Purpose:  gaddis_9thEd_ch13_prb1_ClassDate
 * 
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <string>
using namespace std; //STD Name-space where Library is compiled

//User Libraries
#include "Date2.h"


//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
string getMonString(int);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here

    //Declare variables here
    int month, day, year;
   
    // creating Date object with default constructor
    Date date3;
    
    //Map inputs to outputs here, i.e. the process

    //Initialize variables here
    do {
        cout << "Enter month as integers. Example input: 11 \n";
        cin >> month;
    } while (month < 1 || month > 12);

    do {
        cout << "Enter day as integers. Example input: 30 \n";
        cin >> day;
    } while (day < 1 || day > 31);

    do {
        cout << "Enter a 4 digit year. Example input: 2022\n";
        cin >> year;
    } while (year < 1000 || year > 9999);

    // get a string for month number
    string mon = getMonString(month);
    cout << "\nMonth string: " << mon << endl;
       
    // create Date object with constructor #2
    Date date4(month, day, year);

    //Display date1 object
    cout << "\ndate3 object created with default constructor\n";
    cout << date3.getMonth() << "/" << date3.getDay() << "/" << date3.getYear() << endl;

    //Display date3 object
    cout << "\ndate4 object created with overloaded constructor #2\n";
    cout << date4.getMonth() << "/" << date4.getDay() << "/" << date4.getYear() << endl;

    
    // United States format
    cout << "\nUnited States Date Format: \n";
    date4.formatUS(month, day, year);
    

    // Europe date format
    cout << "\nEurope's Date Format: \n";
    date4.formatEU(month, day, year);

    return 0;
}

// change month from a number to a string
string getMonString(int month) {
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
    return mon;
}