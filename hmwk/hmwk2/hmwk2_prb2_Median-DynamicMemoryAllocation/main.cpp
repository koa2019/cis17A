/*  
 * File:   main.cpp 
 * Author: Danielle Fernandez
 * 9/17/22 @9pm
 * Purpose: hmwk2_prb2_Median - Dynamic Memory Allocation
 */

//Libraries
#include <iostream>
#include <iomanip>
using namespace std;

// function protypes
int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *);     //Print the median Array


int main(){

   int size,            // size of integer array read in from user input
       *intArr = nullptr; // pointer to integer array
    
     //function returns address of the array and value of size via a ref variable   
    intArr = getData(size);
       
    //print integer array
    prntDat(intArr,size);

    //declare pointer and initialize it with ref variable returned from median function
    float *medArr = median(intArr,size);
   
    //print median array
    prntMed(medArr);
    
    //destroy dynamic memory
    delete []medArr;
    delete []intArr;
    medArr = nullptr;
    intArr = nullptr;
    
	return 0;
}

/**********  FUNCTION DEFINITIONS   *************/

//Return the array size and the array
int *getData(int &size){
    
    //read in user input & save value to ref variable
    cin >> size;
    
    // if num is zero or negative, return null pointer 
    if(size<=0) return nullptr;
    
    
    // declare pointer & initialize to null. It will store array of integers
    int *intArr = nullptr; 
    
    // allocate memory dynamically
    intArr = new int[size];
   
    // fill array with integers
    for(int i=0;i<size;i++){
            
        cin >> intArr[i];
    }
    
    // return address of arr
    return intArr;
}   

//Fill the median Array with the Float array size, the median, and the integer array data
float *median(int *intArr,int size){
    
    float median=0;
    
    // create new pointer array
    float *medArr = new float[size+2];
    
     // initialize dynamic array indices
    *medArr=0; 
    medArr[0]=size+2;
    median=(size+1)/2.0;
    medArr[1]=median;

    // copy intArr values into 
    for(int i=2, j=0;i<size+2;i++){
        
        medArr[i]=intArr[j++];
    }
    
    return medArr;
} 


 //Print the median Array
void prntMed(float *medArr){
    
    int length =  medArr[0];
    
    for(int i=0;i<length;i++){
        
        if(i==0) cout << medArr[0] << " ";
        else if(i==length-1) cout << fixed << setprecision(2) << medArr[i];
        else  cout << fixed << setprecision(2) << medArr[i] << " ";
    }
}


//Print the integer array
void prntDat(int *arr,int size){
    
     for(int i=0;i<size;i++){
          if(i==size-1) cout << arr[i];
          else cout << arr[i] << " " ;
     }
    cout << endl;
}   
