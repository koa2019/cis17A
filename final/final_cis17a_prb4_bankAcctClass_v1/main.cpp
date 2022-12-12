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
#include <iomanip>
#include <cmath>
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
   } else if(amount<0){
       Balance = Withdraw(amount);
       FreqWithDraw++;
   }else{ //if(amount==0) 
       return;
   }
}

//Savings Procedure
 float SavingsAcct::Total(float savint, int time){
     float f;
     
     for(int i=0;i<time;i++){
         //f = Balance*(1+savint)^time;
         f = Balance*(1+savint);
         //f = pow(Balance,time);
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
        {cout<<"Withdraw not Allowed.\n";}
    
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

int main(int argc, char** argv) {

    //Driver code
    //SavingsAcct mine(-300);
    SavingsAcct mine(100);
    
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
            << mine.Total(0.10, 7) << endl;
//    cout << "Balance after 7 years given 10% interest = "
//            << mine.TotalRecursive((float) (0.10), 7)
//            << " Recursive Calculation " << endl;
    
    
    return 0;
}

