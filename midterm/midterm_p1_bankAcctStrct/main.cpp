/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on October 17, 2022, 10:24 PM
 * Purpose: midterm_prb1_bankAcctStruct
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cctype>
#include <fstream>
using namespace std;

const int SIZE = 6;
const float FEE = (-35.00);

struct Customer {
    //char acct[SIZE];
    string acct,
    name,
    addy;
    float begBal,
    *chks,
    *deps;
};

int main(int argc, char** argv) {

    //declare variables
    fstream inFile;
    int cnt = 1,
            nChks,
            nDeps,
            length;
    float sumChks = 0,
          sumDeps = 0;

    inFile.open("data.txt", ios::in);

    //dynamically create structure
    Customer *cust = nullptr; //define a Customer pointer

    //dynamically allocate an array of Customer structure
    cust = new Customer[cnt];

    //set structure's member values with user inputs
    for (int i = 0; i < cnt; i++) {
        
        
        do {
            cout << "Enter Account Number\n";
            getline(cin, cust[i].acct); //read string & save to member
            length = cust[i].acct.length();

        } while (length > 5 || length < 5); //validate acct # is 5 digits

        
        getline(cin, cust[i].name); //read string & save to member    
        getline(cin, cust[i].addy); //read string & save to member
        cout << "Enter Beginning Balance\n";
        cin >> cust[i].begBal;
        cout << "Enter number of checks written this month\n";
        cin >> nChks;

        //dynamically allocate float array for checks
        cust[i].chks = new float[nChks];

        //loop to enter check amounts into a dynamic array
        for (int chk = 0; chk < nChks; chk++) {

            cout << "Enter check " << chk + 1 << " amount:  ";
            cin >> cust[i].chks[chk];
            sumChks += cust[i].chks[chk];
        }

        cout << "Enter number of deposits made this month. ";
        cin >> nDeps;

        //dynamically allocate float array for checks
        cust[i].deps = new float[nDeps];
        
        //loop to enter each deposit amounts into a dynamic array
        for (int d = 0; d < nDeps; d++) {
            cout << "Enter deposit " << d + 1 << " amount:  ";
            cin >> cust[i].deps[d];
            sumDeps += cust[i].deps[d];
        }
        cin.ignore();
    }
    //display customer's info
    int i=0;
    cout << fixed << setprecision(2);
    cout << "\nAccount #: " << cust[i].acct << endl;
    cout << cust[i].name << endl;
    cout << cust[i].addy << endl;
    cout << "Beginning Balance: " << cust[i].begBal << endl;
    cout << "Checks Written this Month:\n";
    for (int chk = 0; chk < nChks; chk++) {
        cout << cust[i].chks[chk] << endl;
    }
    cout << "Sum of Checks:  " << sumChks << endl;
    
    cout << "Deposits Made this Month:\n";
    for (int d = 0; d < nDeps; d++) {
        cout << cust[i].deps[d] << endl;
    }
    cout << "Sum of Deposits:  " << sumDeps << endl;
    
    float bal = cust[i].begBal + sumDeps - sumChks;
    cout << "Balance: " << bal << endl;
    if(bal<0) {
        bal+= FEE;
        cout << "Overdraft Fee: " << FEE*(-1) << endl
             << "New Balance: " << bal << endl;
    }
    
    //destroy dynamic memory
    for (int i = 0; i < 1; i++) {
        delete []cust[i].chks;
        delete []cust[i].deps;
    }   
    delete []cust;
    cust = nullptr;

    return 0;
}

