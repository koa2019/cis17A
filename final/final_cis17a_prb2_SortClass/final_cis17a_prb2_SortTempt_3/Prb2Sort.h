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
    int indx;
    int *index; //Index that is utilized in the sort  
    
public:

    //Constructor
    Prb2Sort() {
        index = new int[10*18];        
    };

    //Destructor
    ~Prb2Sort() { 
        delete [] index;
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
    T *array = new T[10*16];
    return array;    
}



//***********************************************************
//Sorts a 2 dimensional array represented as a 1 dim array
//***********************************************************
template<class T>
T *Prb2Sort<T>::sortArray(const T *ch2p, int rows, int cols, int column, bool ascending) {

    int size = rows*cols;    
    string str1,str2;
    string sArry[rows];
    
    //****************************************
    // Puts every 16 characters into a string
    //****************************************
    
    //cout << "\nstring array\n";
    for (int i=0; i<rows; i++) {
        int start = i*cols;
        sArry[i] = str1.assign(ch2p,start,cols);        
        //cout << sArry[i] << "\n";
    }
    
    //**************************************************
    // create new array pointer and 
    // initialize it with pointer from function argument
    //**************************************************   
    T *array = new T[rows*cols];

    // copy pointer from argument to new pointer   
    for (int i = 0; i < size; i++) {
        *(array + i) = *(ch2p + i);
    }
 
     
    //****************************************
    //     Sort ascending
    //**************************************** 
    
    //Call function that Sorts a single column array 
    sortArray(array,column,ascending);
                    
    cout << "\n\nsorting takes a minute...\n";   
    
    // start at the last indx in array to the 2nd indx. starts at[last,1]
    for (int last=rows-1; last<rows; last--) { //loop for sorting. 
        for(int a=0;a<last;a++){    //loop for sorting. starts @[0,last]
            for(int i = 0,k=1; i < rows; i++,k++) { //loop for 1D array acting like 2D array
                for(int j = 0; j < cols; j++) {     
           
                    indx = (i*cols+j);                                             
    
                    if (indx%cols==column) {
                    //prints comparison of this column to the next column
                    //cout << array[indx] << " " << array[indx+cols] << endl;
                
                        //Conditional for ascending order
                        if(ascending){
                            if(array[indx] < array[indx+cols]) {

                                //cout << endl << array[indx] << "<" << array[indx+cols] << " ";
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
                        else{// if(!ascending) { // Conditional for descending order                            
                        
                            if(array[indx] > array[indx+cols]) {

                                cout << array[indx] << ">" << array[indx+cols] << " ";
                                
                                //Swap values in col
                                T tempD = array[indx];
                                array[indx] = array[indx+cols];
                                array[indx+cols] = tempD;

                                //Swap corresponding strings
                                string temp2 = sArry[i];
                                sArry[i] = sArry[i+1];
                                sArry[i+1] = temp2;
                                
                            } 
                        }
                    }              
                }
            }
        }
    }    
   
    //****************************************
    //     string array to char array
    //****************************************   
      
//    string tempS;     
//    for (int i = 0; i<rows; i++) {        
//        tempS = sArry[i];   //set string array element to a string variable        
//        for (int j = 0; j < cols; j++) { 
//            indx = (i*cols+j);  //set index
//            array[indx] = tempS[j];     //save string to a char array      
//            //cout << "array[" << indx << "]= "<<array[indx]<<endl;              
//        }        
//    }
   
    return array;
}

#endif /* PRB2SORT_H */

