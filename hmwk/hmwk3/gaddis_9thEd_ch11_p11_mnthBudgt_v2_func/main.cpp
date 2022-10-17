/* 
* File: main.cpp
* Author: Danielle Fernandez
* Created on 9/28/22 8:10 PM
* Purpose:  gaddis_9thEd_ch11_prb11_monthBudget_v2
*   created functions to getdata and find sums for budget and how much user spent
*/

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
struct Budgt {
    float rent; //monthly rent
    float utl; //utilities
    float hExp; //house expenses
    float trans; //transportation
    float food; //food
    float medic; //medical
    float insur; //insurance
    float entmnt; //entertainment
    float cloths; //clothes
    float misc; // Miscellaneous
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void getData(Budgt&);
void sumBudgt(Budgt&, float&);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed

    //Declare Variable Data Types and Constants
    Budgt bdgt = {500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00}; //declare a new struct to hold how much is alotted for each category
    Budgt spent; //declare new struct for how much was spent that month  
   
    float sum = 0,
          bSum = 0;

    //Initialize Variables
    getData(spent);
    sumBudgt(bdgt, bSum);
    sumBudgt(spent,sum);

    cout << "Total budget allotted = " << bSum << endl;
    cout << "total spent this month = " << sum << endl;
    cout << "bSum-sum = " << bSum - sum << endl;

    //Process or map Inputs to Outputs

    //Display Outputs

    //Exit stage right!
    return 0;
}

/************FUNCTION DEFINITIONS**************/

//calculate sum of the total allotted budget
void sumBudgt(Budgt &bdgt, float &sum) {
    sum += bdgt.rent;
    sum += bdgt.utl;
    sum += bdgt.hExp;
    sum += bdgt.trans;
    sum += bdgt.food;
    sum += bdgt.medic;
    sum += bdgt.insur;
    sum += bdgt.entmnt;
    sum += bdgt.cloths;
    sum += bdgt.misc;
}

//read user inputs. Return struct & sum
void getData(Budgt &spent) {
    cin >> spent.rent;
    cin >> spent.utl;
    cin >> spent.hExp;
    cin >> spent.trans;
    cin >> spent.food;
    cin >> spent.medic;
    cin >> spent.insur;
    cin >> spent.entmnt;
    cin >> spent.cloths;
    cin >> spent.misc;
}