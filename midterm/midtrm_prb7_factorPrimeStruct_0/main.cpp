/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on October 23, 2022, 1:20 PM
 * Purpose: midterm_prb7_primeFactorizatnStruct_0
 *          factors out prime numbers out of 65000
 *          using static int arrays
 * 
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

//function prototypes

int main(int argc, char** argv) {

    // declare variables
    int size = 25, // find primes up to 100, but half will be eliminated because their even #s
        num = 65000;


    int n = 0,quot = 0, count = 0;
    int power[size] = {};
    int pArr[] = {2, 3, 5, 7, 9, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    quot = num;
  
    do {

        while ((quot % pArr[count]) == 0) {

            quot = quot / pArr[count];
            //cout << "quot/ "<< pArr[i] << " = " << quot << endl;
            
            n++;
            power[count] = n;
            //cout <<"["<<i<<"] " << pArr[i] << "^ " << power[i] << endl;
        }
        count++;       
        n = 0;
        
    }    while (quot > 1);

    cout << "\nPrime Factors of " << num << endl;
    for (int i = 0; i < count; i++) {

        if (power[i] > 0) {
            cout << pArr[i] << "^" << power[i];
            if((i != count-1)) cout << " + ";
            else cout << "";
        }
    }

    return 0;
}
/********************************PROBLEM 7 FUNCTION DEFINITIONS****************/
