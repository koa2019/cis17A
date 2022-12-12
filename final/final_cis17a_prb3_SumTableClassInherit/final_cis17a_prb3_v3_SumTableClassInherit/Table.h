/* 
 * File:   Table.h
 * Author: DanYell
 *
 * Created on December 10, 2022, 1:48 PM
 */

#ifndef TABLE_H
#define TABLE_H

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//template<class T>
class Table {
    //protected:
    private:    
        int rows;       //# of rows
        int cols;       //# of cols
        int *rowSum;    //row sum array
        int *colSum;    //column sum array
        int *table;     //Table array
        int grandTotal; //Grand total
        //void calcTable(void);   //Calculate all the sums
        //void calcTable();   //Calculate all the sums
        int tValues[100] = { //rows=5. cols=6
                            101,101,102,103,104,105,
                            106,107,108,109,110,111,
                            112,113,114,115,116,117,
                            118,119,120,121,122,123,
                            124,125,126,127,128,129};
    public:
        
        // Default constructor        
        Table(int, int);
        // Destructor
        ~Table(){
            delete [] table; delete [] rowSum; delete [] colSum;
            table=nullptr;   rowSum=nullptr;   colSum=nullptr;          
        }

        //Mutator   
        void setTable();

        //Accessor
        const int *getTable() {return table;}
        const int *getRowSum() {return rowSum;}
        const int *getColSum() {return colSum;}
        int getGrandTotal()    {return grandTotal;}
        int getTValues(int i) const { return tValues[i];}
};

//******************************************
//   Default Constructor
//******************************************
Table::Table(int r, int c){  
   //cout<< "Inside Table() r="<<r << " c=" << c <<endl;
    rows = r<2 ? 2 : r;
    cols = c<2 ? 2 : c;
    grandTotal=0;            
    rowSum = new int[rows+1]; //allocating memory for pointer array
    colSum = new int[cols+1]; //allocating memory for pointer array
    table  = new int[rows*cols]; //allocating memory for pointer array
    setTable();
}


//******************************************
//        Calculate all the sums
//******************************************
//void Table::calcTable(){
//    
//}
//******************************************
//      Set table
// Prints 1D pointer array like its a 2D array
// arguments passing rows=rows+1  cols=cols+1
//******************************************
void Table::setTable(){
    
    cout << "\nSetting table with " << rows*cols << " numbers...\n";
    
    int indx;
    
    // Initialize 1D array like it's a 2D array   
    for(int i=0;i<rows;i++){
        rowSum[i] = 0;          //initializing pointer arrays
        for(int j=0;j<cols;j++){    
            indx = (i*cols+j); //numbers between [0,(rows*cols)].      
            colSum[j] = 0;    //initializing pointer array
            table[indx] = 0;
        }
    }
    
    int count = 0;
    float sumRow;
    
    // fill 1D array like it's a 2D array   
    for(int i=0;i<rows;i++){ 
        float sumRow = 0;
        for(int j=0;j<cols;j++){           
            
           //numbers between [0,(rows*cols)].
           indx = (i*cols+j);           
           //cout<< "[" << setw(3) << indx << "]=";
                     
           //if(!(indx%cols==cols-1)) {  //when its augTable
            if(!(indx%cols==cols)) {    
               table[indx] = tValues[count]; 
               sumRow += table[indx];
               count++;
                //cout  << setw(3) << table[indx] <<"  ";
                //on last col of each row save its sum to array
                //if(indx%cols==cols-1) {  //end of row for augTab
                if(indx%cols==cols-1) {  //end of row
                   rowSum[i] = sumRow;
                   grandTotal += rowSum[i];
                   //cout<<"rowSum["<< i << "]=" << rowSum[i] << "  ";
                } 
           }                                                      
        }
        //cout<<endl;
    }  
    //cout << "GrandTotal= " << grandTotal << endl;
}

#endif /* TABLE_H */

