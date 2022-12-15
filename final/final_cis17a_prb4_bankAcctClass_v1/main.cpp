/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on October 17, 2022, 10:24 PM
 * Purpose: final_prb4_bankAcctClass_1
 *
 */
#include <iostream>
#include <cstdlib>  //rand()
#include <ctime>    //rand()
#include <iomanip> //setw()
#include <cmath>  //pow()
using namespace std;

#include "SavingsAcct.h"

int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Driver code
    float input=0;

    cout<<"Input starting balance.\n";
    cin>>input;
 
    SavingsAcct mine(input);
    
    mine.toString();
    cout<<endl;
    
    int max = 32767;
    float amount;
    for (int i = 1; i <= 10; i++) {
        amount = (rand()%500)*(rand()%3-1);
        cout << "Transaction(amount)= " << amount << endl;
        mine.Transaction(amount);
    }
    mine.toString();
    
    cout << "Balance after 7 years given 10% interest = "
            << mine.Total((0.10),7) << endl;
    cout << "Balance after 7 years given 10% interest = "
            << mine.TotalRecursive((0.10),7)
            << " Recursive Calculation " << endl;
    
    return 0;
}

