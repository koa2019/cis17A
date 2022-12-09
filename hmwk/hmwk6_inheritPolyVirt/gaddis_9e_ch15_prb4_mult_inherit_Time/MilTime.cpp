
#include <iostream>
#include <string>
#include <iomanip>    //setprecision(2)
#include "MilTime.h"
using namespace std;


// sets member variables. Converts military time to standard
//  and stores in hours,min,secs variables in Time class
 void MilTime::setMilTime(int mTime,int mSec){
     
    setMilHrs(mTime);
    setMilSecs(mSec);
    
    int hr, min;
    
    min = mTime%100;   //Convert military time to Standard time minutes
    
    mTime /=100;   //Calculate military hours    
   
    hr = (mTime<=12) ? mTime : (mTime-12);   //Convert military time to Standard Time hours
    
    hr = hr==0 ? 12 : hr;
    
    setTime(hr,min,mSec);  //Set variables in Time class        
 }
 
 // Display the military time in the form HHMM:SS.
 void MilTime::showMilTime() const {
    
    cout << "Military Time:    " << setw(4) << right << setfill('0') 
         <<  getMilHrs() << ":" 
         << setw(2) << getMilSecs() << endl;     
 }
 
 // Display Standard time in the form HH:MM:SS.
 void MilTime::showStandTime() const {     
   cout << "Standard Time:    " 
        << setw(2) << right << setfill('0') << getHour() << ":" 
        << setw(2) << getMin() << ":"
        << setw(2) << getSec();
   if(getMilHrs()<1200) { cout << " A.M." << endl; }
   else { cout << " P.M." << endl; }
 }
