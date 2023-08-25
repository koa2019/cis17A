//User Libraries
#include "PrdctnWrkr.h"

//System Libraries
#include <string>
//#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled


void PrdctnWrkr::set(int shft,float payRate){
    shift=shft;
    pay=payRate;
}


// function sets this class's member variables and it's parent class member variables
void PrdctnWrkr::setWrkr(int shft,float payRate,string name, string idNum, string hDate){
    shift=shft;
    pay=payRate;
    
    //Call inherited setEmployee()
    setEmployee(name,idNum,hDate);
}

void PrdctnWrkr::setShift(int s){
     shift= (s<1 && s>2) ? 1 : s;
     
}

void PrdctnWrkr::setPay(float p){
     pay=p;
}

string const PrdctnWrkr::getShift() const {
    string str;
    if(shift==1) {str="Day Shift";}
    else if(shift==2) {str="Night Shift";}
    else {str="Invalid shift code.";}
    return str;
}