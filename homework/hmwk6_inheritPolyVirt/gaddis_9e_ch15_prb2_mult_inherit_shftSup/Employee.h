/* 
 * File:   Employee.h
 * Author: DanYell
 *
 * Created on December 2, 2022, 8:37 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;  //STD Name-space where Library is compiled


class Employee {
    private:
        string name;
        string id;
        string hireDate;
    public:
        Employee(){setEmployee("","","");}
        Employee(string n,string i,string h){setEmployee(n,i,h);}
        void setEmployee(string, string, string);
        void setName(string);
        void setId(string);
        void setHDate(string);
        string getName() const {return name;}
        string getId() const {return id;}
        string getHDate() const {return hireDate;}        
};

#endif /* EMPLOYEE_H */

