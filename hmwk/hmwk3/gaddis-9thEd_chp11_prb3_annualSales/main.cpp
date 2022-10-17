/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on 9/27/22 @10:20 PM
 * Purpose:  gaddis-9thEd_chp11_prb3_annualSales
*/

//System Libraries
#include <iostream>
#include <iomanip>
#include <string> // string
using namespace std;

//User Libraries
struct Div {
    
    string name; //division's name: west north east south
    float q1;   //quarter 1 sales 
    float q2;   //quarter 2 sales 
    float q3;   //quarter 3 sales 
    float q4;   //quarter 4 sales 
    float annual;   // sum of sales from 4 quarters
    float avgQtr;   // average of the 4 quarters
    
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Div dvn;   // West division
    
    int numQtrs = 4;    // number of quarters im a year
    string nameArr[4] = {"North", "West", "East", "South"}; //name of each division

    //Initialize Variables
    
    //Process or map Inputs to Outputs
    for(int i=0;i<numQtrs;i++){
        
        dvn.name = nameArr[i];
        cout << dvn.name << endl;
        
        cout << "Enter first-quarter sales:"<<endl;
        cin >> dvn.q1;
        
        cout << "Enter second-quarter sales:"<<endl;
        cin >> dvn.q2;
        
        cout << "Enter third-quarter sales:"<<endl;
        cin >> dvn.q3;
        
        cout << "Enter fourth-quarter sales:"<<endl;
        cin >> dvn.q4;
    
        //calculate annual quarterly sales
        dvn.annual = dvn.q1 + dvn.q2 + dvn.q3 + dvn.q4;
        
        //calculate average quarterly sales
        dvn.avgQtr = dvn.annual/numQtrs;
        
        //Display Outputs
        cout << fixed << setprecision(2);
        cout << "Total Annual sales:$" << dvn.annual << endl;
        cout << "Average Quarterly Sales:$" << dvn.avgQtr;
        
        if(i!=numQtrs-1) cout << endl;
    }

    //Exit stage right!
    return 0;
}