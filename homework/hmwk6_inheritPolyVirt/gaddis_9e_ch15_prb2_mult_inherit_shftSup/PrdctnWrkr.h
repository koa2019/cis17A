/* File:   Supervisor.h
 * Author:Danielle Fernandez
 * Created on December 3, 2022, 12:47 PM
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
        PrdctnWrkr() {setWrkr(0,0.0f);}
        PrdctnWrkr(int shft,float p) {setWrkr(shft,p);}
        PrdctnWrkr(int shft,float p,string n,string i,string d){setWrkr(shft,p,n,i,d);}
        void setWrkr(int shft,float payRate);
        void setWrkr(int,float,string,string, string);
        void setShift(int);
        void setPay(float);
        string const getShift() const;
        float getPay() const {return pay;}
};


#endif /* PRDCTNWRKR_H */

