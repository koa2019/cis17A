/* 
 * File:   Prb1Random.h
 * Author: DanYell
 *
 * Created on December 8, 2022, 6:25 PM
 */

#ifndef PRB1RANDOM_H
#define PRB1RANDOM_H
#include "Prb1Random.h"//User Libraries
//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>  //setw()
#include <cstdlib>  //rand()
#include <ctime>    //rand()
using namespace std; //STD Name-space where Library is compiled


class Prb1Random {
private:
    char *set; //The set of numbers to draw random numbers from
    char nset; //The number of variables in the sequence
    int *freq; //Frequency of all the random numbers returned
    int numRand; //The total number of times the random number
                 //function is called
public:
    Prb1Random(const char, const char *); //Default Constructor
    ~Prb1Random(){ //Destructor
        delete [] set;
        delete [] freq;
    }
    char randFromSet(); //Returns a random number from the set
    int *getFreq() const { return freq;} //Returns the frequency histogram
    char *getSet() const{ return set;}  //Returns the set used
    int getNumRand() const{ return numRand;} //Gets the number of times 
                                             //randFromSet has been called
};

//******************************************************************************
//*************************************
//         Default constructor
//*************************************
Prb1Random::Prb1Random(const char size, const char *rndseq){
    
    numRand = 0;
    
    nset = size;
    
    set = new char[nset];   // Allocate memory for rand # array
    
    //Copy randSeq[] values from main to pointer in this class
    for(int i=0;i<size;i++){
        set[i]=rndseq[i];
    }
    
    freq = new int[nset];   // Allocate memory for freq array
    
    // initialize elements to zero
    for(int i=0;i<size;i++){
        freq[i]=0;
    }   
}


//*************************************
// Returns random number from the set
//*************************************
char Prb1Random::randFromSet(){
   
    numRand++;
   
    int randm = rand()%nset;  //Random # between [0,4]
    
    for(int i=0;i<nset;i++){
        if(set[randm]== set[i]){
            freq[i]++;
        }
    }
    return set[randm];
}

#endif /* PRB1RANDOM_H */

