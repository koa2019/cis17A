/* 
 * File:   DateMilTime.h
  * Author:  Danielle Fernandez
 * Created: 12-06-2022 @ 11:24 PM
 * Created on December 3, 2022, 6:06 PM
 */

#ifndef DATEMILTIME_H
#define DATEMILTIME_H
#include "Date.h"
#include "MilTime.h"
using namespace std;


class DateMilTime :  public Date, public MilTime {
    public:
        DateMilTime();   // Default constructor       
        DateMilTime(int, int, int, int, int);    // Constructor #2 Date & MilTime
        DateMilTime(int, int, int);    // Constructor #3 Date & MilTime
        void showDateMilTime() const;    // print date and the time.
};

#endif /* DATEMILTIME_H */

