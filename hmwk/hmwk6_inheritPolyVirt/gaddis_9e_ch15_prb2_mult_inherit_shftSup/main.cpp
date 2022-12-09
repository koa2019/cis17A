/* File:    main.cpp
 * Author:  Danielle Fernandez
 * Created: 12-03-2022 @ 12:36 PM
 * Purpose:  gaddis_9thEd_ch15_2_inherit_shftSupervisor
 * 
 * Demonstrates inheritance:
 * PrdctnWrkr Class is derived from Employee Class.
 * Supervisor Class is derived from Employee Class.
 * Employee Class is parent. PrdctnWrkr & Supervisor Classes are children.
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "PrdctnWrkr.h"
#include "Supervisor.h"


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
       
    //Declare & initialize variables
    Supervisor sup1(200000,4500,"Teddy","47897","03/30/2009");
    PrdctnWrkr emp1(1,25.45,"Jill","54321","12/02/2022");
    PrdctnWrkr emp2(2,29.15,"Cora","98743","10/30/2019");
    
    
    //Display the results
    //Supervisor
    cout << "\nSupervisor:  " << sup1.getName()   << endl
         << "Id Number:       " << sup1.getId()     << endl
         << "Hire Date:       " << sup1.getHDate()  << endl
         << "Annual Salary:   " << sup1.getSalary() << endl
         << "Annual Bonus:    " << sup1.getBonus()  << endl;
    
    //Employee 1
    cout << "\n\nEmployee:     " << emp1.getName() << endl
         << "Id Number:    " << emp1.getId() << endl
         << "Hire Date:    " << emp1.getHDate() << endl
         << "Shift:        " << emp1.getShift()  << endl
         << "Pay per hour: " << emp1.getPay() << endl;
    
    //Employee 2
    cout << "\n\nEmployee:     " << emp2.getName() << endl
         << "Id Number:    " << emp2.getId() << endl
         << "Hire Date:    " << emp2.getHDate() << endl
         << "Shift:        " << emp2.getShift()  << endl
         << "Pay per hour: " << emp2.getPay() << endl;
    
    return 0;
}