/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created: 10-19-22 @10 PM
 * Purpose:  Driver program to test out the statistics problem.
 */

//Libraries
#include <iostream>//I/O
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "
        << ary->mode->size<<endl;
    cout<<"The max Frequency        = "
        <<ary->modFreq<<endl;
    
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    
    cout<<"The mode set             = {";    
    for(int i=0;i<ary->mode->size-1;i++){              
        cout<<ary->mode->data[i]<<",";
    }   
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;    
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

// set an instances of the Stats structure based on data in Array structure
Stats *stat(const Array *ary){
    
    int   j=0,         // counter for dynamic array          
          freq=0,      // number of times an element was found 
          maxFreq=0,   // max number of times an element was found 
          numMods=0;  // number of modes that have a freq that equals maxFreq
    float sum=0;     // hold sum of all integers in array
    
    // Allocate the mode array      
    int *modeAry = new int[ary->size]; // declare pointer array where its memory is dynamic 
    
    // initialize pointer to zero
    *modeAry=0;
    
    // set comparison variable to the first value in the array as starting point 
    int element = ary->data[0]; 
    
    // loop through Array structure to process data
    for (int i = 0; i < ary->size; i++) {
        
        // calculate sum of all numbers in array
        sum += ary->data[i];  
        
        // check if elements are the same
        if (element == ary->data[i]) {  
            
            // increment number times elements are equal
            freq++;

            // if freq is greater than maxFreq is true, then reset maxFreq
            if (freq >= 2 && freq > maxFreq) maxFreq = freq;            
            
          // if array values are NOT equal, then do the stuff below
        } else {
            
            // if count equals maxFreq
            if (freq == maxFreq) { 
                
                // increment total number of mode sets found in array 
                numMods++; 
                
                // array holds all the elements that their freq equals maxFreq
                modeAry[j] = element;       
                
                //increment array's index counter
                j++;
            }
            
            // reset value of element to current array index 
            element = ary->data[i]; 
            
            // reset count to 1 for next iteration
            freq = 1;   
        }
    }
    
    // create new pointer to Stats structure 
    Stats *stats = new Stats;
    
    // creates a pointer reference that points to the Array structure
    stats->mode = new Array;    
    
    // set mode's dynamic array size to number of modes 
    stats->mode->size = numMods; 
    
    // only allocates memory for mode[] if number of modes is NOT zero
    if(numMods!=0) stats->mode->data = new int[numMods];
    
    //set structure member to array's total sum divided by array's size
    stats->avg = sum/ary->size;
    
    // if no modes were found in array, then set maxFreq to 1
    if(maxFreq==0) maxFreq=1;   
    
    // set structure member
    stats->modFreq = maxFreq; 
    
    // if arySize is even minus 1 to compensate array starting @0
    int mdptIdx = (ary->size)%2==0 ? (ary->size-1)/2 : 
                  (ary->size-2)/2; // else if odd minus 2 to compensate array starting @0
   
    // calculate median by adding the midpoint array index 
    // with the index to its right then divide by 2
    float medn = ( (ary->data[mdptIdx]) + (ary->data[mdptIdx+1]) )/2.0f;
    
    // set Stat member to median
    stats->median = medn;
    
    //set the mode set array to the values stored in modeAry[]
    for(int k=0;k<numMods;k++){       
        stats->mode->data[k] = modeAry[k];        
    }
    
    delete [] modeAry;
    
    return stats;
}