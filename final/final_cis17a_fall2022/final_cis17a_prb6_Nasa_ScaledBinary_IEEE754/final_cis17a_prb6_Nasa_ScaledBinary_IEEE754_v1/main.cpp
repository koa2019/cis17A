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
    
    cout<<"\n\n\tSCALED BINARY\n\n";
    
    //Declare variables here
    unsigned int input; // input int
    unsigned char value;    //1 byte value
    unsigned char seven=7;  //width=8, BP=1; BP=binary point
    unsigned char  binary;// 1 byte binary approx
    unsigned short octal; // 2 byte octal approx
    unsigned int   hex;   // 3 byte hex approx
    unsigned int result;
    
    //**********************************************************
    //                0.1    binary 
    //**********************************************************
    /*
     * base10 0.1=>1.999 base16
     * .0001 1001 1001 1001 1001 1001 1001 ...base2
     *     1 1001 101 => shifted right 11 places 
     *     1 1001 1001 1001 101 => 146315  BP=19
     *     1 1001 1001 1001 1001 1001 101 =>    CCCCCD  BP=27
     * 
    */
    //initialize variables   
    binary=0b11001101;//0.1 rounded up. 1byte-> width=8, BP=11
    octal=0146315;//0.1 rounded up.     2byte-> width=16, BP=19
    hex=0xCCCCCD;//0.1 rounded up.      3byte->  width=24, BP=27
    
    
    //Display the results
    input=7; 
    value=input;  //width 8, BP 0
    cout<<"\nValue:             " <<static_cast<int>(value) <<endl;  
    cout<<"0.1 converted to scaled int binary 1,2 & 3 unsigned byte.\n"; 
    cout << "Scaled Binary:     "<<static_cast<int>(binary)<<endl;
    cout << "Scaled Octal:      "<<static_cast<int>(octal)<<endl;
    cout << "Scaled Hex:        "<<static_cast<int>(hex)<<endl<<endl;
   
    result=value*binary;//width=8+8=16, BP=0+11
    
    cout<<"\nBinary:\n "<<static_cast<int>(value)<<"*"<<static_cast<int>(binary)
         <<"="<<result<<endl<<result;
    
    result>>=11;//Shifted 11 places.width=16-11=5, BP=11-11=0
    
    cout<<" shifted 11 places: "<<result<<endl<<endl;       
    
    //multiply 1 byte value by 7 and shift back to integer
    result=value*binary*seven;//width=8+8+8==24, BP=0+11
    
    cout<<" "<<static_cast<int>(value)<<"*"<<static_cast<int>(binary)
         <<"*7="<< value*binary*seven<<endl<<result;
    
    result>>=11;//Shifted.  width=24-11=13, BP=11-11=0
    
    cout<<" shifted 11 places: "<<result<<endl;
    
    
    //**********************************************************
    //              0.1   octal - base 8
    //**********************************************************
    result = value*octal;//width=8+16=24, BP=0+19   
    
    cout <<"\n\nOctal:\n"<<static_cast<int>(value)<<"*"<<static_cast<int>(octal)
         <<"="<<result<<endl<<result;
    
    result>>=19;//Shifted 19 places. width=24-19=5, BP=19-19=0
    
    cout<<" shifted 19 places: "<<result<<endl<<endl;
    
    //multiply 1 byte value by 7 and shift back to integer
    result=value*octal*seven;//width=8+16+8=32, BP=0+19  
    
    cout<<static_cast<int>(value)<<"*"<<static_cast<int>(octal)
         <<"*7="<< value*octal*seven<<endl<<result;
    
    result>>=19;//Shifted. width=32-19=13 , BP=19-19=0
    
    cout<<" shifted 19 places: "<<result<<endl;
    
    
    //**********************************************************
    //              0.1   hex - base 16
    //**********************************************************
    result = value*hex;//width=8+24=32, BP=0+27
    
    cout <<"\n\nHex: "<<static_cast<int>(value)<<"*"<<static_cast<int>(hex)
         <<"="<<result<<endl<<result;
    
    result>>=27;//Shifted 27 places. width=32-27=5, BP=27-27=0
    
    cout<<" shifted 27 places: "<<result<<endl<<endl;
    
    //multiply 1 byte value by 7 and shift back to integer
    result=value*hex*seven;//width=8+24+8=40, BP=0+27 
    
    cout<<static_cast<int>(value)<<"*"<<static_cast<int>(hex)
         <<"*7="<< value*hex*seven<<endl<<result;
    
    result>>=27;//Shifted. width=40-27=13, BP=27-27=0
    
    cout<<" shifted 27 places: "<<result<<endl;
    cout<<"\n-------------------------------\n\n";   
    
}