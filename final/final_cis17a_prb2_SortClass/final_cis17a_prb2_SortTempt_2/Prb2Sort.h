/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prb2Sort.h
 * Author: DanYell
 *
 * Created on December 8, 2022, 7:34 PM
 */

#ifndef PRB2SORT_H
#define PRB2SORT_H
#include <iostream>   //Input/Output Library
#include <string>   //string
#include <cstring> //strstr
using namespace std;  //STD Name-space where Library is compiled


//This class sorts arrays either ascending or descending
template<class T>
class Prb2Sort {
    
private:
    int *index; //Index that is utilized in the sort
    
public:

    //Constructor
    Prb2Sort() {
        index = NULL;
    };

    //Destructor
    ~Prb2Sort() { 
        delete []index;
    };
    T *sortArray(const T*, int, bool); //Sorts a single column array
    T *sortArray(const T*, int, int, int, bool); //Sorts a 2D array that's represented as a 1D array
};

//***************************************
//     Sorts a single column array
//***************************************
template<class T>
T *Prb2Sort<T>::sortArray(const T *arr, int column, bool ascending){ 
    
    //cout << "\n\nInside sort1().\n";
    
    //index = &column;  //set class variable 
    
    //cout << "sizeof(arr)/sizeof(arr[0]) = " << sizeof(arr)/sizeof(arr[0]) << endl;
    
    T *array = new T[sizeof(arr)/sizeof(arr[0])];
    
    return array;    
}



//***********************************************************
//Sorts a 2 dimensional array represented as a 1 dim array
//***********************************************************
template<class T>
T *Prb2Sort<T>::sortArray(const T *ch2p, int rows, int cols, int column, bool ascending) {

    //cout << "\n\nInside sort2().\nsize = " << size << endl;
    
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
    
    
    T *array = new T[rows * cols];

    // copy pointer from argument to new pointer   
    for (int i = 0; i < size; i++) {
        *(array + i) = *(ch2p + i);
    }
 
     
    //****************************************
    //     Sort ascending
    //**************************************** 
    
    //Call function that Sorts a single column array 
    sortArray(array,column,ascending);
                    
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
                            T tempC = array[indx];
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
    T *array2 = new T[rows * cols];
    
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

#endif /* PRB2SORT_H */

