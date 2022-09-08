/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on September 6, 2022, 6:58 PM
 * Purpose: gaddis_9thEd_ch3_prb12_cel2Fahrnt
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    float cel, fahrnt;
    
    cout<<"This program converts Celsius to Fahrenheit\n"
        << "Input degrees in Celsius. \n";
    
    cin>>cel;
    
    // convert celsius to fahrenheit
    fahrnt=((9.0/5)*cel) +32;
    
    // display results
    cout << "Celsius:    "<< cel<< endl
         << "Fahrenheit: "<< fahrnt <<endl;
    
    
    return 0;
}

