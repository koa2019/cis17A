/*  
 * File:   main.cpp 
 * Author: Danielle Fernandez
 * 9/17/22 @4pm
 * Purpose: hmwk2_prb2_Median - Dynamic Memory Allocation
 * Sample Input: 
 *                  5
 *                  1 5 2 4 3
 */

//Libraries
#include <iostream>

// function protypes
int *getData(int &);               //Fill the array

int *sort(const int *,int);         //Sort smallest to largest

int *reverse(const int *,int);  //Sort in reverse order

void prntDat(const int *,int); //Print the array


using namespace std;

int main(){

    int size,   // size of array
        *intPtr=nullptr;    // pointer to array of integers
    
    //function returns size of array and a reference to arrays address that holds array's inteer values
    intPtr = getData(size); 
   
    
    //print array
    //prntDat(intPtr, size);
    //cout << endl;
    
    int *sortArr = sort(intPtr, size);
    
    //print array sorted small to big
    prntDat(sortArr, size);
    cout << endl;
    
    //reverse sortArr big to small
    intPtr = nullptr;
    intPtr = reverse(sortArr,size);
    
    //print array
    prntDat(intPtr, size);
    
    //destroy dynamic memroy
    delete []intPtr;
    delete []sortArr;
    
    
	return 0;
}

/**********FUNCTION DEFINITIONS***********/

 //Fill the array
int *getData(int &size){      
    
    cin >> size;
    
    // catch size error
    if(size<=0) return nullptr;
    
    // declare and set pointer
    int *arr = nullptr;
    
    // allocate memory for dynamic array 
    arr = new int[size];
    
    //read in int values & set to their own array index
    for(int i=0;i<size;i++){
        
        cin >> *(arr + i);
    }
    
    // return ref to array's address
    return arr;
}


//Sort smallest to largest
int *sort(const int *arr, int size){         
    
    //declare and allocate memory for an array[size]
    int *sortArr = new int[size];
    
    //copy arr values to new array
    for(int count=0; count<size;count++){
        
        sortArr[count]=arr[count];   
    }
    
    //sort ascending order
     for(int i=0;i<size-1;i++){
       
        //loop compares i against all the other indices in the array
        for(int j=i+1; j<size;j++){
            
            //cout << "is " << sortArr[i] << ">" << sortArr[j] << "?";
            
            if(sortArr[i]>sortArr[j]) {
            
                //cout << " yes.SWAP! ";
                swap(sortArr[i],sortArr[j]);
                //prntDat(sortArr, size);
               
                }
                //cout<<endl;
        }
    }
    // return address to sortArr
    return sortArr;
}


//Sort in reverse order
int *reverse(const int *sortArr, int size){ 
    
    int *revArr = nullptr;
    revArr = new int[size];
   
    // set new array to be sortArr values in reverse order descending - big to small 
    for(int last=size-1, start=0;last>=0;last--, start++){
        
        revArr[start]=sortArr[last];
        //cout << "[" << start << "]=" << revArr[start] << " [" << last << "]=" << sortArr[last] << endl;
    }
   
    // return array's address
    return revArr;
}

//Print the array
void prntDat(const int *arr,int size){ 

    for(int i=0;i<size;i++){
        
        cout << *(arr+i);
        
        if(i != size-1) cout << " ";
    }
}