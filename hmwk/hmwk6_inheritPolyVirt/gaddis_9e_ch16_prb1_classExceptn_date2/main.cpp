/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on December, 5 2022, 6:18 PM
 * Purpose:  gaddis_9thEd_ch16_prb1_ClassExceptionDate_2
 * 
 * version 2 uses while with try/catch statements until user
 * inputs a valid number
 * 
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <string>
using namespace std; //STD Name-space where Library is compiled

//User Libraries
#include "Date2.h"


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
   
    //Declare variables here
    bool tryAgan=true;  //set flag
    int month, day, year;  
    
    Date date4;    // creating Date object with default constructor
    
    cout<<"\n\nObject created with default constructor:  ";
    date4.formatdigt();
    
    
    //Initialize variables here
    cout << "\nEnter month as an integers. Number between 1-12 \n";
    cin >> month;
    
    while(tryAgan){        
        try {        
            date4.setMonth(month);
            tryAgan=false; // If no exception was thrown, then next statement will execute.
        } 
        catch (Date::InvalidMonth) {
            cout << "Error. Enter month as an integers. Number between 1-12 \n";
            cin >> month;
        } 
    }
      
      
    cout << "Enter day as integers. Number between 1-31 \n";
    cin >> day;
    
    tryAgan=true;   // reset flag   
    
    while(tryAgan){        
        try {        
            date4.setDay(day);
            tryAgan=false; // If no exception was thrown, then next statement will execute.
        } 
        catch (Date::InvalidDay) {
            cout << "Error. Enter day as integers. Number between 1-31 \n";
            cin >> day;
        } 
    }
    
    cout << "Enter a 4 digit year. Example input: 2022\n";
    cin >> year;
       
    tryAgan=true;   // reset flag    
    
    while(tryAgan){    
        try {
            date4.setYear(year);       
            tryAgan=false; // If no exception was thrown, then next statement will execute.         
        } 
        catch (Date::InvalidYr) {
            cout<<"Error. Enter a 4 digit year. Example input: 2022\n";
            cin >> year;
        }
    }
    
    //Display object
    cout << "\nNumber Format:  ";
    date4.formatdigt();
        
    cout << "\nUnited States Date Format:  ";
    date4.formatUS();
    
    // Europe date format
    cout << "\nEurope's Date Format:  ";
    date4.formatEU();
    
    return 0;
}