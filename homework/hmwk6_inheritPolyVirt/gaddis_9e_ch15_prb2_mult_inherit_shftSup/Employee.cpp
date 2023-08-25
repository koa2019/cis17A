//User Libraries
#include "Employee.h"
//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled


void Employee::setEmployee(string n, string idNum, string hDate){
            name=n;
            id=idNum;
            hireDate=hDate;
}

// set name member variable
void Employee::setName(string n){
    name=n;
}

// set emplpyee id number member variable
void Employee::setId(string i){
    id=i;
}

// set hire date member variable
void Employee::setHDate(string h){
    hireDate=h;
}