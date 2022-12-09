/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on December, 5 2022, 6:18 PM
 * Purpose:  gaddis_9thEd_ch13_prb1_ClassDate
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
    int month, day, year;   

    //Initialize variables here
    cout << "Enter month as an integers. Number between 1-12 \n";
    cin >> month;
    
    cout << "Enter day as integers. Number between 1-31 \n";
    cin >> day;

    cout << "Enter a 4 digit year. Example input: 2022\n";
    cin >> year;
       
    
    // creating Date object with default constructor
    Date date4;
    
    cout<<"\nObject created with default constructor:  ";
    date4.formatdigt();
    
    try {
        
        date4.setMonth(month);
        date4.setDay(day);
        date4.setYear(year);       
         
        //Display object
        cout << "\nNumber Format:  ";
        date4.formatdigt();
        
        cout << "\nUnited States Date Format:  ";
        date4.formatUS();
    
        // Europe date format
        cout << "\nEurope's Date Format:  ";
        date4.formatEU();
    } 
    catch (Date::InvalidMonth) {
        cout<<"Error. Month must be between 1-12\n";
    } 
    catch (Date::InvalidDay) {
        cout<<"\nError. Day must be between 1-31\n";
    } 
    catch (Date::InvalidYr) {
        cout<<"\nError. Year must be a 4 digit number\n";
    }
    
    return 0;
}