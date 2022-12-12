/* 
 * File:    main.cpp
 * Author:  Danielle 
 * Created on December 11, 2022, 1:51 PM
 * Purpose: final_cis17a_prb5_employeeClass
 * 
 * Used my homework from gaddis_9thEd_ch15_1_inherit_employee_1
 * as a starting point for this problem.
 * 
 * Demonstrates inheritance. Supervisor Class is derived from Employee Class.
 * Employee Class is parent. Supervisor Class is child.
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Supervisor.h"

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
       
    //Driver Program
    Supervisor Mark("Mark","Boss",215.50);
    Mark.setHrsWrkd(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),Mark.setHrsWrkd(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),Mark.setHrsWrkd(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),Mark.setHrsWrkd(25));
    Mark.toString();
    cout<<endl<<endl;
    
    //Display the results
    
    Supervisor Mary("Mary","VP",50.00);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHrsWrkd(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHrsWrkd(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHrsWrkd(60));
    Mary.toString();
    
    return 0;
}