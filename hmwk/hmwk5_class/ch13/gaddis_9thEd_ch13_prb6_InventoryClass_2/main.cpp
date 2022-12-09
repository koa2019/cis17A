/* 
 * File:    main.cpp
 * Author:  Danielle Fernandez
 * Created: 11-11-2022 @ 2:36 PM
 * Purpose:  Gaddis_9thEd_ch13_prb6_inventoryClass_2
 * 
 * Version 1: Class and definitions  of member functions in main.cpp
 * Version 2: Moved class to .h file
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <valarray>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Inventory.h"

//class Inventory {
//    private:
//        int itemNum;
//        int quant;      // quantity of an item
//        float cost;     // cost of item
//        float ttlCost;   // total inventory cost for the item (quantity times cost) 
//    public:
//        Inventory();    // default constructor
//        Inventory(int,int,float,float t=0); // constructor #2
//        void setItemNum(int);  // mutators
//        void setQuant(int);    // mutators
//        void setCost(float);     // mutators
//        void setTtlCost(float);  // mutators
//        int getItemNum() const {return itemNum;}   // accessors
//        int getQuant() const {return quant;}     // accessors
//        float getCost() const {return cost;}    // accessors
//        float getTtlCost() const {return ttlCost;} // accessors        
//};

// Definitions of Class member functions
Inventory::Inventory(){ // default constructor
    itemNum=0;
    quant=0;
    cost=0.0f;
    ttlCost=0.0f;
}

// constructor #2
Inventory::Inventory(int i, int q, float c, float t){
   setItemNum(i);   
   setQuant(q);
   setCost(c);
   setTtlCost();
}

// Calculates total inventory cost for the item (quantity times cost) 
// and stores the result in ttlCost
void Inventory::setTtlCost(){
     ttlCost = cost * quant;
}

// copy to itemNum member
void Inventory::setItemNum(int i){
    itemNum = i;
}

// copy to quant member
void Inventory::setQuant(int q){
    quant = q;
}

// copy to cost member
void Inventory::setCost(float c){
    cost = c;
}

//Global Constants not Variables

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
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
       
    
    
    return 0;
}