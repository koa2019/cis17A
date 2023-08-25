/* 
 * File:    main.cpp
 * Author:  Danielle Fernandez
 * Created: 11-27-2022 @ 4:00 PM
 * Purpose:  Gaddis_9thEd_ch14_prb4_numDaysClass
 * v1: 
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>  // setprecision()
using namespace std; //STD Name-space where Library is compiled

//User Libraries
#include "NumDays.h"


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
   
    //Declare variables here
    float hrs1, hrs2, hrs3, nDays1, nDays2, nDays3;
    char ans;
    bool again = true;

    //Initialize variables here
    while (again) {
        
        do {
            cout << "Enter number of hours worked this month. Integer between 1-199\n";
            cin >> hrs1;            
        } while ( hrs1 < 1 || hrs1 > 199);

        hrs2 = 40;
        
        //Map inputs to outputs here, i.e. the process
        NumDays numDays1(hrs1);// Create new object 
        NumDays numDays2(hrs2);// Create new object
        NumDays numDays3,numDays4;// Create new object with default constructor
      
        
        // Display outputs
       
        cout << fixed << setprecision(2);
        cout << "NumDays1   " << numDays1.getHrs();
        cout << " == " << numDays1.getDays() << " days.\n";
       
        cout << "NumDays2   " << numDays2.getHrs();
        cout << " == " << numDays2.getDays() << " days.\n";
       
        
        // Overloaded + operator
        numDays3 = numDays1 + numDays2;        
        cout << "\nOverloaded Operator+  " << numDays3.getHrs();
        cout << " == " << numDays3.getDays() << " days.\n";
       
        
        // Overloaded - operator
        numDays3 = numDays1 - numDays2;        
        cout << "Overloaded Operator-  " << numDays3.getHrs();
        cout << " == " << numDays3.getDays() << " days.\n";
        
        // Overloaded ++Prefix
        numDays4.setHrs(100);
        cout << "\n\nOverloaded ++Operator\n";
        for(int i=0;i<4;i++){
            
            numDays3 =  ++numDays4;
            cout << "NumDays3     " << numDays3.getHrs()
                 << " == " << numDays3.getDays() << " days.    ";
            cout << "++NumDays4  " << numDays4.getHrs()
                 << " == " << numDays4.getDays() << " days.\n";
        }
        
        //  Overloaded  ++Postfix
        numDays4.setHrs(100);
        cout << "\n\nOverloaded Postfix++\n";
        for(int i=0;i<4;i++){
            
            numDays3 =  numDays4++;
            cout << "NumDays3     " << numDays3.getHrs()
                 << " == " << numDays3.getDays() << " days.    ";               
            cout << "NumDays4++  " << numDays4.getHrs()
                 << " == " << numDays4.getDays() << " days.\n";
        }

        
        // Overloaded --Prefix
        numDays4.setHrs(100);
        cout << "\n\nOverloaded --Prefix\n";
        for(int i=0;i<4;i++){
            
            numDays3 =  --numDays4;
            cout << "NumDays3     " << numDays3.getHrs()
                 << " == " << numDays3.getDays() << " days.    ";
            cout << "--NumDays4  " << numDays4.getHrs()
                 << " == " << numDays4.getDays() << " days.\n";
        }
        
        // Overloaded Postfix--
        numDays4.setHrs(100);
        cout << "\n\nOverloaded Postfix--\n";
        for(int i=0;i<4;i++){
            
            numDays3 =  numDays4--;
            cout << "NumDays3     " << numDays3.getHrs()
                 << " == " << numDays3.getDays() << " days.   ";
            cout << "--NumDays4  " << numDays4.getHrs()
                 << " == " << numDays4.getDays() << " days.\n";
        }
        
        cout << "\nAgain?  ";
        cin >> ans;
        again = (ans == 'y' || ans == 'Y') ? true : false;
    };

    return 0;
}