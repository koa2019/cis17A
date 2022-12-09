/* 
 * File:   Date.h
 * Author: Danielle Fernandez
 * Created on December, 5 2022, 6:18 PM
 * Purpose: Card Class Specification
 */

#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std; //STD Name-space where Library is compiled


class Date {
    private:  
        int month;
        int day;
        int year;
        
    public:
        class InvalidDay {}; //Exception class for day<1 or day>31
        class InvalidMonth {}; //Exception class for month<1 or month>12
        class InvalidYr {}; //Exception class for 
        
        Date(); // default constructor
        Date(int,int,int); // constructor #2 
        
        //Mutator functions
        void setMonth(int);
        string setMonString(int);
        void setDay(int);
        void setYear(int);
        
        //Accessor functions
        int getMonth() const{return month;}        
        int getDay() const{return day;}
        int getYear() const {return year;}
        void formatdigt();
        void formatUS();
        void formatEU();
};

#endif /* DATE_H */

