/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on October 23, 2022, 1:20 PM
 * Purpose: midterm_prb7_primeFactorizatnStruct_1  
 *          1 instances of Primes structure that has an
 *          array of all prime numbers between [2,100].
 *          print and destroy functions for the Primes structure
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

//struct Primes {
//    Prime *p;
//    unsigned char power;
//};
struct Primes{
    unsigned short size;
    unsigned short *primes;
};

//function prototypes
Primes *setPrimes(int);
void destroy(Primes *);
void printStruct(Primes *);

int main(int argc, char** argv) {
    
    //char cnt = 0;
    int size = 100/4, // find primes up to 100, but half will be eliminated because their even #s
        num = 65000;                
    Primes *primes; // points to structure     
     
    // fill structure with data
    primes = setPrimes(size);
    
    // print primes numbers in array
    printStruct(primes);
    
    //factors prime numbers out of num based on static arrays
//     int n = 0, quot = 0, count = 0;
//    int power[size] = {};
//    int pArr[] = {2, 3, 5, 7, 9, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
//
//    quot = num;
//
//    do {
//
//        while ((quot % pArr[count]) == 0) {
//
//            quot = quot / pArr[count];
//            //cout << "quot/ "<< pArr[i] << " = " << quot << endl;
//
//            n++;
//            power[count] = n;
//            //cout <<"["<<i<<"] " << pArr[i] << "^ " << power[i] << endl;
//        }
//        count++;
//        n = 0;
//
//    } while (quot > 1);
//
//    cout << "\nPrime Factors of " << num << endl;
//    for (int i = 0; i < count; i++) {
//
//        if (power[i] > 0) {
//            cout << pArr[i] << "^" << power[i];
//            if ((i != count - 1)) cout << " + ";
//            else cout << "";
//        }
//    }
    
    // delete dynamic memory
    destroy(primes);       
    
    return 0;
}
/********************************PROBLEM 7 FUNCTION DEFINITIONS****************/

// print prime numbers
void printStruct(Primes *primes){
    
    for(int i=0;i< primes->size;i++){
        cout << i << "  " << primes->primes[i] << endl;
    }
    //delete [] primes;
}

// set array to prime #s from [2,100]. Return pointer to array
Primes *setPrimes(int n){
    
    int cnt = 0;
    
    // declare new pointer to structure Primes & initialize pointer with an int array 
    Primes *ptrPrim = new Primes;
    
    ptrPrim->size = n;
    
    ptrPrim->primes = new unsigned short[ptrPrim->size];
    
    // fill structure prime[ ] with prime #s from [2,100]
    for(int i=2;i<100;i++){
       
        // 2 is always the first prime number
        if(i==2) {
            
            ptrPrim->primes[cnt] = i;
            //cout << cnt << "  " << ptrPrim->primes[cnt] << endl;
            cnt++;
        }    
        
        // checks for odd numbers
        else if(!(i%2==0)){
            
            // 3,5,7,9,11 are non-divisible so set as prime
            if((i==3 || i==5 || i==7 || i==9 || i==11)){
                 
                ptrPrim->primes[cnt] = i;
                //cout << cnt << "  "  << ptrPrim->primes[cnt] << endl;
                cnt++;
            }
            // eliminate #s that are divisible by 3,5,7,9,11
            if(!(i%3==0 || i%5==0 || i%7==0 || i%9==0 || i==11)){
                ptrPrim->primes[cnt] = i;
                //cout << cnt << "  "  << ptrPrim->primes[cnt] << endl;
                cnt++;
            }                         
        } else cout<<"";         
    }
    ptrPrim->size = cnt;
    
    return ptrPrim;
}

void destroy(Primes *ptrPrim){
    
    //for(int i=0;i<(ptrPrim->size);i++){
    //    delete [] ptrPrim->primes;
    //}
    delete [] ptrPrim;  // delete array of structures  
    
}


