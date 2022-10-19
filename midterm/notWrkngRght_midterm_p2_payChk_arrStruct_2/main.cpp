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
Employee *fillStruct(int &);
void calcPay(Employee *,int,float &,float &,float &,float &);
void display(const Employee *,const int,const float,const float,const float,const float);
void destroy(Employee *);


int main(int argc, char** argv) {

    //declare variables   
    int     numEmp = 0,
            numHrs = 0;

    float grossPay = 0,
            dblPay = 0,
            tplPay = 0, 
            regPay = 0;

    Employee *emp = nullptr; //define a Employee pointer
    
    //set structure member value's with user input
    emp=fillStruct(numEmp);
    
    //CALCULATE grossPay
    calcPay(emp,numEmp,regPay,dblPay,tplPay,grossPay);
    
   //display employee's pay check info
    display(emp,numEmp,regPay,dblPay,tplPay,grossPay);

    //destroy dynamic memory
    destroy(emp);

    return 0;
}
//
void calcPay(Employee *emp,int numEmp,float &regPay,float &dblPay,float &tplPay,float &grossPay){
    
    cout<<"\n\nStarting pay calculations\n";
    int tplHrs = 40, regHrs = 20;

    for (int i = 0; i < numEmp; i++) {

        cout << emp[i].name << "   i=" << i << "  numEmp=" << numEmp<<endl
             << "rPay=" << regPay <<"  dbl="<<dblPay  <<"  tpl="<<tplPay << " gPay"<<grossPay<<endl;
        
        //initialize variables for calculations
        int hrsWkd = emp[i].hrs;
        float payRate = emp[i].pay;

        cout << emp[i].name <<" " << "hrsWk="<<hrsWkd << "  payRate="<<payRate <<endl;
        
        //REGULAR Pay
        if (hrsWkd <= regHrs) {
            regPay = hrsWkd * payRate;
            grossPay = regPay;
            cout<<"Hit regPay="<<regPay <<"  gPay=" <<grossPay<<endl;
        }
        // DOUBLE Pay
        else if (hrsWkd > regHrs && hrsWkd <= tplHrs) {

            int diffHrs = (hrsWkd - regHrs);
            regPay = (hrsWkd - diffHrs) * payRate;
            dblPay = ((hrsWkd - regHrs)*(payRate * 2));
            grossPay = regPay + dblPay;
            cout<<"Hit2 rPay="<<regPay <<"  dPay=" <<dblPay <<" gPay=" <<grossPay<<endl;
        }
        //TRIPLE Pay
        else if (hrsWkd > tplHrs) {

            
            regPay = regHrs * payRate;
            dblPay = (regHrs * (payRate * 2));
            //cout <<"\n\ndblPay= "<< regHrs << " * " << (payRate * 2) << " = "<< dblPay<<endl;
            tplPay = (hrsWkd - tplHrs)*(payRate * 3);
            grossPay = regPay + dblPay + tplPay;
            //cout<<"grossPay in tplPay  " << grossPay << endl;
            cout<<"hit3x rPay="<<regPay <<"  dPay=" <<dblPay <<" tPay="<<tplPay<<" gPay=" <<grossPay<<endl;
            
        } else cout << "Else Error\n";
        cout<<endl;
    }  
}

//
void display(const Employee *emp,const int numEmp,const float regPay,const float dblPay,const float tplPay,const  float grossPay){
    
    cout<<"\ndisp() rPay="<<regPay <<"  dPay=" <<dblPay <<" tPay="<<tplPay<<" gPay=" <<grossPay<<endl;
            
    for (int i = 0; i < numEmp; i++) {
        
        cout <<endl<<endl<<endl
             << "-----------------------------------------------------------------------"<<endl;

        cout << fixed << setprecision(2);
        cout << "Pay Stub ending on 10-18-2022\n\n"
             << emp[i].name << endl 
             << "Hours Worked:      " << emp[i].hrs << endl
             << "Hourly Rate:       " << emp[i].pay << endl
             << "Regular Pay:       " << regPay << endl
             << "Time and Half Pay: " << dblPay << endl
             << "Triple Pay:        " << tplPay << endl
             << "Gross Pay:         " << grossPay << endl<< endl<< endl;
        
        cout << "-----------------------------------------------------------------------"<<endl;
        
//        cout<<endl<<endl<<endl;
//        cout << setw(40) << left << "Riverside City College" << setw(31) << right << "1001\n"
//             << setw(18) << left << "6000 Magnolia Ave.\n" 
//             << setw(40) << "Riverside, CA 92506" << setw(30) << right << "10-18-2022" << endl<< endl<< endl
//             << setw(21) << " " << setw(40) << left << emp[i].name << setw(1) << right <<"$" <<setw(8) << grossPay << endl
//             << endl << setw(76) << left  << "One thousand fourteen dollars and 10/100\n\n"
//             << setw(37) << right << "___________________\n"
//             << setw(66) << "Signature\n\n";
//        
//        cout << "-----------------------------------------------------------------------"<<endl;

    }
}


//fill structure with employee info
Employee *fillStruct(int &numEmp){
    
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

void destroy(Employee *emp){
    
    delete [] emp;  //delete array of structures
    emp = nullptr;
}