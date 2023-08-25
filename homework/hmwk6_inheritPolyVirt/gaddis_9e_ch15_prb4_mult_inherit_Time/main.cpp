/* File:    main.cpp
 * Author:  Danielle Fernandez
 * Created: 12-03-2022 @ 1:24 PM
 * Purpose:  Gaddis_9thEd_ch15_prb4_inherit_TimeFormat
 * 
 *          DateTime class inherits Date & Time classes (base modes).
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

    // declare constants
    const int MIN = 0;
    const int MAXHR = 2359;
    const int MAXSEC = 59;


    //************************************************
    // Date time class inherits Date & Time classes as base modes.
    //************************************************

    // Define a DateTime object and use the default
    // constructor to initialize it.
    DateTime emptyDay;

    // Define a DateTime object and initialize it
    // with the date 2/4/1960 and the time 5:32:27.
    DateTime pastDay(2, 4, 1960, 5, 32, 27);

    // Display the object's date and time.
    cout<<"DateTime inherits Date & Time classes.\n";
    emptyDay.showDateTime();
    pastDay.showDateTime();
    cout << endl << endl;


    //************************************************
    // DateMilitaryTime class inherits Date & MilTime class as base mode.
    //************************************************
    int mHrs, mSecs;

    do {
        cout << "Enter Military hours in the format HHMM 0059\n";
        cin >> mHrs;
    } while (mHrs < MIN || mHrs > MAXHR || (mHrs%100 > MAXSEC) );

    do {
        cout << "Enter seconds. Number between 1-59.\n";
        cin >> mSecs;
    } while (mSecs < MIN || mSecs > MAXSEC);

    // Create Military Time objects
    cout<<"\n\nDateMilTime  inherits Date & MilTime classes.\n"
        <<"MilTime class is derived from Time class.\n\n";
    
    DateMilTime emptyMilTime; // object created with default constructors
    DateMilTime mTime(12,3,2022,mHrs, mSecs); // object with military time and seconds

    // Print military time and military time converted to Standard time  
    emptyMilTime.showMilTime();
    mTime.showDateMilTime();
  
    return 0;
}