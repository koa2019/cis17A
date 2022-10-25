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
    int size,
    hrs;
    float pay;
};

//function prototype
Employee *fillStruct(int &);//fill structure
void calcPay(Employee *, int, float &, float &, float &, float &);//calculate paycheck
string num2wrd(float);//convert float into words for a check
void display(const Employee *, const int, const float, const float, const float, const float);//show paycheck
void destroy(Employee *);//de-allocate dynamic memory

int main(int argc, char** argv) {

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

    return 0;
}

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