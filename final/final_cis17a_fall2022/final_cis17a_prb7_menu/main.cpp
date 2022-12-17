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
using namespace std; //STD Name-space where Library is compiled

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

void printCharArry(const char *); //prb5

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int> (time(0)));

    //Declare Variables
    char choice;

    //Loop and Display menu
    do {
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch (choice) {
            case '1':
            {
                prblm1();
                break;
            }
            case '2':
            {
                prblm2();
                break;
            }
            case '3':
            {
                prblm3();
                break;
            }
            case '4':
            {
                prblm4();
                break;
            }
            case '5':
            {
                prblm5();
                break;
            }
            case '6':
            {
                prblm6();
                break;
            }
            default: cout << "Exiting Menu" << endl;
        }
    } while (choice >= '1' && choice <= '6');

    //Exit stage right!
    return 0;
}

//******************************************************************************
//                         Menu
//******************************************************************************

void menu() {
    //Display menu
    cout << "\n\n************************************\n\n";
    cout << "Choose from the following Menu" << endl;
    cout << "Type 1 for Problem 1 Random Sequence" << endl;
    cout << "Type 2 for Problem 2 Sort on Column" << endl;
    cout << "Type 3 for Problem 3 Table Sum" << endl;
    cout << "Type 4 for Problem 4 Savings Account" << endl;
    cout << "Type 5 for Problem 5 Employee Class" << endl;
    cout << "Type 6 for Problem 6 Scaled Binary\n";
    cout << "\n************************************\n\n";
}

//******************************************************************************
//                         Problem 1 Random Sequence
//******************************************************************************

void prblm1() {
    cout << "\n\n\tProblem 1\nRandom Sequence's Frequency\n";

    //Driver program to return a random sequence
    char n = 5;
    char rndseq[] = {19, 34, 57, 79, 126};
    int ntimes = 100000;

    Prb1Random a(n, rndseq);

    for (int i = 1; i <= ntimes; i++) {
        a.randFromSet();
    }

    int *x = a.getFreq(); //set pointer to *freq pointer in Prb1Random class

    char *y = a.getSet(); //set pointer to *set pointer in Prb1Random class

    //Print results   
    for (int i = 0; i < n; i++) {
        cout << int(y[i]) << " occurred " << x[i] << " times" << endl;
    }

    cout << "The total number of random numbers is " << a.getNumRand() << endl;
}


//******************************************************************************
//                         Problem 2 Sorting
//******************************************************************************

void prblm2() {
    cout << "\n\n\tProblem 2\n      Sorting Class" << endl;

    //Create new object
    Prb2Sort<char> rc;

    int input = 0;
    bool ascending;
    ifstream infile;
    ascending = true;

    infile.open("Problem2b.txt", ios::in);
    if (!infile) cout << "Error reading infile\n";

    // creating pointer and allocating memory for a char array[160]
    char *ch2 = new char[10 * 16];

    //creating new pointer and initializing it to previous pointer
    char *ch2p = ch2;

    int count = 0;

    //read in text file
    cout << "\n*ch2 contents:\n";
    while (infile.get(*ch2)) {
        cout << *ch2;
        ch2++;
        count++;
        if (count % 16 == 0)cout << endl;
    }
    infile.close();
    cout << endl << endl;

    int column;
    do {
        cout<<"Which column would you like to sort on? Number between [0,14]" << endl;
        cin>>column;
    } while (column < 0 || column > 14);

    cout<<"\nEnter 1 to sort Ascending or ZERO for Descending order\n";
    cin>>input;

    ascending = input == 0 ? false : true;

    try {
        //Call function that Sorts a 2D array represented as a 1 dim array            
        char *zc = rc.sortArray(ch2p, 10, 16, column, ascending);

        string str = ascending == true ? " in ascending order" : " in descending order";

        cout << "\nSorted array on column " << column << str << endl << endl;

        //Print a 1D array like a 2D array. Prints every 16 elements, 10 times
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 16; j++) {
                cout << zc[i * 16 + j];
            }
            cout << endl;
        }

        delete []zc;
        
    } catch (Prb2Sort<char>::BadBool) {
        if (ascending == true) {
            cout << "\nCAUGHT! Error in ascending==true\n";
        } else {
            cout << "\nCAUGHT! Error in ascending==false\n";
        }
    }

    cout << endl;

}

//******************************************************************************
//                         Problem 3
//******************************************************************************

void prblm3() {
     cout << "\n\n\tProblem 3.\n\nAugmented Table Sums\n\n";
   
    //Declare Variables       
    int rows, cols;
    
    //Read Inputs for original table
    cout << "Input the number of rows and cols. num<20 for each\n";
    //cin >> rows >> cols;
    rows = 5; // for testing purposes. when u dont want to cin everytime
    cols = 6;
    cout << "Read in rows=" << rows << ",  Number cols=" << cols << endl;



    //***************************************
    // Create new instance of an object
    //***************************************
    Prob3TableInheritd<int> table(rows, cols);

    //Output the original array
    cout << endl << "The Original Table\n";

    //Create new object and print it
    const int *naugT = table.getTable();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(3) << naugT[i * cols + j] << "  ";
        }
        cout << endl;
    }
    cout << endl;


    //***************************************
    //       Output the augmented array
    //***************************************    
    const int *augT = table.getAugTable();

    cout << "\n\nThe Augmented Table\n";

    for (int i = 0; i <= rows; i++) { //changed condition to <=
        for (int j = 0; j <= cols; j++) { //changed condition to <=        

            cout << setw(3) << augT[i * (cols + 1) + j] << "  ";
        }
        cout << endl;
    }
    cout << endl;

}

//******************************************************************************
//                         Problem 4
//******************************************************************************

void prblm4() {

    //Driver code
    float input = 0;
    cout << "\n\n\tProblem 4\n      Savings Account Class\n";
    cout << "Input starting balance.\n";
    cin>>input;

    SavingsAcct mine(input);

    mine.toString();
    cout << endl;

    int max = 32767;
    float amount;
    for (int i = 1; i <= 10; i++) {
        amount = (rand() % 500)*(rand() % 3 - 1);
        cout << "Transaction(amount)= " << amount << "  ";
        mine.Transaction(amount);
    }
    mine.toString();

    cout << "Balance after 7 years given 10% interest = "
            << mine.Total((0.10), 7) << endl;
    cout << "Balance after 7 years given 10% interest = "
            << mine.TotalRecursive((0.10), 7)
            << " Recursive Calculation " << endl;
}


//******************************************************************************
//                         Problem 5
//******************************************************************************

void prblm5() {
    cout << "\n\tProblem 5\nEmployee Class";
    //Driver Program   
    Prb5Employee Mark("Mark", "Boss", 215.50);
    Mark.setHrsWrkd(-3);
    printCharArry(Mark.toString());

    Mark.CalculatePay(Mark.setHourlyRate(20.0), Mark.setHrsWrkd(25));
    printCharArry(Mark.toString());

    Mark.CalculatePay(Mark.setHourlyRate(40.0), Mark.setHrsWrkd(25));
    printCharArry(Mark.toString());

    Mark.CalculatePay(Mark.setHourlyRate(60.0), Mark.setHrsWrkd(25));
    printCharArry(Mark.toString());


    //Second employee
    Prb5Employee Mary("Mary", "VP", 50.00);
    printCharArry(Mary.toString());

    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHrsWrkd(40));
    printCharArry(Mary.toString());

    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHrsWrkd(50));
    printCharArry(Mary.toString());

    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHrsWrkd(60));
    printCharArry(Mary.toString());
    cout << "\nEXTRA CREDIT #1 ATTEMPTED for PROB5. RETURNED *char from toString()\n";
}

//Prints *char for prob 5
void printCharArry(const char *chArry) {
    cout << fixed << setprecision(2);
    for (int i = 0; i < strlen(chArry); i++) {
        cout << fixed << setprecision(2) << chArry[i];
    }
    cout << endl << endl;
}


//******************************************************************************
//                         Problem 6
//******************************************************************************

void prblm6() {
    cout << "\n\n\tProblem 6 Conversions\n\n";
    cout << "5.75 base 10 converted to base 2,8,16\n\n";
    cout << "Base 2:   0101.1100\n";
    cout << "Base 8:   5.6\n";
    cout << "Base 16:  5.C\n";
    cout << "NASA format: 0.101 1100 | 0000 0000 | 0000 0000 | 0000 0011\n";
    cout << "Hex Rep:        5    C      0    0      0    0      0    3\n";
    cout << "IEEE 754:    0100 0000 1 | 011 1000 0000 0000 0000 0000\n";

    cout << "\n\n0.9 base 10 converted to base 2,8,16\n\n";
    cout << "Base 2:   .1110 0110 0110...\n";
    cout << "Base 8:   .7146\n";
    cout << "Base 16:  .E66...\n";
    cout << "NASA format: 0.1110 0110 | 0110 0110 | 0110 0110 | 0000 0000\n";
    cout << "Hex Rep:        E    6      6    6       6   6      0    0   \n";
    cout << "IEEE 754:    0011 1111 0 | 110 0110 0110 0110 0110 0110\n";

    cout << "\n\n99.7 base 10 converted to base 2,8,16\n\n";
    cout << "Base 2:   0011 0110.1011 0011 0011...\n";
    cout << "Base 8:   66.54631 4631 4631...\n";
    cout << "Base 16:  36.B333...\n";
    cout << "NASA format: 0.110 1101 | 0110 0110 | 0110 0110 | 0000 0110\n";
    cout << "Hex Rep:       6     D      6    6      6     6    0     6\n";
    cout << "IEEE 754:    0100 0010 1 | 100 0111 0110 0110 0110 0110\n\n";


    /*********************************************************************
                             Scaled Binary
     **********************************************************************/
    cout << "\n\n\tSCALED BINARY\n\n";

    /*********************************************************************
     Convert 5.75 base10 to scaled integer binary 1 unsigned byte max bits 
     **********************************************************************   
     
     * 5.75 base10 => 5.C base16
     * 0101.1100x2^0 base2 => only numbers before decimal fill the byte
     * 0000 0101.x2^0 => eliminate leading zeros to get better accuracy in byte
     * 0000 0101.1100 0000x2^0 => 101 1100 0.x2^-5    
     *       101 1100 0.x2^-5 =>  1011 1000 base2. WD 8, BP=5 

     **********************************************************************/

    //Declare variables here
    unsigned int input; // input int
    unsigned char value; //1 byte, WD=width 8, BP=binaryPoints 0
    unsigned int result; //4 byte, WD 32, BP 0    
    unsigned char binary; // 1 byte binary approx, WD=8, BP=0

    //Initialize variables
    binary = 0b10111000; // 5.75 base10==1011 1000 base2. WD=8 BP=5   
    input = 7;
    value = input; //WD 8, BP 0  
    result = value*binary; //WD=8+8=16 BP=0+5=5

    cout << "Value:  " << static_cast<int> (value) << endl;
    cout << "5.75 scaled to binary 1 byte:  " << static_cast<int> (binary) << endl;
    cout << setw(2) << static_cast<int> (value) << " x " << static_cast<int> (binary) << " = " << result
            << endl << result;

    result >>= 5; //Shifted 5 places.  WD=16-5=11, BP=5-5=0

    cout << " shifted 5 places: " << result << endl;
    cout << "5.75 x 7 = " << 5.75 * 7 << endl << endl << endl;



    /*********************************************************************
     Convert 0.9 base10 to scaled integer binary 2 unsigned byte max bits 
     **********************************************************************
    
     *    0.9 base10 => .E6 base16* => .1110 0110 0110...repeat infinity
     *   .1110 0110 0110 0110.0110x2^0
     *    1110 0110 0110 0110.0110x2^-16 => shifted right 16 places 
     *    1  6   3   1   4   6. => octal: 163146  BP=16   
     *    
     *    unsigned int result ==  MAX 4 byte, WD 32 
     *    unsigned char value == 1 byte, WD=8, BP=0
    
     **********************************************************************/

    unsigned short octal; //2 byte octal approx   WD=16, BP=16   
    octal = 0163146; //0.9 base10 => 163146 base8 WD=16, BP=16
    result = value*octal; //WD=8+16=24, BP=0+16 

    cout << "Value:  " << static_cast<int> (value) << endl;
    cout << "0.9 scaled to binary 2 byte:  " << static_cast<int> (octal) << endl;
    cout << setw(2) << static_cast<int> (value) << " x " << static_cast<int> (octal) << " = " << result
            << endl << result;

    result >>= 16; //Shifted 16 places. WD=24-16=8, BP=16-16=0

    cout << " shifted 16 places: " << result << endl;
    cout << "0.9 x 7 = " << (0.9 * 7) << endl << endl;



    /**********************************************************************
     Convert 99.7 base10 to scaled integer binary 3 unsigned byte max bits 
     **********************************************************************
    
        99.7 base10=> 36.B3333... base16 => 0011 0110.1011 0011 0011...base2
        0011 0110. 1011 0011 0011 0011 0011x2^0...base2     
        0011 0110  1011 0011 0011 0011.x2^-16  => WD=24 BP=16         
          11 0110  1011 0011 0011 0011 00.1x2^-18   BP=18
          11 0110  1011 0011 0011 0011 01.x2^-18   rounded up BP=18 
          1101 1010 1100 1100 1100 1101.x2^-18   rounded up BP=18 
            D    A    C    C    C    D . base 16=> DACCCD. 3 byte rounded up BP=18  
       
       unsigned int result ==  MAX 4 byte, WD 32 
       unsigned char value == 1 byte, WD=8, BP=0
    
     ***********************************************************************/

    unsigned int hex; //3 byte hex approx WD=24 BP=0
    //hex=0b110110101100110011001101;
    hex = 0xDACCCD; //99.7 base10=>DACCCD. base16 rounded up.3byte WD=24, BP=18
    result = value*hex; //WD=8+24=32, BP=0+Y=Y

    cout << "Value:  " << static_cast<int> (value) << endl;
    cout << "99.7 scaled to binary 3 byte:  " << static_cast<int> (hex) << endl;

    cout << setw(2) << static_cast<int> (value) << " x " << static_cast<int> (hex) << " = " << result
            << endl << result;

    result >>= 18; //Shifted. WD=32-18=14 , BP=Y-Y=0   

    cout << " shifted 18 places: " << result << endl;
    cout << "99.7 x 7 = " << 99.7 * 7 << endl << endl;
}