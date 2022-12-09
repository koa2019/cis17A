/* 
 * File:   Day.h
 * Author: Danielle Fernandez
 * Created on November 27, 2022
 */
#include <iostream>
#include <string>
using namespace std; //STD Name-space where Library is compiled

#ifndef DAY_H
#define DAY_H

class Day {
    private:
        bool isValid;
        int day;
        int indx;
        string month;
        string mArray[12] = {"January  ", "February ", "March ", "April ", "May ", "June ", "July ", "August ", "September ", "October ", "November ", "December "};
        void verify();
        void simplify();
    public:
        Day(); // default constructor
        Day(int, int); // constructor #2
        Day(string, int); // constructor 3
        void setMonth(int);
        void setDay(int);
        bool getIsValid() const {return isValid;}
        string getMonth() const {return month;}
        int getDay() const {return day;}
        void getMnthDy() const {
            cout << month << day << endl;
        }
        Day operator++();    //Overloaded ++prefix
        Day operator++(int); //Overloaded postfix++
        Day operator--();    //Overloaded --prefix
        Day operator--(int); //Overloaded postfix--
};

#endif /* DAY_H */

