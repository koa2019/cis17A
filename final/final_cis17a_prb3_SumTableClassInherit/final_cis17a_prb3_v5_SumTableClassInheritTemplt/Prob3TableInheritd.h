/* 
 * File:   Prob3TableInheritd.h
 * Author: DanYell
 * Created on December 10, 2022, 2:47 PM
 * 
 * Prob3TableInheritd class inherits Table class.
 * Prob3TableInheritd is derived/child class.
 * Table class is base/parent class
 */

#ifndef PROB3TABLEINHERITD_H
#define PROB3TABLEINHERITD_H
#include "Table.h"  // base class
using namespace std;

template<class T>
//class Prob3TableInheritd:public Table<T> {

class Prob3TableInheritd : public Table<T> {
    
protected:
    T *augTable;
public:
    Prob3TableInheritd(int, int); //Default Constructor
    ~Prob3TableInheritd() {delete [] augTable;};  //Destructor
    const T *getAugTable() {return augTable;};
};


//*********************************
//    Default Constructor
//*********************************
template<class T>
Prob3TableInheritd<T>::Prob3TableInheritd(int row, int col) : Table<T>(row,col) {

    //cout << "\nInside Prob3TableInheritd() \n";
    row++;
    col++;
    
    //allocate memory for augmented table    
    augTable = new T[row*col];
    int indx;
    int count=0,count2=0;

    // Initialize 1D array like it's a 2D array  
    //cout << "\nInitializing augTable...\n";
     
    for (int i = 0; i < row; i++) {
        //rowSum[i] = 0;          //initializing pointer arrays
        for (int j = 0; j < col; j++) {
            indx = (i * col + j); //numbers between [0,(rows*cols)]. 
            
            // sets the last column of each row to its sum 
            if (indx % col == col - 1) {
                if (indx ==(row*col)-1)//last row & col                
                     {augTable[indx] = grandTotal;}
                
                else {augTable[indx] = rowSum[i];}
              
              //sets the last column to the sum of that column's values  
            } else if ((indx >= 35) && (indx <= (row*col-1))) {
                augTable[indx] = colSum[count2];
                count2++;
                
             //sets the rest with values from *table in Table class   
            } else {
                augTable[indx] = table[count];
                count++;
            }           
        }
    }
}

#endif /* PROB3TABLEINHERITD_H */

