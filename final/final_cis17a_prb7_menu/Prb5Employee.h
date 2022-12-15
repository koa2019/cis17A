/* 
 * File:   Prb5Employee.h
 * Author: DanYell
 *
 * Created on December 14, 2022, 11:34 PM
 */

#ifndef PRB5EMPLOYEE_H
#define PRB5EMPLOYEE_H

#include "Employee.h"
#include <string>
using namespace std;  //STD Name-space where Library is compiled

class Prb5Employee : public Employee {
    private:
        char jobTitle[20];
        float hourlyRate;
        int hrsWrkd;
        float grossPay;
        float netPay;
        double Tax(float);  //Utility Procedure
    public:        
       
        Prb5Employee(char nme[],char jTitle[],float hrRate) //Default Constructor 
            {setWrkr(nme,jTitle,hrRate);}
       
        //Mutators       
        void  setWrkr(char[],char[],float);
        float setHourlyRate(float);
        int   setHrsWrkd(int);
        
        //Accessors     
        float CalculatePay(float,int);
        float getGrossPay(float,int);
        float getNetPay(float);        
        void  toString();
};

#endif /* PRB5EMPLOYEE_H */