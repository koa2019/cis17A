/* File:   DateTime.h
 * Author: DanYell
 * Created on December 3, 2022, 3:49 PM
*/

// Specification file for the DateTime class
#ifndef DATETIME_H
#define DATETIME_H
#include "Date.h"
#include "Time.h"
using namespace std;

// DateTime is derived class. Date & Time class are the base classes
class DateTime : public Date, public Time
{
    public:
        DateTime();   // Default constructor
        DateTime(int, int, int, int, int, int);    // Constructor #2       
        void showDateTime() const;    // print date and the time.
};
#endif
