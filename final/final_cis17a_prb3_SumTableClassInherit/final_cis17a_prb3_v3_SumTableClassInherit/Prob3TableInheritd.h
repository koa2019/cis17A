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

//template<class T>
//class Prob3TableInheritd:public Table<T> {

class Prob3TableInheritd : public Table {
protected:
    int *augTable;
    int tValues[100] = {//rows=5. cols=6
        101, 101, 102, 103, 104, 105,
        106, 107, 108, 109, 110, 111,
        112, 113, 114, 115, 116, 117,
        118, 119, 120, 121, 122, 123,
        124, 125, 126, 127, 128, 129};
public:
    Prob3TableInheritd(int, int); //Default Constructor
    ~Prob3TableInheritd() {delete [] augTable;};  //Destructor
    const int *getAugTable() {return augTable;};
};

//*********************************
//    Default Constructor
//*********************************

Prob3TableInheritd::Prob3TableInheritd(int row, int col) : Table(row, col) {

    cout << "\nInside Prob3TableInheritd() \n";
    //cout<< "row=" << row << " col=" << col <<endl;
    row++;
    col++;
    //cout<< "row++=" << row << " col++=" << col <<endl;

    //allocate memory for augmented table    
    augTable = new int[row * col];
    int indx;
    int count = 0;

    cout << "\nInitializing augTable...\n";
    // Initialize 1D array like it's a 2D array   
    for (int i = 0; i < row; i++) {
        //rowSum[i] = 0;          //initializing pointer arrays
        for (int j = 0; j < col; j++) {
            indx = (i * col + j); //numbers between [0,(rows*cols)]. 
            //cout << "[" << setw(3) << indx << "]= ";
            //colSum[j] = 0;    //initializing pointer array
            //augTable[indx] = 0;
            if (indx % col == col - 1) {
                augTable[indx] = -99;
            } else if ((indx >= 35) && (indx <= (row * col - 1))) {
                augTable[indx] = 0;
            } else {
                augTable[indx] = tValues[count];
                count++;
            }
            //cout << setw(3) << augTable[indx] << "  ";
        }
        //cout << endl;
    }
    
    int rowSum[row] = {};
    int colSum[col] = {};
    float sum, gTotal = 0;
    
    cout << "\nFilling augTable with " << row * col << " numbers...\n";
    // fill 1D array like it's a 2D array   
    for (int i = 0; i < row; i++) {
        sum = 0;
        for (int j = 0; j < col; j++) {

            //numbers between [0,(row*col)].
            indx = (i * col + j);            

            if (!(indx % col == col - 1)) { //when its augTable
                //if(!(indx%col==col)) {    
                //cout << "[" << setw(3) << indx << "]= ";
                sum += augTable[indx];
                //cout << setw(3) << augTable[indx] << "  ";
            } else if ((i != row - 1) && (indx % col == col - 1)) { //end of row and last col
                //cout << "[" << setw(3) << indx << "]= ";
                rowSum[i] = sum;
                augTable[indx] = rowSum[i];
                gTotal += rowSum[i];
                //cout<<"rowSum["<< i << "]=" << sum << endl;
                //cout << setw(3) << augTable[indx] << "  ";
            }
            else if (i == row - 1 && (indx % col == col - 1)) {//last row & col
                //cout << "[" << setw(3) << indx << "]= ";
                augTable[indx] = gTotal;
                //cout << setw(3) << augTable[indx] << "  ";
            } else {
                cout << "Damn\n";
            }
        }
        //cout << endl;
    }
    
    //*******************************************
    //        calculate each column's sum       
    //*******************************************
    // outer loop is columns instead of rows
    for(int c=0;c<col;c++){        
        sum=0;        
        for(int i=0;i<row;i++){                      
            indx = (i * col + c);   //numbers between [0,(row*col)]                       
            sum+=augTable[indx];
            //cout<< "sum= "<<sum<<endl;           
                      
            //last row and not last col in table
            if(i==row-1 && indx!=(row*col-1)) {
                augTable[indx]=sum;                
            }
        }        
    }  
}

#endif /* PROB3TABLEINHERITD_H */

