/* 
 * File:   Day.h
 * Author: Danielle Fernandez
 * Created on November 22, 2022, 3:16 PM
 */

#include <string>
using namespace std; //STD Name-space where Library is compiled

#ifndef DAY_H
#define DAY_H

class Day {
    private:
        int day;
        string month[12] = {"January ", "February ", "March ", "April ", "May ", "June ", "July ", "August ", "September ", "October ", "November ", "December "};
    public:
        Day(int d = 1); // constructor
        string num2Day(); // convert number to day of year
        void print(string);
};

#endif /* DAY_H */

