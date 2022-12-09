/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 12-06-2022 @ 1:05 PM
 * Purpose:  gaddis_9e_ch16_prb3_tempMaxMin
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>  //setw()
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "MaxMin.h"

//Function Prototypes
char setCharMin(char, char);
char setCharMax(char, char);
int setIntMin(int, int);
int setIntMax(int, int);
void printCharMin(char,char);
void printCharMax(char,char);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
        
    //Declare variables here
    char a=56,
        b=57,
        min,
        max;
    int intA=56,
        intB=57;
    float fltA=5.5,
          fltB=4.5;
    
    //Map inputs to outputs here, i.e. the process
    cout << setw(3) << a << " <= " << setw(3) << b << " ? " 
         << "Minimum char: " << setMin(a,b) << endl;
    cout << setw(3) << a << " >= " << setw(3) << b << " ? " 
         << "Maximum char: " << setMax(a,b) << endl << endl ;
    
    cout << setw(3) << intA << " <= " << setw(3) << intB << " ? " 
         << "Minimum int: " << setMin(intA,intB) << endl;
    cout << setw(3) << a << " >= " << setw(3) << b << " ? " 
         << "Maximum int: " << setMax(intA,intB) << endl << endl ;
        
    cout << setw(3) << fltA << " <= " << setw(3) << fltB << " ? " 
         << "Minimum float: " << setMin(fltA,fltB)<< endl;  
    cout << setw(3) << fltA << " >= " << setw(3) << fltB << " ? " 
         << "Maximum float: " << setMax(fltA,fltB) << endl << endl;
    
    a=79;
    b=77;
    intA=79,
    intB=77; 
    fltA=79.12,
    fltB=77.59;
//    cout << setw(3) << a << " <= " << setw(3) << b << " ? " 
//         << "Minimum char: " << setMin(a,b) << endl;
//    cout << setw(3) << a << " >= " << setw(3) << b << " ? " 
//         << "Maximum char: " << setMax(a,b) << endl << endl ;
//    
//    cout << setw(3) << intA << " <= " << setw(3) << intB << " ? " 
//         << "Minimum int: " << setMin(intA,intB) << endl;
//    cout << setw(3) << a << " >= " << setw(3) << b << " ? " 
//         << "Maximum int: " << setMax(intA,intB) << endl << endl ;
//        
//    cout << setw(3) << intA << " <= " << setw(3) << intB << " ? " 
//         << "Minimum float: " << setMin(fltA,fltB)<< endl;  
//    cout << setw(3) << a << " >= " << setw(3) << b << " ? " 
//         << "Maximum float: " << setMax(fltA,fltB) << endl << endl;
   
    
    
    a=99;
    b=99;
    intA=99,
    intB=99;
    fltA=99.19,
    fltB=99.19;
//    cout << setw(3) << a << " <= " << setw(3) << b << " ? " 
//         << "Minimum char: " << setMin(a,b) << endl;
//    cout << setw(3) << a << " >= " << setw(3) << b << " ? " 
//         << "Maximum char: " << setMax(a,b) << endl << endl ;
//    
//    cout << setw(3) << intA << " <= " << setw(3) << intB << " ? " 
//         << "Minimum int: " << setMin(intA,intB) << endl;
//    cout << setw(3) << a << " >= " << setw(3) << b << " ? " 
//         << "Maximum int: " << setMax(intA,intB) << endl << endl ;
//        
//    cout << setw(3) << intA << " <= " << setw(3) << intB << " ? " 
//         << "Minimum float: " << setMin(fltA,fltB)<< endl;  
//    cout << setw(3) << a << " >= " << setw(3) << b << " ? " 
//         << "Maximum float: " << setMax(fltA,fltB) << endl << endl;
    
    return 0;
}

//****************************************
//       Function definitions
//****************************************

// return minimum value from 2 arguments
char setCharMin(char a, char b){
    
    char min = (a<=b) ? a : b;
    return min;
}

//return maximum value from 2 arguments
char setCharMax(char a, char b){    
    char max = (a>=b) ? a : b;    
    return max;
}

// return minimum value from 2 arguments
int setIntMin(int a, int b){
    
    int min = (a<=b) ? a : b;
    return min;
}

//return maximum value from 2 arguments
int setIntMax(int a, int b){    
    int max = (a>=b) ? a : b;    
    return max;
}
 

void printCharMin(char a, char b){
    cout << setw(3) << a << " <= " << setw(3) << b << " ? " 
         << "Minimum: " << setMin(a,b) << endl;
}

void printCharMax(char a, char b){
    cout << setw(3) << a << " >= " << setw(3) << b << " ? " 
         << "Maximum: " << setMax(a,b) << endl << endl;
}