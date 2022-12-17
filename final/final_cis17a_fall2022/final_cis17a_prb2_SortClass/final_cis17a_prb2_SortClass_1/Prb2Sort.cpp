#include "Prb2Sort.h"
//System Libraries
#include <iostream>   //Input/Output Library
#include <string>
#include <cstring> //strstr

using namespace std; //STD Name-space where Library is compiled


//***************************************
//     Sorts a single column array
//***************************************

char * Prb2Sort::sortArray(const char *arr, int column, bool ascending){ 
    
    index = &column;  //set class variable 
    //char *arr=nullptr;
    
    //return arr;    
}



//***********************************************************
//Sorts a 2 dimensional array represented as a 1 dim array
//***********************************************************

char * Prb2Sort::sortArray(const char *ch2p, int rows, int cols, int column, bool ascending) {

    //cout << "\n\nInside sort().\nsize = " << size << endl;
    
    //index = &column;  //set class variable 
    int findCol = column-1;
    int size = rows*cols;
    string str1,str2;
    string sArry[rows];
    
    //****************************************
    // Put every 16 characters into a string
    //****************************************
    
    //cout << "\nstring array\n";
    for (int i = 0; i<10; i++) {
        int start = i*cols;
        sArry[i] = str1.assign(ch2p,start,cols);        
        //cout << sArry[i] << "\n";
    }
    
    //**************************************************
    // create new pointer & 
    // initialize it with pointer from function argument
    //**************************************************
    
    
    char *array = new char[rows * cols];

    // copy pointer from argument to new pointer   
    for (int i = 0; i < size; i++) {
        *(array + i) = *(ch2p + i);
    }
 
     
    //****************************************
    //     Sort ascending
    //****************************************   
    
    cout << "\n\nsorting...\n";
    
    for (int last= rows-1; last<rows; last--) { //loop for sorting
        for(int a=0;a<last;a++){    //loop for sorting
            for(int i = 0,k=1; i < rows; i++,k++) { //loop for 1D array
                for(int j = 0; j < cols; j++) {  //acting like 2D array
           
                    int indx = (i*cols+j);            
                    //cout<< indx << " ";
            
                    if (indx%cols==findCol) {
                        //cout << array[indx] << " " << array[indx+cols] << endl;
                
                        if( array[indx] < array[indx+cols] ) {
                            
                            //cout << endl << array[indx] << " " << array[indx+cols] << " ";
                            //cout << static_cast<int>(array[indx]) << " < " << static_cast<int>(array[indx+cols]);

                            //Swap values in col
                            char tempC = array[indx];
                            array[indx] = array[indx+cols];
                            array[indx+cols] = tempC;

                            //Swap corresponding strings
                            string temp = sArry[i];
                            sArry[i] = sArry[i+1];
                            sArry[i+1] = temp;
                        }
                    }
                }              
            }
        }
    }    
   
    //****************************************
    //     string array to char array
    //****************************************   
    
    // create new pointer to char array2
    char *array2 = new char[rows * cols];
    
    string tempS;
     
    for (int i = 0; i<rows; i++) {
        
        tempS = sArry[i];
        
        for (int j = 0; j < cols; j++) {            
            
            int indx2 = (i*cols+j);
            
            //save string to a char array
            array2[indx2] = tempS[j];
           
            //cout << "array2[" << indx2 << "]= "<<array2[indx2]<<endl;              
        }        
    }
   
    delete [] array;
    
    return array2;
}

