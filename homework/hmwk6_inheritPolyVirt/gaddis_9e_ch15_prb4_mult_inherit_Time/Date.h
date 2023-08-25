/* 
 * File:   Date.h
 * Author: DanYell
 *
 * Created on December 3, 2022, 3:51 PM
 */


// Specification file for the Date class
#ifndef DATE_H
#define DATE_H

class Date {
protected:
    int day;
    int month;
    int year;
    
public:
   
    Date() {    // Default constructor
        day = 1;
        month = 1;
        year = 1900;
    }

    Date(int d, int m, int y) {  // Constructor 
        day = d;
        month = m;
        year = y;
    }

    // Accessors
    int getDay() const {return day;}
    int getMonth() const { return month;}
    int getYear() const {return year;}    
};
#endif

