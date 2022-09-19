/*  
 * File:   main.cpp 
 * Author: Danielle Fernandez
 * 9/18/22 @12:30pm
 * Purpose: hmwk2_prb6_1DAugment-DynamicMemoryAllocation
 *
 * Sample Input:                Expected Output
 *                  5         
 *                  1 2 3 4 5    1 2 3 4 5
                                 0 1 2 3 4 5
 */
 
#include <iostream>
using namespace std;

//function protypes
int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array


int main(){
	
    int size  = 0,
	    *ptr1 = nullptr,
	    *ptr2 = nullptr;
	
	ptr1 = getData(size);
	
	prntAry(ptr1, size);
	
	cout << endl;
	
	ptr2 = augment(ptr1, size);
	
	prntAry(ptr2, size+1);
	
	delete []ptr1;
	delete []ptr2;
	
	return 0;
}

/************FUNCTION DEFINITIONS************/


//Read the array
int *getData(int &size){

    cin >> size;
    
    int *arr = new int[size];
    
    for(int i=0;i<size;i++){
        
        cin >> arr[i];
    }
    
    return arr;
}


//Augment and copy the original array
int *augment(const int *arr, int size){
    
    int *augmntd = new int[size+1];
    
    
    for(int i=0; i<size+1;i++){

        if(i==0) augmntd[i] = 0;
        
        else {
            augmntd[i] = arr[i-1];
            //cout << "aug[" <<i<<"]="<< augmntd[i] << " arr[" << i-1 <<"]=" << arr[i-1] <<endl;
        }
    }
    return augmntd;
}


//Print the array
void prntAry(const int *arr, int size){
    
    for(int i=0;i<size;i++){
        
        cout << arr[i];
        
        if(i != size-1) cout << " ";
    }
}