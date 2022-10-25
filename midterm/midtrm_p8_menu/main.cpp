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
#include <climits> // char and int maximums
#include <cfloat>  //float maximum
using namespace std;

// User Libraries
#include "Customer.h"   // prb1
#include "Employee.h"   // prb2
#include "Primes.h"     //prb 7
#include "Factors.h"    // prb 7

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();

// prb 2 function prototypes
Employee *fillStruct(int &);//fill structure
void calcPay(Employee *, int, float &, float &, float &, float &);//calculate paycheck
string num2wrd(float);//convert float into words for a check
void display(const Employee *, const int, const float, const float, const float, const float);//show paycheck
void destroy(Employee *);//de-allocate dynamic memory

// prb 4 function prototypes
bool getInput(string &);
int *str2IntArr(string);
int *setEncrypt(string, int &, const int, const int);
void prntArry(int *);
int *setDecrypt(int *, int, int);
void swap(int &, int &);

// prb 7 function prototypes
int *setPrimes(int);            // sets prime numbers to an array
Factors *getFactors(int, int,int&);  // calculates prime number factors
void printStruct(Factors *);    // print structure
void destroy(Factors *);        // delete dynamic memory


// app starts here
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
    cout<<"Type 1 for Problem 1: Checking Account"<<endl;
    cout<<"Type 2 for Problem 2: Employee Paycheck"<<endl;
    cout<<"Type 3 for Problem 3: Stats Structure"<<endl;
    cout<<"Type 4 for Problem 4: Encrypt/Decrypt"<<endl;
    cout<<"Type 5 for Problem 5: Data Type Limits"<<endl;
    cout<<"Type 6 for Problem 6: NASA Format"<<endl;
    cout<<"Type 7 for Problem 7: Prime Factorization"<<endl<<endl;
}

// Purpose: midterm_prb1_bankAcctStruct
void prblm1(){
    cin.ignore();
    cout<<"\nChecking Account Balance App\n\n";
    const int SIZE = 6;
    const float FEE = (-35.00);
    //declare variables    
    int  cnt = 1,
          k,    //counter for user input
          nChks,
          nDeps,
          length;
    float sumChks = 0,
          sumDeps = 0;
    bool  isDigt=true;
    
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

            // validates user input are only digits        
            k=0;
            isDigt=true;
            if(length==5){     
                while(k<5 && isDigt){               
                    char d=cust[i].acct[k];
                    if(!(d>='0' && d<='9'))isDigt=false;   
                    else isDigt=true;                                                              
                    k++;
                }                      
            }
        } while (isDigt==0 || length<5 || length>5); //validate acct # is 5 digits

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
    cout<<endl;
    
    //destroy dynamic memory
    for (int i = 0; i < 1; i++) {
        delete []cust[i].chks;
        delete []cust[i].deps;
    }   
    delete []cust;
    cust = nullptr;
}

void prblm2(){
    
    cout<<"\nEmployee Pay Check App\n";
    //declare variables   
    int numEmp = 0,
        numHrs = 0;

    float grossPay = 0,
          dblPay = 0,
          tplPay = 0,
          regPay = 0;

    Employee *emp = nullptr; //define a Employee pointer

    //set structure member value's with user input
    emp = fillStruct(numEmp);

    //CALCULATE grossPay
    calcPay(emp, numEmp, regPay, dblPay, tplPay, grossPay);

    //destroy dynamic memory
    destroy(emp);
}

/**********************PRB2 HELPER FUNCTIONS***********************************/
//calculate employee's paycheck
void calcPay(Employee *emp, int numEmp, float &regPay, float &dblPay, float &tplPay, float &grossPay) {

    //cout<<"\n\nStarting pay calculations\n";
    int tplHrs = 40, regHrs = 20;

    for (int i = 0; i < numEmp; i++) {
  
        //initialize variables for calculations
        int hrsWkd = emp[i].hrs;
        float payRate = emp[i].pay;

        //REGULAR Pay
        if (hrsWkd <= regHrs) {
            regPay = hrsWkd * payRate;
            grossPay = regPay;
          
        }// DOUBLE Pay
        else if (hrsWkd > regHrs && hrsWkd <= tplHrs) {

            int diffHrs = (hrsWkd - regHrs);
            regPay = (hrsWkd - diffHrs) * payRate;
            dblPay = ((hrsWkd - regHrs)*(payRate * 2));
            grossPay = regPay + dblPay;
           
        }//TRIPLE Pay
        else if (hrsWkd > tplHrs) {


            regPay = regHrs * payRate;
            dblPay = (regHrs * (payRate * 2));
            //cout <<"\n\ndblPay= "<< regHrs << " * " << (payRate * 2) << " = "<< dblPay<<endl;
            tplPay = (hrsWkd - tplHrs)*(payRate * 3);
            grossPay = regPay + dblPay + tplPay;
            //cout<<"grossPay in tplPay  " << grossPay << endl;
            //cout<<"hit3x rPay="<<regPay <<"  dPay=" <<dblPay <<" tPay="<<tplPay<<" gPay=" <<grossPay<<endl;

        } else cout << "Else Error\n";
        cout << endl;

        //display single employee's paycheck info
        cout << "                  Printing your check...\n";
        display(emp, i, regPay, dblPay, tplPay, grossPay);
    }
}

//convert grossPay into words
string num2wrd(float gPay) {

    string str = " ", s1, s2, s3, s4 = "";
    int temp = gPay; //mod% doesn't work on floats

    int n1000 = gPay / 1000;
    //cout << "n1000= " << n1000 << endl;   

    switch (n1000) {
        case 10: s1 = "Ten Thousand";   break;
        case 9: s1 = "Nine Thousand ";  break;
        case 8: s1 = "Eight Thousand "; break;
        case 7: s1 = "Seven Thousand "; break;
        case 6: s1 = "Six Thousand ";   break;
        case 5: s1 = "Five Thousand ";  break;
        case 4: s1 = "Four Thousand ";  break;
        case 3: s1 = "Three Thousand "; break;
        case 2: s1 = "Two Thousand ";   break;
        case 1: s1 = "One Thousand ";   break;
        default: s1 = "";
    }

    int n100 = temp % 1000 / 100;
    //cout << "n100= " << n100 << endl;

    s2 = n100 == 9 ? "Nine Hundred" :
            n100 == 8 ? "Eight Hundred " :
            n100 == 7 ? "Seven Hundred " :
            n100 == 6 ? "Six Hundred " :
            n100 == 5 ? "Five Hundred " :
            n100 == 4 ? "Four Hundred " :
            n100 == 3 ? "Three Hundred " :
            n100 == 2 ? "Two Hundred " :
            n100 == 1 ? "One Hundred " : "";

    int n10 = (temp % 100);
    //cout << "n10= " << n10 << endl;

    int n1 = temp % 10;
    //cout << "n1= " << n1 << endl;

    if (n10 >= 20 && n10 <= 90) {
        //cout << "n10-n1= " << n10 - n1 << endl;
        switch (n10 - n1) {
            case 90: s3 = "Ninety ";  break;
            case 80: s3 = "Eighty ";  break;
            case 70: s3 = "Seventy "; break;
            case 60: s3 = "Sixty ";   break;
            case 50: s3 = "Fifty ";   break;
            case 40: s3 = "Forty ";   break;
            case 30: s3 = "Thirty ";  break;
            case 20: s3 = "Twenty ";  break;
            default: s3 = "";
        }

        //only print one's if n10 is not a teen number
        s4 =    n1 == 9 ? "Nine " :
                n1 == 8 ? "Eight " :
                n1 == 7 ? "Seven " :
                n1 == 6 ? "Six " :
                n1 == 5 ? "Five " :
                n1 == 4 ? "Four " :
                n1 == 3 ? "Three " :
                n1 == 2 ? "Two " :
                n1 == 1 ? "One " : "";

    } else {
        s3 = n10 == 19 ? "Nineteen" :
                n10 == 18 ? "Eighteen" :
                n10 == 17 ? "Seventeen" :
                n10 == 16 ? "Sixteen" :
                n10 == 15 ? "Fifteen" :
                n10 == 14 ? "Fourteen" :
                n10 == 13 ? "Thirteen" :
                n10 == 12 ? "Twelve" :
                n10 == 11 ? "Eleven" :
                n10 == 10 ? "Ten " : "";
    }

    str = s1 + s2 + s3 + s4 + "Dollars and  ";

    return str;
}

//display employee paycheck info
void display(const Employee *emp, const int i, const float regPay, const float dblPay, const float tplPay, const float grossPay) {

    int temp;
    float change;
    temp = grossPay;
    change = (grossPay - temp)*100;
    //cout << "change=" << change << endl;
    
    string numStr = "One thousand fourteen dollars and 10/100";
    numStr = num2wrd(grossPay);

    cout << endl << endl
            << "-----------------------------------------------------------------------" << endl;

    cout << fixed << setprecision(2);
    cout << "Pay Stub ending on 10-18-2022\n\n"
            << emp[i].name << endl
            << "Hours Worked:      " << emp[i].hrs << endl
            << "Hourly Rate:       " << emp[i].pay << endl
            << "Regular Pay:       " << regPay << endl
            << "Time and Half Pay: " << dblPay << endl
            << "Triple Pay:        " << tplPay << endl
            << "Gross Pay:         " << grossPay << endl << endl << endl;

    cout << "-----------------------------------------------------------------------" << endl;

    cout << endl << endl << endl;
    cout << setw(40) << left << "Riverside City College" << setw(29) << right << "100" << i << endl
            << setw(18) << left << "6000 Magnolia Ave.\n"
            << setw(40) << "Riverside, CA 92506" << setw(30) << right << "10-18-2022" << endl << endl << endl
            << setw(21) << " " << setw(40) << left << emp[i].name << setw(1) << right << "$" << setw(8) << grossPay << endl
            << endl << left << numStr << setprecision(0) << change << "/100" << endl << endl
            << setw(71) << right << "___________________\n"
            << setw(66) << "Signature\n\n";

    cout << "-----------------------------------------------------------------------" << endl;
}

//fill structure with employee info
Employee *fillStruct(int &numEmp) {

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
    //return filled structure
    return emp;
}

//de-allocate dynamic memory
void destroy(Employee *emp) {
    delete [] emp; //delete array of structures
    emp = nullptr;
}
/**********************END PRB2 FUNCTIONS***********************************/

void prblm3(){
    cout<<"Please see midtrm_p3_statStructure_2 folder for this program.\n";
}

void prblm4(){
    cout<<"Problem 4  Encrypt? Decrypt?\n";
    //declare variables
    const int SIZE = 4;    
    const int ADD6 = 6;
    const int MODBY8 = 8;
    bool   isValid;
    char   ch,
           choice;
    string input;
    int    sum;    
    int    *encryptd,
           *decrypt;

    // validate user input
    do {
        cout << "Enter 1 to encrypt\n"
             << "Enter 2 to decrypt\n";
        cin >> choice;
        
    } while( !(choice-48==1 || choice-48==2)); 

    // menu
    switch (choice) {
        
        // Encrypt 4 digits in it
        case '1': {  
             
            // validate user input is 4 digits between [0,7]
            do {  
                cout << "\nThis program takes a 4 digit integer and "
                     << "Encrypts it and then Decrypts.\n";
                
                isValid = getInput(input);
                
            } while (isValid == false || input.length() != 4);

            // encrypt 4 digits
            encryptd = setEncrypt(input, sum, ADD6, MODBY8);

            // display outputs
            cout << "\nOriginal Digits:  ";
            cout << input;
           
            cout << "\nEncrypted Digits: ";
            prntArry(encryptd);

            decrypt = setDecrypt(encryptd, ADD6, MODBY8);
            cout << "\nDecrypted Digits: ";
            prntArry(decrypt);
            
            break;
            
        } 
        // Accepts an encrypted four digit integer & Decrypt it
        case '2': {
            
            // validate user input is 4 digits between [0,7]
            do {  
                
                cout << "\nThis program takes an already Encrypted 4 digit integer\n"
                     << "and Decrypts it.\n";
                
                isValid = getInput(input);
                
            } while (isValid == false || input.length() != 4);

            // encrypt 4 digits
            encryptd = str2IntArr(input);

            // display outputs
            cout << "\nEncrypted String: ";
            cout << input;
           
            cout << "\nEncrypted Digits: ";
            prntArry(encryptd);

            decrypt = setDecrypt(encryptd, ADD6, MODBY8);
            cout << "\nDecrypted Digits: ";
            prntArry(decrypt);
            
            break;
            
        } default: {
            cout << "Error. Invalid Menu choice.\n";
            return;
        }
    }
    cout<<endl;
    
    // De-allocate dynamic memory    
    delete []encryptd;
    delete []decrypt;    
    encryptd = nullptr;
    decrypt = nullptr;

}
/**********************PRB4 HELPER FUNCTIONS***********************************/
// takes an Encrypted 4 digit integer and Decrypts it to original digits
int *setDecrypt(int *encryptd, int ADD6, int MODBY8) {

    int SIZE = 4;
    int digit,  //holds one integer at a time
        *decrpt = nullptr;  //create null pointer

    // dynamically allocate memory for a new integer array
    decrpt = new int[SIZE];

    // holds a single digit from encrypted array
    int eDigit;

    // 
    for (int i = 0; i < SIZE; i++) {

        eDigit = encryptd[i];

        if (!(eDigit == ADD6 || eDigit == MODBY8 - 1)) {

            digit = (eDigit + MODBY8) - ADD6;
            
        } else {

            digit = eDigit - ADD6;

        }
        decrpt[i] = digit;

    }
    
    // swap index 0 with index 2 AND
    // swap index 1 with index 2    
    swap(decrpt[0],decrpt[2]);       
    swap(decrpt[1],decrpt[3]);
    
    return decrpt;
}


// converts a string to integer array
int *str2IntArr(string input){
    int SIZE = 4;
    // creates new pointer reference and sets it to null
    int *array = nullptr;

    // Dynamically allocate memory for an integer array
    array = new int[SIZE];

    // loop through each array element
    for (int j = 0; j < SIZE; j++) {
        
        // convert each character in string to integer
        array[j] = input[j] - 48;           
    }    
   
    // return pointer 
    return array;
    
}

// sets encrypted array elements
int *setEncrypt(string input, int &sum, const int ADD6, const int MODBY8) {
    int SIZE = 4;
    // creates new pointer reference and sets it to null
    int *array = nullptr;

    // Dynamically allocate memory for an integer array
    array = new int[SIZE];

    // loop through each array element
    for (int j = 0; j < SIZE; j++) {
        
        // convert each character in string to integer
        array[j] = input[j] - 48;  
        
        // Add a number to element value, then modulus sum by 8
        sum = (array[j] + ADD6) % MODBY8;
        
        //set array to the value of sum
        array[j] = sum;
       
    }
    
    // swap index 0 with index 2 AND
    // swap index 1 with index 2   
    swap(array[0],array[2]);       
    swap(array[1],array[3]);
       
    // return pointer 
    return array;
}

// swaps array elements
void swap(int &a, int &b){
    
    int temp = a;
    a = b;
    b = temp;
}

// reads in string and validates user input with a flag
bool getInput(string &input) {
    int SIZE = 4;
    cout << "Enter 4 digits between 0 and 7\n";
    cin >> input;

    for (int i = 0; i < SIZE; i++) {

        if (!(input[i] - 48 >= 0 && input[i] - 48 <= 7)) {
            
            cout << "Invalid digit. ";
            
            return false;       
        } 
    }
    return true;
}

void prntArry(int *array) {
    int SIZE = 4;
    for (int i = 0; i < SIZE; i++) {
        cout << array[i];
    }
}
/**********************END PRB4 FUNCTIONS***********************************/

/**********************PRB 5 FUNCTIONS***********************************/
void prblm5(){
    cout<<"\t\tProblem 5\n";
    cout << "\tFactorial Data Type Limits\n\n";
    int w = 10,
        size = 21,
        sizeLDbl = 172;
    unsigned long long int intFact[size] = {};
    long double lngdblFact[sizeLDbl] = {};
    
/*******************PRINTS UNSIGNED LONG LONG INT FACTORIAL********************************/   
    //cout<<"\nunsigned long long int Factorial\n";
    unsigned long long int fact = 1;
    for (int i = 1; i <= size; i++) {
        fact *= i;
        intFact[i] = fact;
        //cout << setw(2) << i << " " << static_cast<float>(intFact[i])<<endl;
    }

    
/*******************PRINTS LONG DOUBLE FACTORIAL********************************/   
    //cout << "\n\nlong Double Factorial\n";
    long double lngdbl = 1;
    for (int i = 1; i <= sizeLDbl; i++) {
        lngdbl *= i;
        lngdblFact[i] = lngdbl;
        if (i <= 10) {
            //cout << setw(2) << i << " " << static_cast<unsigned long long int> (lngdblFact[i]) << endl;
        } else {
            //cout << setw(2) << i << " " << lngdblFact[i] << endl;
        }
    }

    
/************************************************************************************/

    
    //          signed char    SCHAR_MAX = 127
    int ch1=6;
    int factA = 1;
    //while(factA<SCHAR_MAX || factA>0){
    for (int i = 1; i <= ch1; i++) {
       
            factA *= i;
            //cout<< i << "  " << factA << endl; 
            
    }   
    cout << "\nsigned char 1 byte 8 bits MAX:        " << SCHAR_MAX << "\n";
    cout <<  "signed char Limit             " << setw(1) << ch1-1 << setw(4) << left << "! =    "
            << setw(w) << lngdblFact[ch1-1] << endl;
    
    
 /************************************************************************************/
    
    
    //         unsigned char       UCHAR_MAX = 255
    int ch2=6;
    int factB = 1;
    for (int i = 1; i <= ch2; i++) {
            factB *= i;
            //cout<< i << "  " << factB << endl;    
    }   
    cout << "\nsigned char 1 byte 8 bits MAX:        " << UCHAR_MAX << "\n";
    cout <<  "signed char Limit             " << setw(1) << ch2-1 << setw(4) << left << "! =    "
            << setw(w) << lngdblFact[ch2-1] << endl<<endl;
    

 /************************************************************************************/ 
    
    //                  short int      SHRT_MAX = 32767
        
    int n1 = 8;
    short int fact1 = 1;
    for (int i = 1; i <= n1; i++) {
            fact1 *= i;
        if (!(fact1 == lngdblFact[i])) {
            //cout<< i << "  " << fact1 << endl;
            //cout<< i << "  " << lngdblFact[i] << endl;
            n1 = i;
            break;
        }    
    }   
    // print results
    cout << "\nshort int MAX:               " << SHRT_MAX << "\n";
    cout << "short int Limit      " << setw(1) << n1 - 1 << setw(4) << left << "! =    "
            << setw(w) << intFact[n1 - 1] << endl;
    cout << "short int Overflow   " << setw(1) << n1 << setw(4) << left << "! =   "
            << setw(w) << fact1 << endl;
    cout << "actual value of      " << setw(1) << n1 << setw(4) << left << "! =    "
            << setw(w) << lngdblFact[n1] << endl << endl;

    
/************************************************************************************/
        
            
        // unsigned short int     USHRT_MAX =  .65535 x10^5
        
    int n2 = 9;
    unsigned short int fact2 = 1;
    for (int i = 1; i <= n2; i++) {
            fact2 *= i;
            if (!(fact2 == lngdblFact[i])) {
                //cout<< i << "  " << static_cast<float>(fact2) << endl;
                //cout<< i << "  " << static_cast<float>(lngdblFact[i]) << endl;
            n2 = i;
            break;
            }
            
    }   
    // print results
    cout << "\nunsigned short int MAX:               " << static_cast<float> (USHRT_MAX) << "\n";
    cout << "unsigned short int Limit      " << setw(1) << n2 - 1 << setw(4) << left << "! =    "
            << setw(w) << static_cast<float> (intFact[n2 - 1]) << endl;
    cout << "unsigned short int Overflow   " << setw(1) << n2 << setw(4) << left << "! =    "
            << setw(w) << static_cast<float> (fact2) << endl;
    cout << "actual value of               " << setw(1) << n2 << setw(4) << left << "! =    "
            << setw(w) << lngdblFact[n2] << endl << endl << endl;

    
 //************************************************************************************/


    
    //              INT         INT_MAX = .214748 x10^9    
    int n3 = 13;
    int fact3 = 1;
    for (int i = 1; i <= n3; i++) {
        fact3 *= i;
        if (!(fact3 == lngdblFact[i])) {
            //cout<< i << " " << static_cast<float>(fact3) << endl;
            //cout<< i << "  " << static_cast<float>(lngdblFact[i]) << endl;
            n3 = i;
            break;
        }
    }
    // print results
    cout << "\nint MAX:                  " << static_cast<float> (INT_MAX) << "\n";
    cout << "int Limit        " << setw(2) << n3 - 1 << setw(4) << left << "! =    "
            << setw(w) << static_cast<float> (intFact[n3 - 1]) << endl;
    cout << "int Overflow     " << setw(2) << n3 << setw(4) << left << "! =    "
            << setw(w) << static_cast<float> (fact3) << endl;
    cout << "actual value of  " << setw(2) << n3 << setw(4) << left << "! =    "
            << setw(w) << lngdblFact[n3] << endl << endl << endl;


/************************************************************************************/


    //              unsigned int      UINT_MAX = .429497 x10^9
    int n4 = 13;
    unsigned int fact4 = 1;
    for (int i = 1; i <= n4; i++) {
        fact4 *= i;
        //cout << i << " " << static_cast<float> (fact4) << endl;        
    }

    // print results 
    cout << "\nunsigned int MAX:                " << static_cast<float> (UINT_MAX) << "\n";
    cout << "unsigned int Limit      " << setw(2) << n4 - 1 << setw(4) << left << "! =    "
            << setw(w) << static_cast<float> (intFact[n4 - 1]) << endl;
    cout << "unsigned int Overflow   " << setw(2) << n4 << setw(4) << left << "! =    "
            << setw(w) << static_cast<float> (fact4) << endl;
    cout << "actual value of         " << setw(2) << n4 << setw(4) << left << "! =    "
            << setw(w) << lngdblFact[n4] << endl << endl << endl;


/************************************************************************************/


    //              long int    LONG_MAX = .9223372036854775807 x 10^19
    int n5 = 40;
    long int fact5 = 1;

    for (int i = 1; i <= size; i++) {

        fact5 *= i;
        //cout<< i << " " << static_cast<float>(fact5) << endl;

        if (!(fact5 == lngdblFact[i])) {
            //cout<< i << " " << static_cast<float>(fact5) << endl;
            //cout<< i << "  " << static_cast<float>(lngdblFact[i]) << endl;
            n5 = i;
            break;
        }
    }
    //  print results 
    cout << "\nlong int 4 bytes 64 Bits MAX:         " << static_cast<float> (LONG_MAX) << "\n";
    cout << "long int Limit               " << setw(2) << n5 - 1 << setw(4) << left << "! =    "
            << setw(w + 1) << static_cast<float> (intFact[n5 - 1]) << endl;
    cout << "long int Overflow            " << setw(2) << n5 << setw(4) << left << "! =   "
            << setw(w) << static_cast<float> (fact5) << endl;
    cout << "actual value of              " << setw(2) << n5 << setw(4) << left << "! =    "
            << setw(w) << lngdblFact[n5] << endl << endl << endl;

    
/*****************************************************************************************************/


    //                  long long int   LLONG_MAX =  .9223372036854775807 x10^19
    int n7 = sizeLDbl;
    long long int fact7 = 1;
    for (int i = 1; i <= n7; i++) {

        fact7 *= i;

        if (!(fact7 == lngdblFact[i])) {
            //cout<< i << "  " << static_cast<float>(fact7) << endl;
            //cout<< i << "  " << static_cast<float>(lngdblFact[i]) << endl;
            n7 = i;
            break;
        }
    }

    // print results
    cout << "\nlong long int 8 bytes 64 Bits MAX:         " << static_cast<float> (LLONG_MAX) << "\n";
    cout << "long long int Limit               " << setw(2) << n7 - 1 << setw(4) << left << "! =    "
            << setw(w) << static_cast<float> (intFact[n7 - 1]) << endl;
    cout << "long long int Overflow            " << setw(2) << n7 << setw(4) << left << "! =   "
            << setw(w) << static_cast<float> (fact7) << endl;
    cout << "actual value of                   " << setw(2) << n7 << setw(4) << left << "! =    "
            << setw(w) << lngdblFact[n7] << endl << endl << endl;


/*****************************************************************************************************/


    //              unsigned long int     ULONG_MAX = .18446744073709551615 x 10^20    
    int n6 = 40;
    unsigned long int fact6 = 1;
    for (int i = 1; i <= 40; i++) {

        fact6 *= i;
        //cout<< i << "  " << static_cast<float>(fact6) << endl;
        if (!(fact6 == lngdblFact[i])) {
            //cout<< i << "  " << static_cast<float>(fact6) << endl;
            //cout<< i << "  " << static_cast<float>(lngdblFact[i]) << endl;
            n6 = i;
            break;
        }
    }

    // print results
    cout << "\nunsigned long int 4 bytes 64 Bits MAX:         " << static_cast<float> (ULONG_MAX) << "\n";
    cout << "unsigned long int Limit               " << setw(2) << n6 - 1 << setw(4) << left << "! =    "
            << setw(w) << static_cast<float> (intFact[n6 - 1]) << endl;
    cout << "unsigned long int Overflow            " << setw(2) << n6 << setw(4) << left << "! =    "
            << setw(w) << static_cast<float> (fact6) << endl;
    cout << "actual value of                       " << setw(2) << n6 << setw(4) << left << "! =    "
            << setw(w) << lngdblFact[n6] << endl << endl << endl;



/*****************************************************************************************************/


    //                  unsigned long long int   ULLONG_MAX =  .18446744073709551615 x10^20
    int n8 = sizeLDbl;
    unsigned long long int fact8 = 1;
    for (int i = 1; i <= n8; i++) {

        fact8 *= i;
        //cout<< i << "  " << static_cast<float>(fact8) << endl;
        if (!(fact8 == lngdblFact[i])) {
            //cout<< i << "  " << static_cast<float>(fact8) << endl;
            //cout<< i << "  " << static_cast<float>(lngdblFact[i]) << endl;
            n8 = i;
            break;
        }
    }

    // print results
    cout << "\nunsigned long long int 8 bytes 64 Bits MAX:         " << static_cast<float> (ULLONG_MAX) << "\n";
    cout << "unsigned long long int Limit               " << setw(2) << n8 - 1 << setw(4) << left << "! =    "
            << setw(w) << static_cast<float> (intFact[n8 - 1]) << endl;
    cout << "unsigned long long int Overflow            " << setw(2) << n8 << setw(4) << left << "! =    "
            << setw(w) << static_cast<float> (fact8) << endl;
    cout << "actual value of                            " << setw(2) << n8 << setw(4) << left << "! =    "
            << setw(w) << lngdblFact[n8] << endl << endl << endl;


 /****************************************************************************************************/


    //              float FLT_MAX =  .340282 x10^39
    int n9 = 35;
    float fact9 = 1;
    for (int i = 1; i <= n9; i++) {

        fact9 *= i;
        //cout<< i << "  " << fact9 << endl;
        //        if(!(fact9 == ){        //            
        //            cout<< i << "  " << fact9 << endl;
        //            cout<< i << "  " << lngdblFact[i] << endl;        //            
        //            n9 = i;
        //            break;
        //        }         
    }

    // print results
    cout << "\nfloat 4 bytes 32 Bits MAX:         " << FLT_MAX << "\n";
    cout << "float Limit               " << setw(2) << n9 - 1 << setw(4) << left << "! =    "
            << setw(w) << lngdblFact[n9 - 1] << endl;
    cout << "float Overflow            " << setw(2) << n9 << setw(4) << left << "! =    "
            << setw(w) << fact9 << endl;
    cout << "actual value of           " << setw(2) << n9 << setw(4) << left << "! =    "
            << setw(w) << lngdblFact[n9] << endl << endl << endl;


/****************************************************************************************************/


    //                  double         DBL_MAX =  .179769 x10^308
    int n10 = 171;
    double fact10 = 1;
    for (int i = 1; i <= n10; i++) {

        fact10 *= i;
        //cout<< i << "  " << fact10 << endl;       
    }

    // print results
    cout << "\ndouble 8 bytes 64 Bits MAX:         " << DBL_MAX << "\n";
    cout << "double Limit              " << setw(2) << n10 - 1 << setw(4) << left << "! =    "
            << setw(w) << lngdblFact[n10 - 1] << endl;
    cout << "double Overflow           " << setw(2) << n10 << setw(4) << left << "! =    "
            << setw(14) << fact10 << endl;
    cout << "actual value of           " << setw(2) << n10 << setw(4) << left << "! =    "
            << setw(w) << lngdblFact[n10] << endl << endl << endl;


/****************************************************************************************************/


    //                  long double         LDBL_MAX = .118973 x10^4932
    int n11 = 1754;
    long double fact11 = 1.0;
    for (int i = 1; i <= n11; i++) {

        fact11 *= i;
        if (i > 1750) {
            //cout << i << "  " << fact11 << endl;
        }
    }

    // print results
    cout << "\nlong double 16 bytes 128 Bits MAX:           " << setw(14)<<LDBL_MAX << "\n";
    cout << "long double Limit                 " << setw(2) << n11 - 1 << setw(4) << left << "! =    "
            << setw(w) << fact11 << endl;
    //    cout <<   "long double Overflow                             " << setw(2) << n11 << setw(4) << left << "! =    "
    //         << setw(w) << fact11 <<endl;
    //    cout <<   "actual value of                             " << setw(2) << n11 << setw(4) << left << "! =    "
    //         << setw(w) << lngdblFact[n11] << endl << endl << endl;

}


// Purpose: midterm_prb6_nasaFormat_conversions  
void prblm6(){   
    cout << "\t\tProblem 6  Nasa Format\n\n";
    cout << "\n Base 10     Base 16    Base 2        Base 8   Hex Rep     -Hex Rep\n";
    cout <<   " 49.1875      31.3    00110001.0011   61.14    62600006    9DA00006\n\n";
    cout <<   " 3.07421875   3.13    0011.00010011   3.046    62600002    9DA00002\n\n";
    cout <<   " 0.20         0.3     0.0011          0.1463   66666682    A00000FE\n\n";
    
    cout << "\n Hex Rep     Base 2                  Base 16        Base 10       \n";
    cout <<   " 69999902    0011.0100(1100repeat)   3.4CCCC8    3.2999999713\n\n";
    cout <<   " 69999903    0110.(1001repeat)       6.999999    6.5999994278\n\n";
    cout <<   " 966667FF    .0110(1001repeat)       0.699999    0.4124999642\n\n";
}

// 
void prblm7(){
    cout<<"Problem 7  Prime Factorization\n";
    // declare variables
    int size = 25, // find primes up to 100, but half will be eliminated because their even #s
        num = 65000,
        q=0;

    do{
        cout<<"Enter a number between 0 and 65000 \n";
        cin>>num;
    }while(num<0 || num>65000);
    
    // declare new pointer to structure    
    Factors *factors; 

    // set structure with data
    factors = getFactors(size, num,q);

    // print primes numbers in array
   
     //if (!(quot % primes[count])) {
    if(q==num){
        cout << q << " has NO prime factors.\n";       
    } else {
        cout << "\nPrime Factors of " << num << endl;
        printStruct(factors);
    }
    cout<<endl;
    
    // delete dynamic memory
    destroy(factors);
}
/**********************PRB7 HELPER FUNCTIONS***********************************/
// print structure members
void printStruct(Factors *factors) {

   
    for (int i = 0; i < factors->size; i++) {

        if (factors->primes[i].power > 0) {
            cout << factors->primes[i].p << "^"
                    << factors->primes[i].power;
            if (i != (factors->size) - 1) cout << " * ";
            else cout << "";
        }
    }
    
}

// factor prime numbers out of a given #
Factors *getFactors(int s, int num,int &quot) {
    
    // declare & set variables
    int pwr = 0,    // counts how many times a prime # is divisible        
        count = 0;  //loop counter
    
    quot = num; // quotient represents whole number after division
    
    // declare new pointer to structure Primes & initialize pointer with an int array 
    Factors *factors = new Factors;

    // set structure's member value
    factors->size = s;
    //cout << factors->size << endl;

    // created an array inside Factors structure
    factors->primes = new Primes[factors->size];
   
    // call function to get prime #s between [2,100]
    int *primes = setPrimes(s);

    do {        
        
        //cout<<count<<"  " << primes[count]<<endl;
        // if quotient is divisible by current prime #
        while ((quot % primes[count]) == 0) {

            // save current prime # to structure's member
            factors->primes[count].p = primes[count];

            // divide quotient by current prime #
            quot = quot / primes[count];
            //cout << "quot/ "<< primes[count] << " = " << quot << endl;
            
            // increment how many times current prime can be even divided into quot
            pwr++;
        }

        // set structure's member value
        factors->primes[count].power = pwr;
        
        // increment for next loop iteration
        count++;
        //cout<<count<<endl;
        
        // reset counter
        pwr = 0;

    } while (quot > 1 && count<=25);  // stop when quot == 1

    // reset size according to count
    factors->size = count;

    // return pointer
    return factors;
}

// find prime #s between [2,100] & set in an array
int *setPrimes(int n) {

    // declare & set counter
    int cnt = 0;

    // declare new pointer & initialize it with an array
    int *primes = new int[n];

    // fill structure prime[ ] with prime #s from [2,100]
    for (int i = 2; i < 100; i++) {

        // 2 is always the first prime number
        if (i == 2) {

            primes[cnt] = i;
            //cout << cnt << "  " << primes[cnt] << endl;
            cnt++;
        }
        
        // checks for odd numbers
        else if (!(i % 2 == 0)) {

            // 3,5,7,9,11 are non-divisible so set as prime
            if ((i == 3 || i == 5 || i == 7 || i == 9 || i == 11)) {

                primes[cnt] = i;
                //cout << cnt << "  "  << primes[cnt] << endl;
                cnt++;
            }
            
            // eliminate #s that are divisible by 3,5,7,9,11
            if (!(i % 3 == 0 || i % 5 == 0 || i % 7 == 0 || i % 9 == 0 || i == 11)) {
                primes[cnt] = i;
                //cout << cnt << "  "  << primes[cnt] << endl;
                cnt++;
            }
        } else cout << "";
    }
    return primes;
}

void destroy(Factors *ptrPrim) {

    //for(int i=0;i<(ptrPrim->size);i++){
    //    delete [] ptrPrim->primes;
    //}
    delete [] ptrPrim; // delete array of structures  

}
/**********************END PRB7 FUNCTIONS***********************************/
