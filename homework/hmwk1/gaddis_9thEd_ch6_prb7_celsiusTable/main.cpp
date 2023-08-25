/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on 9/7/2022, 7:44 PM
 * Purpose: gaddis_9thEd_ch6_prb7_celsiusTable
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes
float celsius(float);   // converts Fahrenheit to Celsius

int main(int argc, char** argv) {
    
    float cel, fah;
    
    cout<<"This program converts Fahrenheit to Celsius \n\n";
       
    cout << "Fahrenheit " << setw(10) << "Celsius"<< endl
         << "----------------------" << endl;
    
    // call function and display results
    for(int i=1;i<=20;i++){
        cout << right << setw(6) << setprecision(0) << i << " " 
             << setw(13) << fixed << setprecision(2) << celsius(i) << endl;
    }
       
    return 0;
}

// function definitions

// convert Fahrenheit to Celsius
float celsius(float fah){
    return (5/9.0)*(fah-32);
}
