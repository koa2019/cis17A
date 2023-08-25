/* 
 * File:   main.cpp
 * Author: Danielle Fernandez 
 * Created on 09/07/2022, 6:22 PM
 * Purpose: gaddis_9thEd_ch4_prb10_daysInMonth
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    
    // declare variables
    int nDays,  // number of days in a given month
        month,  // month as an integer.(1-12)
        year;   // a four digit year. (1900)
    bool isLeapY = false;      
  
    //read in and validate month and year 
    do {
        cout << "Enter a month as an integer.(1-12)\n";
        cin >> month;
    } while(month<1 || month>12);
    
    while(year<1000 || year>9999){
        cout << "Enter a four digit year. (1900)\n";
    cin >> year;
    }
    
    // set number of days in a non-leap year month
    switch (month){
        case 2: nDays=28; break;
        case 4:
        case 6:
        case 9:
        case 11: {
            nDays=30;
            break;
        }        
        default: nDays=31;
    }
    
    // check if year is a leap year or not
    // It is a Leap Year if year is divisible by 100 AND year is divisible by 400.
    // It is also a Leap Year if year is not divisible by 100 AND year is divisible by 4.
    if((year%100==0 && year%400==0)||(year%100>0 && year%4==0)){
        isLeapY=true;
        if(month==2) nDays=29;        
    }
    else isLeapY=false;    
    
    // display output
    cout << nDays << " days" << endl;
    
    return 0;
}

