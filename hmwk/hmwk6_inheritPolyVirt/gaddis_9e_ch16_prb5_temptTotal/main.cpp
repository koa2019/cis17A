/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 12-06-2022 @ 2:36 PM
 * Purpose:  gaddis_9e_ch16_prb5_template_total
 * 
 * Function should keep a running total of values entered by user,
 * then return the total.
 * 
 * The argument sent into the function should be the number of values 
 * the function is to read.
 * 
 * Driver sends values of various types as arguments & display results
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Total.h"

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    //Declare variables here
    int count = 0;  
    float cFloat=0;
   
    //Initialize variables here
    cout << "How many numbers would you like to add together?\n"
         << "Enter integers.\n";
    cin >> count;       
    cout << setTotal(count) << endl;
    
    // send a float into template
    cout << "\n\nHow many numbers would you like to add together?\n"
         << "Enter floats.\n";
    cin >> cFloat;       
    cout << setTotal(cFloat) << endl;
    
    return 0;
}
