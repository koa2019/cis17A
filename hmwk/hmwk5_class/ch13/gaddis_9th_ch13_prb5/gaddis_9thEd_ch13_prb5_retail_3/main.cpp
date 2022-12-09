/*
 * Danielle Fernandez
 * 11-11-22 @12PM
 * Purpose: Gaddis_9thEd_ch13_prb5_retailItem_3
 * 
 * Version 1: Class and constructor definitions are in main.cpp
 * Version 2: Moved class to .h file 
 * Version 3: Move class constructor to its own .cpp file
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <valarray>   //Input/Output Library
using namespace std;

#include "RetailItem.h"


//// Class constructor
//RetailItem::RetailItem(string n, int u, float p){
//    name=n;
//    numUnits=u;
//    price=p;
//}

int main() {    
       
    // declare & initialize variables
    int size=3;
    string name[3]={"Jacket","Jeans","Shirt"};
    int units[3]={12,40,20};
    float prce[3]={59.95, 34.95, 24.95};
        
    // created 3 new objects from RetailItem Class
    RetailItem item1(name[0],units[0],prce[0]);
    RetailItem item2(name[1],units[1],prce[1]);
    RetailItem item3(name[2],units[2],prce[2]);
    
    // outputs
    cout << "\n____________________________________________________________\n";
    cout << "        \tDescription \t Units on Hand \t Price" << endl;
    cout << "____________________________________________________________\n";    
    
    cout << "Item #1 \t" << item1.getName() << "\t            " << item1.getUnits() << "\t\t " << fixed << setprecision(2) << item1.getPrice() << endl;
    cout << "Item #2 \t" << item2.getName() << "\t            " << item2.getUnits() << "\t\t " << fixed << setprecision(2) << item2.getPrice() << endl;
    cout << "Item #3 \t" << item3.getName() << "\t            " << item3.getUnits() << "\t\t " << fixed << setprecision(2) << item3.getPrice() << endl;
    
    return 0;
}
