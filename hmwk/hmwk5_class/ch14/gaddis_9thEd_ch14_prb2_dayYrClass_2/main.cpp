/* 
 * File:    main.cpp
 * Author:  Danielle Fernandez
 * Created: 11-22-2022 @ 2:07 PM
 * Purpose:  Gaddis_9thEd_ch14_prb2_dayYrClass_v2
 * v1: sets the month string. Calculates the date but does not append it to the
 *     print string. I think I need an operator+() override function ?
 * v2: save integer date as a string in class function 
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std; //STD Name-space where Library is compiled

//User Libraries
#include "Day.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
   
    //Declare variables here
    int num;
    char ans;
    bool again = true;

    //Initialize variables here
    while (again) {
        do {
            cout << "Enter a number between 1-365:  ";
            cin >> num;            
        } while (num < 1 || num > 365);


        //Map inputs to outputs here, i.e. the process
        Day day(num); // Create new object
        string str = day.num2Day(); // convert number to string


       //Display the results
        cout << endl << num << " == ";
        day.print(str);
        
        
        cout << "\nAgain?  ";
        cin >> ans;
        again = (ans == 'y' || ans == 'Y') ? true : false;
    };

    return 0;
}