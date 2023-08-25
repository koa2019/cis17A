/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 12-06-2022 @ 2:44 PM
 * Purpose:  gaddis_9e_ch16_prb4_templateAbsoulteValue1
 * version 1: utilizes a template to find absolute value of an int and float
 * 
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "AbsVal.h"


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    //Declare variables here
    int nInt=-12;
    float nFlt=-99.12;
       
    //Display the results
    cout << "Abs(" << nInt << ") = " << setInt(nInt) << endl;
    
    cout << "Abs(" << nFlt << ") = " << setInt(nFlt) << endl;
    
    return 0;
}