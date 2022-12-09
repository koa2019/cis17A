/* 
 * File:    main.cpp
 * Author:  Danielle Fernandez
 * Created: 11-11-2022 @ 2:36 PM
 * Purpose:  Gaddis_9thEd_ch14_prb1_numbersClass_1
 * v1: converts number to English words
 */

//System Libraries
#include <iostream>
#include <string>
#include <valarray>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Number.h"



//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int number;  
    
    //Initialize variables here
    do {
        cout << "Enter a number between 0-9999\n";
        //cin >> number;
    }while (number<0 || number>9999);
    
    number = 9999;
    
    Number num(number); // call constructor
    string str = num.num2Wrd();
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    num.print();
    num.print(str);
      
    return 0;
}
