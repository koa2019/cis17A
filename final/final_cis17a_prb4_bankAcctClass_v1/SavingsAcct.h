/* 
 * File:   SavingsAcct.h
 * Author: DanYell
 * Created on December 14, 2022, 10:10 PM
*/

#ifndef SAVINGSACCT_H
#define SAVINGSACCT_H

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

#endif /* SAVINGSACCT_H */

