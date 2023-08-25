/* 
 * File:   DateMilTime.h
 * Author: DanYell
 *
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
        void showDateMilTime() const;    // print date and the time.
};

#endif /* DATEMILTIME_H */

