/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on October 18, 2022, 6:06 PM
 * Purpose: midterm_prb2_payChk_arrStruct
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cctype>
#include <fstream>
using namespace std;

struct Employee {
    string name;
    int hrs;
    float pay;
};

int main(int argc, char** argv) {

    //declare variables   
    int     numEmp = 0,
            numHrs = 0;

    float grossPay = 0,
            dblPay = 0,
            tplPay = 0, 
            regPay = 0;

    cout << "How many employee's would you like to add today?  ";
    cin >> numEmp;

    //dynamically create structure
    Employee *emp = nullptr; //define a Employee pointer

    //dynamically allocate an array of Employee structure
    emp = new Employee[numEmp];

    //SET Employee structure's member values with user inputs
    for (int i = 0; i < numEmp; i++) {

        cin.ignore();

        cout << "Enter Employee's Name\n";
        getline(cin, emp[i].name); //read string & save to member


        do {
            cout << "Enter number of hours worked:   ";
            cin >> emp[i].hrs;

        } while (emp[i].hrs < 0); //number of hours can NOT be negative


        do {
            cout << "Enter Pay Rate per hour:   ";
            cin >> emp[i].pay;

        } while (emp[i].pay < 0); //Pay can NOT be negative
    }

    //CALCULATE grossPay
    int tplHrs = 40, regHrs = 20;

    for (int i = 0; i < numEmp; i++) {

        int hrsWkd = emp[i].hrs;
        float payRate = emp[i].pay;

        if (hrsWkd <= regHrs) {
            regPay = hrsWkd * payRate;
            grossPay = regPay;
        }
        // DOUBLE Pay
        else if (hrsWkd > regHrs && hrsWkd <= tplHrs) {

            int diffHrs = (hrsWkd - regHrs);
            regPay = (hrsWkd - diffHrs) * payRate;
            dblPay = (hrsWkd - regHrs)*(payRate * 2);
            grossPay = regPay + dblPay;
        }
        //TRIPLE Pay
        else if (hrsWkd > tplHrs) {

            regPay = regHrs * payRate;
            dblPay = (regHrs * (payRate * 2));
            tplPay = (hrsWkd - tplHrs)*(payRate * 3);
            grossPay = regPay + dblPay + tplPay;
            
        } else cout << "Else Error\n";
    }

    //display employee's pay check info
    for (int i = 0; i < numEmp; i++) {
        
        cout << fixed << setprecision(2)<<endl<<endl<<endl<<endl;
        cout << "Pay Stub ending on 10-18-2022\n\n"
             << emp[i].name << endl 
             << "Hours Worked:      " << emp[i].hrs << endl
             << "Hourly Rate:       " << emp[i].pay << endl
             << "Regular Pay:       " << regPay << endl
             << "Time and Half Pay: " << dblPay << endl
             << "Triple Pay:        " << tplPay << endl
             << "Gross Pay:         " << grossPay << endl<< endl<< endl;
        
        cout << "-----------------------------------------------------------------------"<<endl;
        
        cout<<endl<<endl<<endl;
        cout << setw(40) << left << "Riverside City College" << setw(31) << right << "1001\n"
             << setw(18) << left << "6000 Magnolia Ave.\n" 
             << setw(40) << "Riverside, CA 92506" << setw(30) << right << "10-18-2022" << endl<< endl<< endl
             << setw(21) << " " << setw(40) << left << emp[i].name << setw(1) << right <<"$" <<setw(8) << grossPay << endl
             << endl << setw(76) << left  << "One thousand fourteen dollars and 10/100\n\n"
             << setw(37) << right << "___________________\n"
             << setw(66) << "Signature\n";
    }




    //destroy dynamic memory
    for (int i = 0; i < 1; i++) {
        //        delete []emp[i].chks;
        //        delete []emp[i].deps;
    }
    delete [] emp;
    emp = nullptr;

    return 0;
}

