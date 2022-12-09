#include "NumDays.h"
#include <iostream>
#include <string>
#include <cmath>    // abs()

using namespace std; //STD Name-space where Library is compiled

// ****************************
// Default Constructor
// ****************************
NumDays::NumDays(){
    hrs=0;
    nDays=0;
    convert();
}

// ****************************
// Constructor #2
// ****************************
NumDays::NumDays(float h){
    hrs=h;
    nDays=0;
    convert();
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
