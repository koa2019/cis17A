/* File:    main.cpp
 * Author:  Danielle F
 * Created: 12-14-2022 @ 10:21 PM
 * Purpose:  final_cis17a_prb7_menu
*/

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>  //rand()
#include <ctime>    //rand()
#include <iomanip> //setw()
#include <cmath>  //pow()
#include <fstream>  //ifstream
#include <string>  //c_str()
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Prb1Random.h"   //prb1
#include "Prb2Sort.h"     //prb2
#include "Prob3TableInheritd.h" //prb3
#include "SavingsAcct.h"  // prb4 
#include "Prb5Employee.h" //prb5


//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();

void printCharArry(const char *);//prb5


//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));    
    
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
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='6');
    
    //Exit stage right!
    return 0;
}

//******************************************************************************
//                         Menu
//******************************************************************************
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1 Random Sequence"<<endl;
    cout<<"Type 2 for Problem 2 Sort on Column"<<endl;
    cout<<"Type 3 for Problem 3 Table Sum"<<endl;
    cout<<"Type 4 for Problem 4 Savings Account"<<endl;
    cout<<"Type 5 for Problem 5 Employee Class"<<endl;
    cout<<"Type 6 for Problem 6 Scaled Binary"<<endl<<endl;
}

//******************************************************************************
//                         Problem 1 Random Sequence
//******************************************************************************
void prblm1(){
     cout << "\n\nProblem 1\nRandom Sequence's Frequency\n";
     
    //Driver program to return a random sequence
    char n = 5;
    char rndseq[] = {19, 34, 57, 79, 126};
    int ntimes = 100000;
    
    Prb1Random a(n, rndseq);
    
    for (int i = 1; i <= ntimes; i++) {
        a.randFromSet();     
    }   
    
    int *x = a.getFreq();   //set pointer to *freq pointer in Prb1Random class
    
    char *y = a.getSet();   //set pointer to *set pointer in Prb1Random class
    
    //Print results   
    for (int i = 0; i < n; i++) {
        cout << int(y[i]) << " occurred " << x[i] << " times" << endl;
    }  
    
    cout << "The total number of random numbers is " << a.getNumRand() << endl;
}


//******************************************************************************
//                         Problem 2 Sorting
//******************************************************************************
void prblm2(){
        cout << "\n\n\tProblem 2\n      Sorting Class" << endl; 
    
    //Create new object
    Prb2Sort<char> rc;
    //Prb2Sort rc;
  
    bool ascending = true;    
    ifstream infile;
    
    infile.open("Problem2b.txt", ios::in);
    if(!infile) cout<<"Error reading infile\n";
    
    // creating pointer and allocating memory for a char array[160]
    char *ch2 = new char[10*16];
   
    //creating new pointer and initializing it to previous pointer
    char *ch2p = ch2;
    
    int count = 0;
    
    //read in text file
    cout << "\n*ch2 contents:\n";
    while (infile.get(*ch2) ) {         
        cout << *ch2;
        ch2++;               
        count++;
        if(count%16==0)cout<<endl;
    }   
    infile.close();    
    cout<<endl<<endl;
    
    int column;
    do{
        cout << "Which column would you like to sort on? Number between [0,14]" << endl;
        cin>>column;
    }while(column<0 || column>14);
    
    cout<<"\nEnter 1 to sort Ascending or ZERO for Descending order\n";
    cin>>ascending;
   
    
    //Call function that Sorts a 2D array represented as a 1 dim array            
    char *zc = rc.sortArray(ch2p, 10, 16, column, ascending);
    
    string str = ascending==true? " in ascending order" : " in descending order";
    
    cout<<"\nSorted array on column " << column << str <<endl<<endl;
   
    //Print a 1D array like a 2D array. Prints every 16 elements, 10 times
    for(int i=0;i<10;i++){
        for(int j=0;j<16;j++){
            cout<<zc[i*16+j];            
        }    
        cout<<endl;
    }
    
    delete []zc;
  
    cout << endl;
    return;
}

//******************************************************************************
//                         Problem 3
//******************************************************************************
void prblm3(){
        //Declare Variables       
    int rows, cols;                
   
    cout  << "\n\n\tCIS17A Final Problem 3.\n" 
          << "Program Input a table and \noutput the Augment row, col and total sums.\n\n"; 
         
    //Read Inputs for original table
    cout << "Input the number of rows and cols. num<20 for each\n"; 
    //cin >> rows >> cols;
    rows = 5; // for testing purposes. when u dont want to cin everytime
    cols = 6; 
    cout << "Read in rows=" << rows << ",  Number cols=" << cols << endl;  
    
    
    
    //***************************************
    // Create new instance of an object
    //***************************************
    Prob3TableInheritd<int> table(rows,cols);
    
    //Output the original array
    cout<<endl<<"The Original Table\n";
   
    //Create new object and print it
    const int *naugT = table.getTable();
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){                    
           cout << setw(3) << naugT[i*cols+j] <<"  ";                                      
        }
        cout<<endl;
    }   
    cout << endl;
    
    
    //***************************************
    //       Output the augmented array
    //***************************************    
    const int *augT = table.getAugTable();

    cout<<"\n\nThe Augmented Table\n";
    
    for(int i=0;i<=rows;i++){     //changed condition to <=
        for(int j=0;j<=cols;j++){ //changed condition to <=        
      
           cout << setw(3) << augT[i*(cols+1)+j] <<"  ";                                       
        }
        cout<<endl;
    }   
    cout << endl;
    
}

//******************************************************************************
//                         Problem 4
//******************************************************************************
void prblm4(){
   
    //Driver code
    float input=0;
    cout<<"\n\n\tProblem 4\n      Savings Account Class\n";
    cout<<"Input starting balance.\n";
    cin>>input;
 
    SavingsAcct mine(input);
    
    mine.toString();
    cout<<endl;
    
    int max = 32767;
    float amount;
    for (int i = 1; i <= 10; i++) {
        amount = (rand()%500)*(rand()%3-1);
        cout << "Transaction(amount)= " << amount << "  ";
        mine.Transaction(amount);
    }
    mine.toString();
    
    cout << "Balance after 7 years given 10% interest = "
            << mine.Total((0.10),7) << endl;
    cout << "Balance after 7 years given 10% interest = "
            << mine.TotalRecursive((0.10),7)
            << " Recursive Calculation " << endl;
}


//******************************************************************************
//                         Problem 5
//******************************************************************************
void prblm5(){
    cout<<"\nProblem 5\nEmployee Class";
    //Driver Program   
    Prb5Employee Mark("Mark","Boss",215.50);
    Mark.setHrsWrkd(-3);
    printCharArry(Mark.toString());
    
    Mark.CalculatePay(Mark.setHourlyRate(20.0),Mark.setHrsWrkd(25));
    printCharArry(Mark.toString());
    
    Mark.CalculatePay(Mark.setHourlyRate(40.0),Mark.setHrsWrkd(25));
    printCharArry(Mark.toString());
    
    Mark.CalculatePay(Mark.setHourlyRate(60.0),Mark.setHrsWrkd(25));
    printCharArry(Mark.toString());
    
    
    //Second employee
    Prb5Employee Mary("Mary","VP",50.00);
    printCharArry(Mary.toString());
    
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHrsWrkd(40));
    printCharArry(Mary.toString());
    
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHrsWrkd(50));
    printCharArry(Mary.toString());
    
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHrsWrkd(60));
    printCharArry(Mary.toString());
    cout<<"\nEXTRA CREDIT #1 ATTEMPTED for PROB5. RETURNED *char from toString()\n";
}

//Prints *char
void printCharArry(const char *chArry){
    cout<<fixed<<setprecision(2);
    for(int i=0; i<strlen(chArry); i++){
       cout<<fixed<<setprecision(2)<<chArry[i];
    }
    cout<<endl<<endl;
}


//******************************************************************************
//                         Problem 6
//******************************************************************************
void prblm6(){
    cout<<"\n\tProblem 6\n       Conversions\n\n";
    cout<<"5.75 base 10 converted to base 2,8,16\n";
    cout<<"Base 2:  0101.1100\n";
    cout<<"Base 8:   5.60\n";
    cout<<"Base 16:  5.C\n";
    cout<<"NASA format: 0.101 1100 | 0000 0000 | 0000 0000 | 0000 0011\n";
    cout<<"Hex Rep:        5    C      0    0      0    0      0    3\n";
    cout<<"IEEE 754: 0100 0000 1 | 011 1000 0000 0000 0000 0000\n";
    
    cout<<"\n\n0.1 base 10 converted to base 2,8,16\n";
    cout<<"Base 2:  .0001 1001\n";
    cout<<"Base 8:   .063146314...\n";
    cout<<"Base 16:  .1999...\n";
    cout<<"NASA format: 0.110 0110 | 0110 0110 | 0110 0110 | 1111 1101\n";
    cout<<"Hex Rep:        6    6      6    6       6   6      F   D\n";
    cout<<"IEEE 754: 0011 1101 1 | 100 1100 1100 1100 1100 1101\n";
    
    cout<<"\n\n99.7 base 10 converted to base 2,8,16\n";
    cout<<"Base 2:  0011 0110.1011 0011\n";
    cout<<"Base 8:   66.54631466\n";
    cout<<"Base 16:  36.B333...\n";
    cout<<"NASA format: 0.110 1101 | 0110 0110 | 0110 0110 | 0000 0110\n";
    cout<<"Hex Rep:       6     D      6    6      6     6    0     6\n";
    cout<<"IEEE 754: 0100 0010 1 | 100 0111 0110 0110 0110 0110\n\n";
  
    
    //***************************************************
    //  Scaled Binary
    //***************************************************
    cout<<"\n\n\tSCALED BINARY\n\n";
    
    //Declare variables here
    unsigned int input; // input int
    unsigned char value;    //1 byte value
    unsigned char  binary;// 1 byte binary approx
    unsigned short octal; // 2 byte octal approx
    unsigned int   hex;   // 3 byte hex approx
    unsigned int result;
    
    /*********************************************************************
     Convert 5.75 base10 to scaled integer binary 1 unsigned byte max bits 
    **********************************************************************   
     
    * 5.75 base10 => 5.C base16
    * 0101.1100x2^0 base2
    * 0101 1100.0 x2^-4   => shifted right 4 places.  
    * 1011 1000. x2^-5   => shifted right 5 places. For better accuracy
     
    **********************************************************************
     Convert 0.9 base10 to scaled integer binary 2 unsigned byte max bits 
    **********************************************************************
     
    *    0.9 base10 => .E6 base16* 
    *   .1110 0110 0110 0110. 0110 0110 0110x2^0
    *    1 110 011 001 100 110.0x2^-16 => shifted right 16 places 
    *    1  6   3   1   4   6. => octal: 163146  BP=16   
       
    **********************************************************************
     Convert 99.7 base10 to scaled integer binary 3 unsigned byte max bits 
    **********************************************************************
    
        99.7 base10=> 36.B3333... base16
        0011 0110. 1011 0011 0011 0011 0011x2^0...base2
        00 1101 1010 1100 1100 1100 1100.11x2^-18  => DACCCC BP=18
            D    A   C     C    C    C
        11 0110 1011 0011 0011 0011 0011.x2^-20    =>  36B3333  BP=20
         3   6   B    3    3    3    3                 EB3333  */
    
    
    //initialize variables   
    binary=0b10111000;//5.75  1byte-> width=8, BP=5
    octal=0163146;   //0.9    2byte-> width=16, BP=16
    hex=0xEB3333;   //99.7   3byte-> width=24, BP=18 or 20
    
    
    /*********************************************************************
     Convert 5.75 base10 to scaled integer binary 1 unsigned byte max bits 
    **********************************************************************/     
    input=7; 
    value=input;  //width 8, BP 0     
    cout << "5.75 Scaled to Binary 1 byte:  "<<static_cast<int>(binary)<<endl;   
    cout<<"Value:    " <<static_cast<int>(value) <<endl; 
    result=value*binary;//width=8+8=16, BP=0+5=5
    
    cout<<setw(2)<<static_cast<int>(value)<<" x "<<static_cast<int>(binary) <<" = "<<result
        <<endl<<result;
    
    result>>=5;//Shifted 5 places.  width=16-5=11, BP=5-5=0
    
    cout<<" shifted 5 places: "<<result<<endl;    
    cout<<"5.75 x 7 = "<<5.75*7<<endl<<endl;
    
    
    
    /*********************************************************************
     Convert 0.9 base10 to scaled integer binary 2 unsigned byte max bits    
    **********************************************************************/
    cout << "0.9 Scaled to Binary 2 byte:  "<<static_cast<int>(octal)<<endl;
    cout<<"Value:    " <<static_cast<int>(value) <<endl; 
    result = value*octal;//width=8+16=24, BP=0+16 
    
    cout<<setw(2)<<static_cast<int>(value)<<" x "<<static_cast<int>(octal) <<" = "<<result
        <<endl<<result;
    
    result>>=16;//Shifted 16 places. width=24-16=8, BP=16-16=0
    
    cout<<" shifted 16 places: "<<result<<endl;
    cout<<"0.9 x 7 = "<<(0.9*7)<<endl<<endl;
    
    
    
    //***********************************************************************
    // Convert 99.7 base10 to scaled integer binary 3 unsigned byte max bits 
    //***********************************************************************   
    cout << "99.7 Scaled to Binary 3 byte:  "<<static_cast<int>(hex)<<endl;
    cout<<"Value:    " <<static_cast<int>(value) <<endl; 
    
    result = value*hex;//width=8+24=32, BP=0+Y=Y
    
    cout<<setw(2)<<static_cast<int>(value)<<" x "<<static_cast<int>(hex)<<" = "<<result
        <<endl<<result;
    
    result>>=18;//Shifted. width=32-Y= , BP=Y-Y=0
    
    cout<<" shifted 18 places: "<<result<<endl;
    cout<<"99.7 x 7 = "<<99.7*7<<endl<<endl;
}