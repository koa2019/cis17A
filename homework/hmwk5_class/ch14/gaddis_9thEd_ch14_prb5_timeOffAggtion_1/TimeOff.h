/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeOff.h
 * Author: DanYell
 *
 * Created on November 27, 2022, 9:06 PM
 */
#include "NumDays.h"
#include <string>
using namespace std; //STD Name-space where Library is compiled

#ifndef TIMEOFF_H
#define TIMEOFF_H

class TimeOff {
    private:        
        string name;
        string idNum;
        NumDays numDays;
    public:
        TimeOff();  // Default constructor
        TimeOff(string,string,float,float,float,float); // Constructor #2
        void setName(string);
        void setId(string);
        string getName() const {return name;}
        string getId() const {return idNum;}
        void print();
};

#endif /* TIMEOFF_H */

