//User Libraries
#include "Supervisor.h" 

//System Libraries
#include <string>
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled


//
void Supervisor::setSup(float s, float b) {
    aSalary=s;
    aBonus=b;
    setEmployee("","","");    // set parent class
}

//
void Supervisor::setSup(float s, float b, string name, string idNum, string hDate) {
    aSalary=s;
    aBonus=b;
    //Call inherited setEmployee()
    setEmployee(name,idNum,hDate);
}

//
void Supervisor::setSalary(float s) {
     aSalary=s;
}

//
void Supervisor::setBonus(float b) {
     aBonus=b;
}