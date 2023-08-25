/* 
 * File:    main.cpp
 * Author:  Danielle Fernandez
 * Created: 11-11-2022 @ 2:36 PM
 * Purpose:  Gaddis_9thEd_ch13_prb6_inventoryClass_2
 * 
 * Version 1: Class and definitions  of member functions in main.cpp
 * Version 2: Moved class to .h file
 * Version 3: Moved class member functions to their own .cpp file
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <valarray>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Inventory.h"

//Global Constants not Variables

//Function Prototypes

//Code Begins Execution Here with function main

int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int itemNum=0, quantity=0;
    float cost=0;
    
    Inventory item1;
    
    //Display the results
    cout << left << setw(8) << setfill(' ') << "Item #" << setw(10) << "Quantity" << setw(8) << "Cost" << setw(8) << "Total Cost\n";
    cout << setw(8) << item1.getItemNum() << setw(10) << item1.getQuant() 
         << setw(8) << item1.getCost() << setw(8) << item1.getTtlCost() << endl;
    
    
    //Initialize variables here
    Inventory item2(2,12,10.01);
    
    
    //Display the results    
    cout << setw(8) << item2.getItemNum() << setw(10) << item2.getQuant() 
         << setw(8) << item2.getCost() << setw(8) << item2.getTtlCost() << endl;
      
    // user inputs for item3
    do{
        cout << "Enter item number\n";
        cin >> itemNum;
    }while(itemNum<0);
    
    do {
        cout << "Enter quantity of item number\n";
        cin >> quantity;
     }while(quantity<0);
     
     do {
        cout << "Enter cost of item\n";
        cin >> cost;
     }while(cost<0);
     
    Inventory item3(itemNum,quantity,cost);
    
    //Display the results    
    cout << setw(8) << item3.getItemNum() << setw(10) << item3.getQuant() 
         << setw(8) << item3.getCost() << setw(8) << item3.getTtlCost() << endl;
    
    
    return 0;
}