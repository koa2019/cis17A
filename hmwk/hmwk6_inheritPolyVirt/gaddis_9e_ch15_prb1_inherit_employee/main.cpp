/* 
 * File:    main.cpp
 * Author:  Danielle Fernandez
 * Created: 12-02-2022 @ 2:36 PM
 * Purpose:  gaddis_9thEd_ch15_1_inherit_employee_1
 * 
 * Demonstrates inheritance. PrdctnWrkr Class is derived from Employee Class.
 * Employee Class is parent. PrdctnWrkr Class is child.
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "PrdctnWrkr.h"

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
       
    //Declare & initialize variables
    PrdctnWrkr emp1(1,25.99,"Jill","54321","12/02/2022");
    PrdctnWrkr emp2(2,30.42,"Cora","98743","10/30/2019");
    
    
    //Display the results
    //Employee 1
    cout << "Employee:     " << emp1.getName() << endl
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