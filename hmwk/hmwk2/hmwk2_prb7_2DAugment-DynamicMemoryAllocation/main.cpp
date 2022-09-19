/*  
 * File:   main.cpp 
 * Author: Danielle Fernandez
 * 9/18/22 @12:30pm
 * Purpose: hmwk2_prb7_2DAugment-DynamicMemoryAllocation
 *
 * Sample Input:                Expected Output
 *                  2 3         
 *                  1 2 3       1 2 3 
                    4 5 6       4 5 6
                                0 0 0 0 
                                0 1 2 3 
                                0 4 5 6
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
	
	//cout << endl;
	
	row = row+1;
	col = col+1;
	
	aug2D = augment(ptr2D,row,col);
	
	printDat(aug2D,row,col);
	
	destroy(ptr2D,row);
	
	destroy(aug2D,row);
	
	
	return 0;
}

/************FUNCTION DEFINITIONS************/

//Get the Matrix Data
int **getData(int &row, int &col){
    
    cin >> row >> col;
    cin.ignore();
    
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
    
    cin.ignore();
    
    return arr;
}


//Augment the original array
int **augment(const int * const *arr, int row, int col){
    
    //int newRow = row+1,
      //  newCol = col+1;
    
    //cout <<"newRow= " << newRow << "  newCol= " << newCol << endl << endl;    
    
    int **arr2D = new int*[row];
    
    for(int r=0;r<row;r++){
        
        //allocate each row with an array of columns
        arr2D[r] = new int[col];
  
        for(int c=0;c<col;c++){
                
                //initialize each index in 2D array to zero
                arr2D[r][c] = 0;
                
                if( (r==1 || r==2) && (c>=1 && c<=3) ){
                    
                    arr2D[r][c] = arr[r-1][c-1];
                }
        }
    }
    
    return arr2D;
}


//Print the Matrix
void printDat(const int * const *arr,int row, int col){
    
    //cout <<"\nrow=" << row << "  col=" << col << endl<<endl;    
    int c,lastR,lastC;
    
    lastR=row-1;
    lastC=col-1;
    
    //cout<<row<<"-1= "<<lastR<<" \n";
    //cout<<col<<"-1= "<<lastC<<" \n";
     
    for(int r=0;r<row;r++){
        for(c=0;c<col;c++){
         
            //cout <<" r=" << r << "_c=" << c;    
            
            cout << arr[r][c];
            
            if(c!=col-1) { 
                cout << " ";
            } 
            else cout << endl;
            
            
        /*    else {
                
           // if( (r==row-1) && (c==col-1) ) cout << "";
           
            //else cout << endl;
            }
        */    
         
         
        /*
            if(r==3 && c==col-1) {cout << arr[r][c] << " ";}
            
            else if(r<=1 && c==col-1) {cout << arr[r][c] << endl;}
            
            else if(c!=col-1) { cout << arr[r][c] << " ";} //if(c!=col-1) 
            
            else cout << arr[r][c];
            
            //cout<<" hit";
        */               
        }
        
    }
}


//Destroy the Matrix, i.e., reallocate memory
void destroy(int **arr, int row){
    
    for(int r=0;r<row;r++){
        
        delete []arr[r];
    }
    
    delete []arr;
}