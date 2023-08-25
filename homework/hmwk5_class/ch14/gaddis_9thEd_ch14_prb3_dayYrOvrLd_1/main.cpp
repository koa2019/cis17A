/* 
 * File:    main.cpp
 * Author:  Danielle Fernandez
 * Created: 11-27-2022 @ 12:00 PM
 * Purpose:  Gaddis_9thEd_ch14_prb3_dayYrOverloadedPrefixPostfix_v2
 * v1: 
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
    int num, mon;
    char ans;
    bool again = true;

    //Initialize variables here
    while (again) {
        
        do {
            cout << "Enter a month. A number between 1-12\n";
            cin >> mon;            
        } while ( mon < 1 || mon > 12);

        do {
            cout << "Enter a day between 1-31:\n";
            cin >> num;            
        } while ( num < 1 || num > 31);
        
        
        //Map inputs to outputs here, i.e. the process
        Day day(mon,num); // Create new object
       

        //Display the results if num of days in month is valid
        if(day.getIsValid()) {
            day.getMnthDy();
        }
        
        
        cout<<"\n\nOverloaded ++Prefix\n";
        Day day2(12,29);  
        Day first;
        
        for(int i=1;i<4;i++){             
            first = ++day2;    
            cout << first.getMonth() << " " << first.getDay() << ",  ";      
            day2.getMnthDy();
        }
         
       cout<<"\n\nOverloaded Postfix++\n";
       day2.setMonth(12);
       day2.setDay(29);
       
       for(int i=1;i<4;i++){ 
            first = day2++;            
            cout << first.getMonth() << " " << first.getDay() << ",  ";                      
            day2.getMnthDy();
        }
        
        
        cout<<"\n\nOverloaded --Prefix\n";
        day2.setMonth(1);
        day2.setDay(2);     
        
        for(int i=1;i<4;i++){             
            first = --day2;   
            cout << first.getMonth() << " " << first.getDay() << ",  ";            
            day2.getMnthDy();
        }
        
        cout<<"\n\nOverloaded Prefix--\n";
        day2.setMonth(1);
        day2.setDay(2); 
        
        for(int i=1;i<4;i++){                          
            first = day2--;   
            cout << first.getMonth() << " " << first.getDay() << ",  ";  
            day2.getMnthDy();
        }
        
        
        cout << "\nAgain?  ";
        cin >> ans;
        again = (ans == 'y' || ans == 'Y') ? true : false;
    };

    return 0;
}