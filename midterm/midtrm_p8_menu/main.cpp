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
//prb1
struct Customer {
    //char acct[SIZE];
    string acct,
    name,
    addy;
    float begBal,
    *chks,
    *deps;
};

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();


int main(int argc, char** argv) {

    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
    
    return 0;
}

void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<"Type 7 for Problem 7"<<endl<<endl;
}

// Purpose: midterm_prb1_bankAcctStruct
void prblm1(){
    cin.ignore();
    cout<<"\nChecking Account Balance App\n\n";
    const int SIZE = 6;
    const float FEE = (-35.00);
    //declare variables    
    int cnt = 1,
            nChks,
            nDeps,
            length;
    float sumChks = 0,
          sumDeps = 0;

    //dynamically create structure
    Customer *cust = nullptr; //define a Customer pointer

    //dynamically allocate an array of Customer structure
    cust = new Customer[cnt];

    //set structure's member values with user inputs
    for (int i = 0; i < cnt; i++) {             
        do {
            cout << "Enter 5 digit Account Number\n";
            getline(cin, cust[i].acct); //read string & save to member
            length = cust[i].acct.length();
            //cout <<"leng "<< length <<endl;

        } while (length<5 || length>5); //validate acct # is 5 digits

        cout << "Enter your name:  ";
        getline(cin, cust[i].name); //read string & save to member     
        cout<<"Enter your address:  ";
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
    cout << "Beginning Balance: " << cust[i].begBal <<endl<< endl;
    cout << nChks << " Checks Written this Month:\n";
    for (int chk = 0; chk < nChks; chk++) {
        cout << cust[i].chks[chk] << endl;
    }
    cout << "Sum of Checks:  " << sumChks <<endl<<endl;
    
    cout << nDeps << " Deposits Made this Month:\n";
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
}

void prblm2(){
    
}
void prblm3(){
    cout<<"Please see midtrm_p3_statStructure_2 folder for this program.\n";
}

void prblm4(){
    
}
void prblm5(){
    
}

// Purpose: midterm_prb6_nasaFormat_conversions  
void prblm6(){     
    cout << "\n  B10         B16      B2              B8      Hex Rep    -Hex Rep\n";
    cout <<   " 49.1875     31.3    00110001.0011   61.14    62600006    9DA00006\n\n";
    cout <<   " 3.07421875  3.13    0011.00010011   3.046    62600002    9DA00002\n\n";
    cout <<   " 0.20        0.3     0.0011          0.1463   66666682    A00000FE\n\n";
    
    cout << "\n Hex Rep     B2                      B16         B10       \n";
    cout <<   " 69999902    0011.0100(1100repeat)   3.4CCCC8    3.2999999713\n\n";
    cout <<   " 69999903    0110.(1001repeat)       6.999999    6.5999994278\n\n";
    cout <<   " 966667FF    .0110(1001repeat)       0.699999    0.4124999642\n\n";
}

// 
void prblm7(){
    
}



