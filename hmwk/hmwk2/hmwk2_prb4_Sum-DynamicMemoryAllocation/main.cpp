/*  
 * File:   main.cpp 
 * Author: Danielle Fernandez
 * 9/17/22 @6:30pm
 * Purpose: hmwk2_prb4_Sum-DynamicMemoryAllocation
 * Sample Input: 
 *                  5
 *                  1 2 3 4 5
 */
 
#include <iostream>
using namespace std;

int *getData(int &);//Return the array size and the array from the inputs
int *sumAry(const int *,int);//Return the array with successive sums
void prntAry(const int *,int);//Print the array

int main(){
	
	int size=0,
	    *ptr=nullptr;
	
	ptr = getData(size);
	
	prntAry(ptr,size);
	
	cout << endl;
	
	int *sumPtr = sumAry(ptr,size);
	
	prntAry(sumPtr,size);
	
	delete []ptr;
	delete []sumPtr;
	
	return 0;
}

/*************FUNCTION DEFINITIONS************/

//Return the array size and the array from the inputs
int *getData(int &size){
    
    cin >> size;
    
    int *ptr = new int[size];
    
    for(int i=0;i<size;i++){
        cin >> *(ptr+i);
    }
    
    return ptr;
} 


//Return the array with successive sums
int *sumAry(const int *ptr, int size){
    
    int *sum = new int[size];
    
    //loop through ptr array and accumlate sum
    for(int i=0;i<size;i++){
        
        if(i==0) sum[0]=ptr[0];
        else sum[i] = sum[i-1] + ptr[i];
    }
    
    return sum;
    
}


//Print the array
void prntAry(const int *arr, int size){
    
    for(int i=0;i<size;i++){
        cout << *(arr+i);
        if(i != size-1) cout << " ";
    }
}