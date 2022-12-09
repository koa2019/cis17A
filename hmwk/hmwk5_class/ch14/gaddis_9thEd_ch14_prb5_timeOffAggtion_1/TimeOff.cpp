
//User Libraries
#include "NumDays.h"
#include "TimeOff.h"

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>  // setprecision()
using namespace std; //STD Name-space where Library is compiled

// ****************************
// Default Constructor
// ****************************
TimeOff::TimeOff(){
    name="";
    idNum = "00000";
    numDays;
}

// ****************************
// Constructor #2
// ****************************
TimeOff::TimeOff(string n, string i,float hrs, float sTkn, float vTkn, float upTkn){
    name=n;
    idNum = i;
    numDays.setHrs(hrs,sTkn,vTkn,upTkn);
}

void TimeOff::print(){
    cout << getName() << endl
         << "Id #                " << getId() << endl;
    numDays.printNDays();
         
}
