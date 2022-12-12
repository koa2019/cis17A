/* File:   Supervisor.h
 * Author:Danielle Fernandez
 * Created on December 3, 2022, 12:47 PM
*/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;  //STD Name-space where Library is compiled


class Employee {
    private:
        char name[20];        
       
    public:
        Employee(){
            for(int i=0;i<20;i++){
                name[i]=' ';
            }
        }
         
        Employee(char n[]){
            setName(n);
        }
                  
        void setName(char n[]){
           for(int i=0;i<20;i++){
                name[i]=n[i];
            }
        }
       
        string getName() const {
            string temp = name;
            return temp;}           
};

#endif /* EMPLOYEE_H */

