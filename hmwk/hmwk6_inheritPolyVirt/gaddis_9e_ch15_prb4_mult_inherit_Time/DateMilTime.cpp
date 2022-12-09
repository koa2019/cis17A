// Implementation file for the DateTime class
#include <iostream>
//#include <string>
#include "DateMilTime.h"

using namespace std;

//************************************************
// Default constructor                           *
// Note that this constructor does nothing other *
// than call default base class constructors.    *
//************************************************
DateMilTime::DateMilTime() : Date(), MilTime()
{ }


//************************************************
// Constructor #2                                *
// Note that this constructor does nothing other *
// than call base class constructors.            *
//************************************************
DateMilTime::DateMilTime(int dy, int mon, int yr, int mHr, int mSc) :
    Date(dy, mon, yr), MilTime(mHr, mSc)
{ }

//************************************************
// The showDateTime member function displays the *
// date and the time.                            *
//************************************************
void DateMilTime::showDateMilTime() const
{
   // Display the date in the form MM/DD/YYYY.
   cout << getMonth() << "/" << getDay() << "/" << getYear() << " \n";

   // Display the time in the form HH:MM:SS.
   showStandTime();
   
   // Display the time in the form HHMM:SS.
   showMilTime();
}