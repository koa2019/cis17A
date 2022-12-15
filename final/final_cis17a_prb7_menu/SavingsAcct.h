/* 
 * File:   SavingsAcct.h
 * Author: DanYell
 * Created on December 14, 2022, 10:10 PM
*/

#ifndef SAVINGSACCT_H
#define SAVINGSACCT_H
#include <iostream>
#include <cstdlib>  //rand()
#include <ctime>    //rand()
#include <iomanip> //setw()
#include <cmath>  //pow()
using namespace std;


class SavingsAcct {
private:
    float Balance; //Property
    int FreqWithDraw; //Property
    int FreqDeposit; //Property
    float Withdraw(float); //Utility Procedure
    float Deposit(float); //Utility Procedure

public:
    SavingsAcct(float); //Constructor
    void Transaction(float); //Procedure
    float Total(float = 0, int = 0); //Savings Procedure
    float TotalRecursive(float = 0, int = 0);
    void toString(); //Output Properties
};

//******************************************************************************
//              Class function definitions
//******************************************************************************
//Default constructor
SavingsAcct::SavingsAcct(float amount) {
    Balance = amount < 0 ? 0 : amount; //if bal is negative initialize Balance to zero
    FreqWithDraw = 0;
    FreqDeposit = 0;   
}

//If the transaction is greater than 0 then a Deposit is made
//else a Withdraw is made.
void SavingsAcct::Transaction(float amount){
    
   if(amount>0){
       Balance = Deposit(amount);
       FreqDeposit++; 
       cout<<endl;
   } else if(amount<0){
       Balance = Withdraw(amount);
       FreqWithDraw++;
       cout<<endl;
   } else{ //if(amount==0) 
       cout<<endl;
       return;
   }
}

// Recursive function. It does the same things as Total(), but
// somehow doesn't have to use a for loop to iterate. Crazy
float SavingsAcct::TotalRecursive(float savint, int time){    
    return Balance*pow((1+savint),time);
}

//Savings Procedure Calculates the balance after at fixed percentage and a set amount of time
 float SavingsAcct::Total(float savint, int time){
     float f=0;     
     for(int i=0;i<time;i++){
         f = Balance*pow((1+savint),time);        
     }
     return f;
 }
 
//Decreases balance if amount is less than or equal to balance
float SavingsAcct::Withdraw(float withdrw){ //Utility Procedure
    
    float bal=Balance;    
    withdrw = abs(withdrw);
    
    //Does not allow withdraw to cause a Negative balance
    if(withdrw<=Balance) 
        {bal -= withdrw;}            
    else 
        {cout<<"Withdraw not Allowed.";}    
    return bal;
}


//Increase balance 
float SavingsAcct::Deposit(float amount){ //Utility Procedure    
    float bal=Balance;     
    bal += amount;    
    return bal;
}


//Print all properties
void SavingsAcct::toString(){
    cout<<"Balance: " << Balance << endl;
    cout<<"FreqDeposit: " << FreqDeposit << endl;
    cout<<"FreqWithdraw: " << FreqWithDraw << endl;
}

#endif /* SAVINGSACCT_H */

