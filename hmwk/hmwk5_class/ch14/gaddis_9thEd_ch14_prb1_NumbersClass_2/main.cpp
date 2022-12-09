/* 
 * File:    main.cpp
 * Author:  Danielle Fernandez
 * Created: 11-22-2022 @ 12:36 PM
 * Purpose:  Gaddis_9thEd_ch14_prb1_numbersClass_2
 * * v1: converts number to English words
 * * v2: uses static arrays and variables from the class to convert a number to a string
 */

//System Libraries
#include <iostream>
#include <string>
//#include <valarray>   //Input/Output Library
using namespace std; //STD Name-space where Library is compiled

//User Libraries
#include "Number.h"

//Code Begins Execution Here with function main

int main(int argc, char** argv) {

    //Declare variables here
    int number;
    char ans;
    bool again=true;

    while (again) {

        //Initialize variables here
        do {
            cout << "Enter a number between 0-9999:   ";
            cin >> number;
        } while (number < 0 || number > 9999);


        //Map inputs to outputs here, i.e. the process
        Number num(number); // call constructor
        string str = num.num2Wrd(); // convert digits to English words

        
        //Display the results
        num.print(str);        
        
        // get user input to continue
        cout << "\nAgain?\n";
        cin >> ans;
        if (!(ans=='y' || ans=='Y')) again = false;
        
    }
    
    return 0;
}
