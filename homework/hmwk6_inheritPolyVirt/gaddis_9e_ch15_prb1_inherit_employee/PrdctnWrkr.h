/* 
 * File:   PrdctnWrkr.h
 * Author: DanYell
 *
 * Created on December 2, 2022, 8:51 PM
*/

#ifndef PRDCTNWRKR_H
#define PRDCTNWRKR_H
#include "Employee.h"
#include <string>
using namespace std;  //STD Name-space where Library is compiled

class PrdctnWrkr : public Employee {
    private:
        int shift;
        float pay;
    public:
        PrdctnWrkr() {set(0,0.0f);}
        PrdctnWrkr(int shft,float p) {set(shft,p);}
        PrdctnWrkr(int shft,float p,string n,string i,string d) {setWrkr(shft,p,n,i,d);}
        void set(int shft,float payRate);
        void setWrkr(int shft,float payRate,string name,string idNum, string hDate);
        void setShift(int);
        void setPay(float);
        string const getShift() const;
        float getPay() const {return pay;}
};


#endif /* PRDCTNWRKR_H */

