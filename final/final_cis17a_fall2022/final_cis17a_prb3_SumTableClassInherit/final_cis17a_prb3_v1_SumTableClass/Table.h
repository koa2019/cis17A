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
        int *array;     //Table array
        int grandTotal; //Grand total
        void calcTable(void);   //Calculate all the sums
        int tValues[100] = {101,101,102,103,104,  // values for array
                         105,106,107,108,109,110,111,112,113,114,
                         115,116,117,118,119,120,121,122,123,124,125,126,127,128,129};
    public:
    
        //Table(char *,int,int);     // Default constructor
        Table(int r=2, int c=2){  // Constructor #2
            
            rows = r<2 ? 2 : r;
            cols = c<2 ? 2 : c;
            grandTotal=0;
            
            rowSum = new int[rows*cols]; //allocating memory for pointer array
            colSum = new int[rows*cols]; //allocating memory for pointer array
            array  = new int[rows*cols]; //allocating memory for pointer array
            setArray();
        }
        // Destructor
        ~Table(){
            delete [] array; delete [] rowSum; delete [] colSum;
            array=nullptr;   rowSum=nullptr;   colSum=nullptr;          
        }

        //Mutator   
        void setArray();

        //Accessor
        const int *getTable() {return array;}
        const int *getRowSum() {return rowSum;}
        const int *getColSum() {return colSum;}
        int getGrandTotal()    {return grandTotal;}
};

//******************************************
//      Set table
// Prints 1D pointer array like its a 2D array
// arguments passing rows=rows+1  cols=cols+1
//******************************************
void Table::setArray(){
    
    cout << "\n\nFilling table with " << rows*cols << " numbers...\n";
    
    // fill 1D array like it's a 2D array   
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){           
          
           //numbers between [0,(rows*cols)].
           int indx = (i*cols+j);  
          
           //initializing pointer arrays
           rowSum[indx] = 0;
           colSum[indx] = 0;       
           array[indx] =  tValues[indx]; 
           
           //cout << "[" << indx << "]= ";
           //cout << array[indx] <<"  ";
           //if(j==cols-1) cout << endl;                              
        }
    }   
}

#endif /* TABLE_H */

