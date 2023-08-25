#include "NumDays.h"
#include <iostream>
#include <string>
#include <cmath>    // abs()
#include <iomanip>  // setprecision()
using namespace std; //STD Name-space where Library is compiled

// ****************************
// Default Constructor
// ****************************
NumDays::NumDays(){
    hrs=min;
    nDays=min;
    convert();
    maxSick=4.0f;
    sickTkn=min;
    maxVaca=14.0f;
    vacaTkn=min;
    maxUnpaid=min;
    unpaidTkn=0;
}

// ****************************
// Constructor #2
// ****************************
NumDays::NumDays(float h){   
    nDays=0;
    setHrs(h);
}


// ****************************
// Constructor #3
// ****************************
NumDays::NumDays(float h,float d){
    setHrs(h);
    nDays=d;
    convert();
}
// ****************************
// Private member function
// ****************************
void NumDays::convert(){
    nDays = hrs/8.0f;   
}
void NumDays::setHrs(float h){
     hrs=h;
     convert();
}

void NumDays::setMaxSick(){    
    maxSick = nDays * .12;
}

void NumDays::setMaxVaca(){    
    maxVaca = nDays * .25;
}

void NumDays::setMaxUnpaid(){    
    maxUnpaid = nDays * .18;
}

void NumDays::setHrs(float h, float sTkn, float vTkn, float upTkn){
    setHrs(h);
    setMaxSick();
    setMaxVaca();
    setMaxUnpaid();
    sickTkn=sTkn;
    vacaTkn=vTkn;
    unpaidTkn=upTkn;    
}

void NumDays::printNDays() const {
    cout << fixed << setprecision(2)
         << "Hours worked:       " << getHrs() << endl
         << "# days worked:      " << getDays() << endl
         << "Max Sick Days:      " << maxSick << endl
         << "Sick Days Taken:    " << sickTkn << endl
         << "Max Vacation Days:  " << maxVaca << endl
         << "Vacation Taken:     " << vacaTkn << endl
         << "Max Unpaid Days:    " << maxUnpaid << endl
         << "Sick Days Taken:    " << unpaidTkn << endl;    
}

// ****************************
// Overloaded binary + operator
// ****************************
NumDays NumDays::operator+(const NumDays &right){
    NumDays temp;
    temp.hrs = hrs + right.hrs;    
    convert();
    temp.nDays = nDays + right.nDays;
    return temp;
}

// ****************************
// Overloaded binary - operator
// ****************************
NumDays NumDays::operator-(const NumDays &right){
    NumDays temp;
    temp.hrs = abs((hrs - right.hrs));
    temp.convert();
    temp.nDays = abs((nDays - right.nDays));
    return temp;
}

// ****************************
// Overloaded Prefix ++operator
// ****************************
NumDays NumDays::operator++() {
    ++hrs;
    convert();
    return *this;
}

// ****************************
// Overloaded Postfix operator++
// ****************************
NumDays NumDays::operator++(int) {
    
    NumDays temp(hrs,nDays);
    hrs++;
    convert();
    return temp;
}

// ****************************
// Overloaded Prefix --operator
// ****************************
NumDays NumDays::operator--() {
    --hrs;
    convert();
    return *this;
}

// ****************************
// Overloaded Postfix operator--
// ****************************
NumDays NumDays::operator--(int) {
    
    NumDays temp(hrs,nDays);
    hrs--;
    convert();
    return temp;
}
