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
#include "Date1.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
string getMonString(int);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here

    //Declare variables here
    int month, day, year;
    
    // creating Date object with NO constructor
    Date1 date1;
   
    //Map inputs to outputs here, i.e. the process
    //date1.setString1("");
    date1.setMonth1();
    date1.setDay1();
    date1.setYear1();

    //Display Date1 object
    cout << "\ndate1 object created with NO constructor & default arguments\n";
    cout << date1.getMonth1() << "/" << date1.getDay1() << "/" << date1.getYear1() << endl << endl;
    //cout << "str=" << date1.getStr1() << " " << date1.getMonth1() << "/" << date1.getDay1() << "/" << date1.getYear1() << endl << endl;

    
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
    
    // creating Date object with NO constructor
    Date1 date2;
   
    //Map inputs to outputs here, i.e. the process
    //date2.setString(mon);
    date2.setMonth1(month);
    date2.setDay1(day);
    date2.setYear1(year);

    //Display Date1 object
    cout << "\ndate2 object created NO constructor & user inputs\n";
    cout << date2.getMonth1() << "/" << date2.getDay1() << "/" << date2.getYear1() << endl;
    
  
    // United States format
    cout << "\nUnited States Date Format: \n";
    date2.formatUS1(month, day, year);
    

    // Europe date format
    cout << "\nEurope's Date Format: \n";
    date2.formatEU1(month, day, year);


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