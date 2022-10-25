/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on October 23, 2022, 4 PM
 * Purpose: midterm_prb6_nasaFormat_conversions     
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
    
    cout << "\n  B10         B16      B2              B8      Hex Rep    -Hex Rep\n";
    cout <<   " 49.1875     31.3    00110001.0011   61.14    62600006    9DA00006\n\n";
    cout <<   " 3.07421875  3.13    0011.00010011   3.046    62600002    9DA00002\n\n";
    cout <<   " 0.20        0.3     0.0011          0.1463   66666682    A00000FE\n\n";
    
    cout << "\n Hex Rep     B2                      B16         B10       \n";
    cout <<   " 69999902    0011.0100(1100repeat)   3.4CCCC8    3.2999999713\n\n";
    cout <<   " 69999903    0110.(1001repeat)       6.999999    6.5999994278\n\n";
    cout <<   " 966667FF    .0110(1001repeat)       0.699999    0.4124999642\n\n";
    return 0;
}
