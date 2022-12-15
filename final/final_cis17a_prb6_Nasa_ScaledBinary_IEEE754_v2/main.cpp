/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 12-07-2022 @ 6:36 PM
 * Purpose:  final_cis17a_prb6_Nasa_ScaledBinary_IEEE754_v1
 * 
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>      //setw()
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void getScaledBinary();

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
       
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
    
    
    cout << "Press enter to continue.\n";
    cin.ignore();
    getScaledBinary();
    
    return 0;
}

void getScaledBinary(){
    
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