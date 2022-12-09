/* File:   Supervisor.h
 * Author:Danielle Fernandez
 * Created on December 3, 2022, 12:47 PM
*/

#ifndef SUPERVISOR_H
#define SUPERVISOR_H
#include "Employee.h"
#include <string>
using namespace std;  //STD Name-space where Library is compiled

class Supervisor : public Employee {
    private:
        float aSalary;   //Annual salary
        float aBonus;    //Annual bonus
    public:
        Supervisor(){setSup(0,0.0);}
        Supervisor(float slry,float bns) {setSup(slry,bns);}
        Supervisor(float slry,float bns,string n,string i,string d){setSup(slry,bns,n,i,d);}
        void setSup(float,float);
        void setSup(float,float,string,string,string);
        void setSalary(float);
        void setBonus(float);
        float getSalary() const {return aSalary;}
        float getBonus() const {return aBonus;}
        
};

#endif /* SUPERVISOR_H */

