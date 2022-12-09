/* 
 * File:    main.cpp
 * Author:  Danielle Fernandez
 * Created: 11-11-2022 @ 6:36 PM
 * Purpose:  Gaddis_9thEd_ch13_prb11_numberArrayClass_1
 * 
 * Version 1: class and class member functions in main.cpp
 * Version 2: class moved to Array.h file
 * Version 3: moves class member functions to Array.cpp
 */

//System Libraries
#include <iostream>
#include <iomanip>   // setprecision
#include <valarray>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Array.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int size;
    
    //Initialize variables here
    cout<< "Enter array size\n";
    cin >>size;
    
    // allocate dynamic memory for float array
    Array object(size);
    object.printArr();
   
    
    // reset values inside of array
    object.setElements();
    object.printArr();
    
    // reset one element in array
    object.reset1Element();
    object.printArr();
    
    // find highest, lowest, average
    cout << "\nHighest: " << object.getHigh()<<endl;
    cout << "Lowest: " << object.getLow()<<endl;
    cout << "Average: " << object.getAvg()<<endl;
    
    return 0;
}