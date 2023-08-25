/* 
 * File:    main.cpp
 * Author:  Danielle Fernandez
 * Created: 11-11-2022 @ 6:36 PM
 * Purpose:  Gaddis_9thEd_ch13_prb11_numberArrayClass_1
 * 
 * Version 1: class and class member functions in main.cpp
 * Version 2: class moved to Array.h file
 */

//System Libraries
#include <iostream>
#include <iomanip>   // setprecision
#include <valarray>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Array.h"

Array::Array(int s){
    size=s;
    arrPtr = nullptr;
    
    // initialize ptr with a array of floats
    arrPtr = new float[size];
    
    // initialize array elements to zero
    for(int i=0;i<size;i++){        
        arrPtr[i] = 0;
    }
}
void Array::setElements(){
    
    int indx;
    float value;  
    
     for(int i=0;i<size;i++){
        cout<<"Enter a float number\n";        
        cin>>value;
        arrPtr[i]=value;  
    }
}

void Array::reset1Element(){
    
    int indx;
    float value;
    
    do{
        cout<<"Enter array index. Number between 0 and " << size-1 << endl;
        cin >> indx;
    } while(indx>size-1 || indx<0);
    
    cout<<"Enter value you want to store in array[" << indx << "]\n";
    cin>>value;
    
    value = (value < 1) ? 0 : value;
    
    // reset value in array
    arrPtr[indx]=value;    
}

void Array::printArr() const {
    cout << fixed << setprecision(2);
    cout << "\n{";
    for(int i=0;i<size;i++){
        cout << arrPtr[i] << " ";
        if(i==size-1) cout<<"}\n\n";
    }
}

float Array::getHigh() const {
    
    float max = arrPtr[0];
    for(int i=1;i<size;i++){
        if(max < arrPtr[i]) max = arrPtr[i];
    }
    return max;
}

float Array::getLow() const {
    
    float low = arrPtr[0];
    for(int i=1;i<size;i++){
        if(low > arrPtr[i]) low = arrPtr[i];
    }
    return low;
}
float Array::getAvg() const {
    
    float sum =0;
    
    for(int i=0;i<size;i++){
        sum += arrPtr[i];
    }
    
    return sum/size;
}
Array::~Array(){
    delete arrPtr;
}
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int size;
    
    //Initialize variables here
    cout<< "Enter array size\n";
    cin >>size;
    
    // allocate dynamic memory for float array
    Array object(size);
    object.printArr();
   
    
    // reset values inside of array
    object.setElements();
    object.printArr();
    
    // reset one element in array
    object.reset1Element();
    object.printArr();
    
    // find highest, lowest, average
    cout << "\nHighest: " << object.getHigh()<<endl;
    cout << "Lowest: " << object.getLow()<<endl;
    cout << "Average: " << object.getAvg()<<endl;
    
    return 0;
}