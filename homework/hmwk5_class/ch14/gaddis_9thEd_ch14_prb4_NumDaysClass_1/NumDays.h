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
        float hrs;
        float nDays;
        void convert();
       
    public:
        NumDays();
        NumDays(float h);
        NumDays(float h,float d);
        void setHrs(float);
        float getHrs() const{return hrs;}
        float getDays() const {return nDays;}
        NumDays operator+(const NumDays &); // Overloaded +
        NumDays operator-(const NumDays &); // Overloaded -
        NumDays operator++();    // Overloaded ++Prefix
        NumDays operator++(int); // Overloaded Postfix++
        NumDays operator--();    // Overloaded --Prefix
        NumDays operator--(int); // Overloaded Postfix--
};

#endif /* NUMDAYS_H */

