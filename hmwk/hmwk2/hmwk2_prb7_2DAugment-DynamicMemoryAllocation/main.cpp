/*  
 * File:   main.cpp 
 * Author: Danielle Fernandez
 * 9/18/22 @12:30pm
 * Purpose: hmwk2_prb7_2DAugment-DynamicMemoryAllocation
 *
 * Sample Input:                Expected Output
 *                  3 4         
 *                  1 2 3 4      1 2 3 4
                    5 6 7 8      5 6 7 8
                    9 1 2 3      9 1 2 3(endl)
                                 0 0 0 0 0
                                 0 1 2 3 4
                                 0 5 6 7 8 
                                 0 9 1 2 3(no endl)
 */
 
#include <iostream>
using namespace std;

//function protypes
int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

int main(){
	
	int size,
	    row,
	    col,
	    **ptr2D = nullptr,
	    **aug2D = nullptr;
	 
	size=row=col=0;
	
	ptr2D = getData(row,col);
	
	printDat(ptr2D,row,col);
	
	cout << endl;
/*
    row=row+1;
    col=col+1;
    aug2D = augment(ptr2D,row,col);
    printDat(aug2D,row,col);
*/
    
	aug2D = augment(ptr2D,row+1,col+1);
	printDat(aug2D,row+1,col+1);

/*	
	cout << "Inside main() **aug2D" << endl;
	for(int r=0;r<row;r++){
        
        for(int c=0;c<col;c++){
            
            cout << aug2D[r][c];
        }
        cout << endl;
	}
*/	
	//cout<<"print aug2D"<<endl;

	
	
	destroy(ptr2D,row);
	
	destroy(aug2D,row);
	
	
	return 0;
}

/************FUNCTION DEFINITIONS************/

//Get the Matrix Data
int **getData(int &row, int &col){
    
    cin >> row >> col;
    
    // allocate dynamic memory for a 2D array with number of rows
    int **arr = new int*[row];
    
    // initialize each row with an array of columns
    for(int r=0;r<row;r++){
        arr[r] = new int[col];
    }
    
    //initialize each index to user input 
    for(int r=0;r<row;r++){
        
        for(int c=0;c<col;c++){
            
            cin >> arr[r][c]; 
        }
    }
    return arr;
}


//Augment the original array
int **augment(const int * const *arr, int row, int col){
    
    //cout << "row=" << row << " col=" << col << endl;
   
    //create 2D pointer and initialize it with pointers
    int **aug2D = new int*[row];

    //loop through rows    
    for(int r=0;r<row;r++){
        
        //allocate each row with an array of columns
        aug2D[r] = new int[col];
  
        //initialize each row in aug2D to zero or with *arr[][] value
        for(int c=0;c<col;c++){
                
            // initialize to zero
            aug2D[r][c] = 0;
                
            //add *arr[][] values to aug2D starting at arr2D[1][1]
            if( (r>0) && (c>=1 && c<=col) ){ //tc 1
              
                aug2D[r][c] = arr[r-1][c-1];
            }
        }
    }
    return aug2D;
}


//Print the Matrix
void printDat(const int * const *arr,int row, int col){
    
    //cout <<"row=" << row << "  col=" << col << endl;   
    
    //make sure row and col is at least 2
    row=row<2?2:row;
    col=col<2?2:col;
    
    //cout <<"row=" << row << "  col=" << col << endl;    
    
    int c;
    int r;
    
    for(r=0;r<row;r++){
        
        //cout << "r=" << r << endl;
        
        for(c=0;c<col;c++){
         
            //cout << "c=" << c << endl;    
            
            cout << arr[r][c];
            if(c!=col-1) cout << " ";
            else if(r<row-1 && c==col-1) cout << endl;
            else cout << "";
        
        /*    
            if(c!=col-1) cout << arr[r][c] << " ";
            else if(r!=row-1 && c==col-1) cout << arr[r][c] << endl;
            else cout << arr[r][c] << "";
        */
         
        /* 
            if( (c==col-1) && (!(r==row-1)) ) { cout << arr[r][c] << endl; }
            else if(!(c==col-1)) { cout << arr[r][c] << " "; }
            else { cout << arr[r][c] << " "; } 
        */
        }
        
        if(r!=row-1 && c==col-1) cout << endl;
    }
    //cout << endl;
    //if(r<=2) cout << endl;
}


//Destroy the Matrix, i.e., reallocate memory
void destroy(int **arr, int row){
    
    //delete each row in pointer
    for(int r=0;r<row;r++){
        
        delete []arr[r];
    }
    
    //delete pointer
    delete []arr;
}