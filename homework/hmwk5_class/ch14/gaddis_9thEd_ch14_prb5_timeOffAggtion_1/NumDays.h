/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.h
 * Author: DanYell
 *
 * Created on November 27, 2022, 3:12 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays {
    private:
        float hrs;      // # hours worked
        float nDays;    // # of days worked. Dependent on hrs      
        float maxSick;  // max days of sick leave employee may take
        float sickTkn;  // # of sick leave employee has taken
        int maxV =240;  // max hours of vacation employee may take
        int min=0;      // minimum
        float maxVaca;  // max hours of vacation employee has earned
        float vacaTkn;  // # of vacation days employee has taken
        float maxUnpaid; // max days of unpaid vacation employee may take
        float unpaidTkn; // # of days of unpaid vacation employee has taken 
        void convert(); // convert hrs to nDays
        void setMaxSick();
        void setMaxVaca(); // set max # of vacation days earned
        void setMaxUnpaid();
       
    public:
        NumDays();      // default constructor
        NumDays(float h);  // constructor
        NumDays(float h,float d); // constructor
        void setHrs(float); // set # of hours worked
        void setHrs(float,float,float,float); // set # of hours worked       
        float getHrs() const{return hrs;}   
        float getDays() const {return nDays;}
        void printNDays() const;    // print NumDays members
        NumDays operator+(const NumDays &); // Overloaded +
        NumDays operator-(const NumDays &); // Overloaded -
        NumDays operator++();    // Overloaded ++Prefix
        NumDays operator++(int); // Overloaded Postfix++
        NumDays operator--();    // Overloaded --Prefix
        NumDays operator--(int); // Overloaded Postfix--
};

#endif /* NUMDAYS_H */

