/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date1.cpp
 * Author: DanYell
 * 
 * Created on November 9, 2022, 11:28 PM
 */

#include "Date1.h"
#include <iostream>
#include <string>
using namespace std; //STD Name-space where Library is compiled


// Mutator functions
//void Date1::setString1(string str) {
//    monStr1 = str;
//}

void Date1::setMonth1(int m) {
    month1 = m;
}

void Date1::setDay1(int d) {
    day1 = d;
}

void Date1::setYear1(int y) {
    year1 = y;
}
void Date1::formatUS1(int month, int day, int year) {
    
    string mon = 
            month == 1 ? "January" :
            month == 2 ? "February" :
            month == 3 ? "March" :
            month == 4 ? "April" :
            month == 5 ? "May" :
            month == 6 ? "June" :
            month == 7 ? "July" :
            month == 8 ? "August" :
            month == 9 ? "September" :
            month == 10 ? "October" :
            month == 11 ? "November" : "December";
    
    cout << mon << " " << day << ", " << year << endl;
}

void Date1::formatEU1(int month, int day, int year) {
    
    string mon = 
            month == 1 ? "January" :
            month == 2 ? "February" :
            month == 3 ? "March" :
            month == 4 ? "April" :
            month == 5 ? "May" :
            month == 6 ? "June" :
            month == 7 ? "July" :
            month == 8 ? "August" :
            month == 9 ? "September" :
            month == 10 ? "October" :
            month == 11 ? "November" : "December";
    
    cout << day << " " << mon << " " << year << endl;
}
