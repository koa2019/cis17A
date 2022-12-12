/* 
 * File:   Supervisor.h
 * Author: DanYell
 *
 * Created on December 11, 2022, 1:51 PM
*/

#ifndef PRDCTNWRKR_H
#define PRDCTNWRKR_H
#include "Employee.h"
#include <string>
using namespace std;  //STD Name-space where Library is compiled

class Supervisor : public Employee {
    private:
        char jobTitle[20];
        float hourlyRate;
        int hrsWrkd;
        float grossPay;
        float netPay;
        double Tax(float);  //Utility Procedure
    public:        
       
        Supervisor(char nme[],char jTitle[],float hrRate) //Default Constructor 
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


#endif /* PRDCTNWRKR_H */

