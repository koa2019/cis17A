/* File:    main.cpp
 * Author:  Danielle Fernandez
 * Created: 12-06-2022 @ 11:24 PM
 * Purpose:  Gaddis_9thEd_ch16_prb2_inheritExcptn_TimeFormat
 *          Added try/catch exceptions for user inputs
 *          DateMilitaryTime class inherits Date & MilTime class (base modes).
 *          MilitaryTime class derived from Time class (base mode).
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>    //setprecision(2)
using namespace std; //STD Name-space where Library is compiled

//User Libraries
#include "DateTime.h"
#include "DateMilTime.h"


//Code Begins Execution Here with function main
int main(int argc, char** argv) { 

    //Declare variables
    bool again=true;
    int mHrs, 
        mSecs,
        month=12,
        day=3,
        year=2022;

    
    //************************************************
    // DateMilitaryTime class inherits Date & MilTime class as base mode.
    //************************************************
    cout << "\n\nDateMilTime class inherits Date & MilTime classes.\n"
         << "MilTime class is derived from Time class.\n";
    
    
    //Create object with constructor #3
    DateMilTime mTime(day,month,year); 
    cout << "\n\nObject created with Constructor #3:\n";
    mTime.showDateMilTime();
    
    
    // initialize variables
    cout << "\n\nEnter Military hours in the format HHMM 0059\n";
    cin >> mHrs;
        
    while(again){
        try {
            mTime.setMilHrs(mHrs);
            again=false;// If no exception was thrown, then next statement will execute.
        } 
        catch(DateMilTime::BadHr){
            cout << "Invalid hour. Enter Military hours in the format HHMM 0059\n";
            cin >> mHrs;
        }
    }

    cout << "Enter seconds. Number between 0-59.\n";
    cin >> mSecs;
    
    again = true;    
    while(again){
        try {
            mTime.setMilSecs(mSecs);
            again=false;// If no exception was thrown, then next statement will execute.
        }
        catch(DateMilTime::BadSec){
            cout << "Invalid seconds. Enter seconds. Number between 1-59.\n";
            cin >> mSecs;
        }   
    }
       
    // Print military day &  military time converted to Standard time
    cout << "\n\nObject reinitialized.\nMilitary time converted to Standard time.\n"; 
    mTime.setStandTime(); 
    mTime.showDateMilTime();
  
    return 0;
}