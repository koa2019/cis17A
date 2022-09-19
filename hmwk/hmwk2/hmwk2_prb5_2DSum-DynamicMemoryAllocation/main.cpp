/*  
 * File:   main.cpp 
 * Author: Danielle Fernandez
 * 9/17/22 @7pm
 * Purpose: hmwk2_prb5_2DSum-DynamicMemoryAllocation
 * Sample Input:                Expected Output
 *                  3 4         1 2 3 4
 *                  1 2 3 4     5 6 7 8
                    5 6 7 8     9 8 7 6
                    9 8 7 6     66
 */
 
 #include <iostream>
using namespace std;

int **getData(int &,int &); //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
//void prntDat(int**,int,int);//Print the 2-D Array
void destroy(int **,int,int);       //Deallocate memory
int sum(const int * const *, int,int);    //Return the Sum


int main(){
	
	int row = 0, 
	    col = 0,
	    total = 0,
	    **d2Ptr = nullptr;
	    
	d2Ptr = getData(row,col);
	
	prntDat(d2Ptr,row,col);
	
	total = sum(d2Ptr,row,col);

    cout << total;
    
    destroy(d2Ptr,row,col);
    
	return 0;
}

/**********FUNCTION DEFINITIONS************/


 //add each col and Return the Sum
int sum(const int * const *arr, int row,int col){   
    
    int sum=0;
    
    for(int r=0;r<row;r++){
        for(int c=0; c<col;c++){
            
            //cout <<" arr="<< arr[r][c] << "+";
            sum += arr[r][c];
            //cout << " sum=" << sum ;
        }
        //cout << endl;
    }
    return sum;
}


//Return the 2-D array and its size.
int **getData(int &rows, int &cols){        
    
    int sum=0;
    
    cin >> rows >> cols;
    
    //create new 2D array of pointers
    int **arr = new int*[rows];

    //create an array of columns within each of the array's rows
    for(int r=0;r<rows;r++){
        arr[r] = new int[cols];
    }

    //initialize each index of 2D array 
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            
            cin >> arr[r][c];   
            //sum += arr[r][c];
        }
    }
    //cout << sum << endl;
    
    //return address of pointer
    return arr;
}

//Print the 2-D Array
void prntDat(const int* const *arr, int row, int col){
//void prntDat(int **ptr,int row, int col){
    
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            
            cout << arr[r][c];
            
            if( (c!=(col-1)) ) cout << " ";
        }
        cout << endl;
    }
}


 //De-allocate memory
void destroy(int **arr, int row,int col){ 
    
    for(int r=0;r<row;r++){
        delete []arr[r];
    }
    delete []arr;
}