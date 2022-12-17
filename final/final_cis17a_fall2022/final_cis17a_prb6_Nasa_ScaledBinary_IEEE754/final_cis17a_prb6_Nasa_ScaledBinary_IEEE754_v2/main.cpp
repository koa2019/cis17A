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
   
    cout<<"\n\n\tProblem 6 Conversions\n\n";
    cout<<"5.75 base 10 converted to base 2,8,16\n\n";
    cout<<"Base 2:   0101.1100\n";
    cout<<"Base 8:   5.6\n";
    cout<<"Base 16:  5.C\n";
    cout<<"NASA format: 0.101 1100 | 0000 0000 | 0000 0000 | 0000 0011\n";
    cout<<"Hex Rep:        5    C      0    0      0    0      0    3\n";
    cout<<"IEEE 754:    0100 0000 1 | 011 1000 0000 0000 0000 0000\n";
    
    cout<<"\n\n0.9 base 10 converted to base 2,8,16\n\n";
    cout<<"Base 2:   .1110 0110 0110...\n";
    cout<<"Base 8:   .7146\n";
    cout<<"Base 16:  .E66...\n";
    cout<<"NASA format: 0.1110 0110 | 0110 0110 | 0110 0110 | 0000 0000\n";
    cout<<"Hex Rep:        E    6      6    6       6   6      0    0   \n";
    cout<<"IEEE 754:    0011 1111 0 | 110 0110 0110 0110 0110 0110\n";
    
    cout<<"\n\n99.7 base 10 converted to base 2,8,16\n\n";
    cout<<"Base 2:   0011 0110.1011 0011 0011...\n";
    cout<<"Base 8:   66.54631 4631 4631...\n";
    cout<<"Base 16:  36.B333...\n";
    cout<<"NASA format: 0.110 1101 | 0110 0110 | 0110 0110 | 0000 0110\n";
    cout<<"Hex Rep:       6     D      6    6      6     6    0     6\n";
    cout<<"IEEE 754:    0100 0010 1 | 100 0111 0110 0110 0110 0110\n\n";
    
    
    cout << "Press enter to continue.\n";
    cin.ignore();
    getScaledBinary();
    
    return 0;
}

void getScaledBinary(){
    
    cout<<"\n\n\tSCALED BINARY\n\n";
       
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
    unsigned int  input; // input int
    unsigned char value; //1 byte, WD=width 8, BP=binaryPoints 0
    unsigned int  result;//4 byte, WD 32, BP 0    
    unsigned char binary;// 1 byte binary approx, WD=8, BP=0
    
    //Initialize variables
    binary=0b10111000; // 5.75 base10==1011 1000 base2. WD=8 BP=5   
    input=7;
    value=input;  //WD 8, BP 0  
    result=value*binary;//WD=8+8=16 BP=0+5=5
    
    cout<<"Value:    " <<static_cast<int>(value)<<endl;
    cout<<"5.75 scaled to binary 1 byte:  "<<static_cast<int>(binary)<<endl;  
    cout<<setw(2)<<static_cast<int>(value)<<" x "<<static_cast<int>(binary) <<" = "<<result
        <<endl<<result;
    
    result>>=5;//Shifted 5 places.  WD=16-5=11, BP=5-5=0
    
    cout<<" shifted 5 places: "<<result<<endl;    
    cout<<"5.75 x 7 = "<<5.75*7<<endl<<endl<<endl;
    
    
    
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
    octal=0163146;   //0.9 base10 => 163146 base8 WD=16, BP=16
    result = value*octal;//WD=8+16=24, BP=0+16 
    
    cout<<"Value:    "<<static_cast<int>(value)<<endl; 
    cout<<"0.9 scaled to binary 2 byte:  "<<static_cast<int>(octal)<<endl;   
    cout<<setw(2)<<static_cast<int>(value)<<" x "<<static_cast<int>(octal) <<" = "<<result
        <<endl<<result;
    
    result>>=16;//Shifted 16 places. WD=24-16=8, BP=16-16=0
    
    cout<<" shifted 16 places: "<<result<<endl;
    cout<<"0.9 x 7 = "<<(0.9*7)<<endl<<endl;
    
    
    
   
   
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
    
    unsigned int hex;   //3 byte hex approx WD=24 BP=0
    //hex=0b110110101100110011001101;
    hex=0xDACCCD;   //99.7 base10=>DACCCD. base16 rounded up.3byte WD=24, BP=18
    result = value*hex;//WD=8+24=32, BP=0+Y=Y
    
    cout<<"Value:    "<<static_cast<int>(value)<<endl; 
    cout<<"99.7 scaled to binary 3 byte:  "<<static_cast<int>(hex)<<endl; 
    
    cout<<setw(2)<<static_cast<int>(value)<<" x "<<static_cast<int>(hex)<<" = "<<result
        <<endl<<result;
    
    result>>=18;//Shifted. WD=32-18=14 , BP=Y-Y=0   
    
    cout<<" shifted 18 places: "<<result<<endl;
    cout<<"99.7 x 7 = "<<99.7*7<<endl<<endl; 
   
}