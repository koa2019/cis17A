/* 
 * File:   Date.h
 * Author: Danielle Fernandez
 * Created on November 9, 2022, 8:18 PM
 * Purpose: Card Class Specification
 */
#include <string>

#ifndef DATE_H
#define DATE_H

class Date {
    private:        
        int month;
        int day;
        int year;
    public:
        Date(); // default constructor
        Date(int,int,int); // constructor #2        
//        void setMonth(int m=0);
//        void setDay(int d=0);
//        void setYear(int y=0);
        int getMonth() const{return month;}
        int getDay() const{return day;}
        int getYear() const {return year;}
        void formatUS(int,int,int);
        void formatEU(int,int,int);
};


#endif /* DATE_H */

