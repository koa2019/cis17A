/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on October 23, 2022, 1:20-9PM
 * Purpose: midterm_prb7_primeFactorizatnStruct_2
 *          combine version zero and v1 together
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

// single structure that holds a prime number that's divisible into # 
// and how  many times it does
struct Primes {
    int p;
    int power;
};

// structure points to another structure. *primes is a ref to an integer array
struct Factors {
    int size;
    Primes *primes;
};

//function prototypes
int *setPrimes(int);            // sets prime numbers to an array
Factors *getFactors(int, int,int&);  // calculates prime number factors
void printStruct(Factors *);    // print structure
void destroy(Factors *);        // delete dynamic memory


int main(int argc, char** argv) {

    // declare variables
    int size = 25, // find primes up to 100, but half will be eliminated because their even #s
        num = 65000,
        q=0;

    do{
        cout<<"Enter a number between 0 and 65000 \n";
        cin>>num;
    }while(num<0 || num>65000);
    
    // declare new pointer to structure    
    Factors *factors; 

    // set structure with data
    factors = getFactors(size, num,q);

    // print primes numbers in array
   
     //if (!(quot % primes[count])) {
    if(q==num){
        cout << q << " has NO prime factors.\n";       
    } else {
        cout << "\nPrime Factors of " << num << endl;
        printStruct(factors);
    }

    // delete dynamic memory
    destroy(factors);

    return 0;
}
/********************************PROBLEM 7 FUNCTION DEFINITIONS****************/

// print structure members
void printStruct(Factors *factors) {

   
    for (int i = 0; i < factors->size; i++) {

        if (factors->primes[i].power > 0) {
            cout << factors->primes[i].p << "^"
                    << factors->primes[i].power;
            if (i != (factors->size) - 1) cout << " * ";
            else cout << "";
        }
    }
    
}

// factor prime numbers out of a given #
Factors *getFactors(int s, int num,int &quot) {
    
    // declare & set variables
    int pwr = 0,    // counts how many times a prime # is divisible        
        count = 0;  //loop counter
    
    quot = num; // quotient represents whole number after division
    
    // declare new pointer to structure Primes & initialize pointer with an int array 
    Factors *factors = new Factors;

    // set structure's member value
    factors->size = s;
    //cout << factors->size << endl;

    // created an array inside Factors structure
    factors->primes = new Primes[factors->size];
   
    // call function to get prime #s between [2,100]
    int *primes = setPrimes(s);

    do {        
        
        //cout<<count<<"  " << primes[count]<<endl;
        // if quotient is divisible by current prime #
        while ((quot % primes[count]) == 0) {

            // save current prime # to structure's member
            factors->primes[count].p = primes[count];

            // divide quotient by current prime #
            quot = quot / primes[count];
            //cout << "quot/ "<< primes[count] << " = " << quot << endl;
            
            // increment how many times current prime can be even divided into quot
            pwr++;
        }

        // set structure's member value
        factors->primes[count].power = pwr;
        
        // increment for next loop iteration
        count++;
        //cout<<count<<endl;
        
        // reset counter
        pwr = 0;

    } while (quot > 1 && count<=25);  // stop when quot == 1

    // reset size according to count
    factors->size = count;

    // return pointer
    return factors;
}

// find prime #s between [2,100] & set in an array
int *setPrimes(int n) {

    // declare & set counter
    int cnt = 0;

    // declare new pointer & initialize it with an array
    int *primes = new int[n];

    // fill structure prime[ ] with prime #s from [2,100]
    for (int i = 2; i < 100; i++) {

        // 2 is always the first prime number
        if (i == 2) {

            primes[cnt] = i;
            //cout << cnt << "  " << primes[cnt] << endl;
            cnt++;
        }
        
        // checks for odd numbers
        else if (!(i % 2 == 0)) {

            // 3,5,7,9,11 are non-divisible so set as prime
            if ((i == 3 || i == 5 || i == 7 || i == 9 || i == 11)) {

                primes[cnt] = i;
                //cout << cnt << "  "  << primes[cnt] << endl;
                cnt++;
            }
            
            // eliminate #s that are divisible by 3,5,7,9,11
            if (!(i % 3 == 0 || i % 5 == 0 || i % 7 == 0 || i % 9 == 0 || i == 11)) {
                primes[cnt] = i;
                //cout << cnt << "  "  << primes[cnt] << endl;
                cnt++;
            }
        } else cout << "";
    }
    return primes;
}

void destroy(Factors *ptrPrim) {

    //for(int i=0;i<(ptrPrim->size);i++){
    //    delete [] ptrPrim->primes;
    //}
    delete [] ptrPrim; // delete array of structures  

}


