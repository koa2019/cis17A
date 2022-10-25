/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on October 22, 2022, 12 PM
 * Purpose: midterm_prb5_factorialDataTypeLimits      
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <climits> // char and int maximums
#include <cfloat>  //float maximum
using namespace std;

int main(int argc, char** argv) {
    
    int w = 10,
        size = 21,
        sizeLDbl = 172;
    unsigned long long int intFact[size] = {};
    long double lngdblFact[sizeLDbl] = {};


    cout << "\t\tFactorial Data Type Limits\n\n";
    
    
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
            << setw(w) << lngdblFact[ch2-1] << endl;
    

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
    cout << "\nunsigned int MAX:                    " << static_cast<float> (UINT_MAX) << "\n";
    cout << "unsigned int Limit          " << setw(2) << n4 - 1 << setw(4) << left << "! =    "
            << setw(w) << static_cast<float> (intFact[n4 - 1]) << endl;
    cout << "unsigned int Overflow       " << setw(2) << n4 << setw(4) << left << "! =    "
            << setw(w) << static_cast<float> (fact4) << endl;
    cout << "actual value of             " << setw(2) << n4 << setw(4) << left << "! =    "
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
            << setw(w) << fact10 << endl;
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
    cout << "\nlong double 16 bytes 128 Bits MAX:           " << setw(14)<< LDBL_MAX << "\n";
    cout << "long double Limit                 " << setw(2) << n11 - 1 << setw(4) << left << "! =    "
            << setw(w) << fact11 << endl;
    //    cout <<   "long double Overflow                             " << setw(2) << n11 << setw(4) << left << "! =    "
    //         << setw(w) << fact11 <<endl;
    //    cout <<   "actual value of                             " << setw(2) << n11 << setw(4) << left << "! =    "
    //         << setw(w) << lngdblFact[n11] << endl << endl << endl;

    return 0;
}
