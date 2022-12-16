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

template<class T>
class Table {
    
    protected:        
        int rows;       //# of rows
        int cols;       //# of cols
        T *rowSum;    //row sum array
        T *colSum;    //column sum array
        T *table;     //Table array
        T grandTotal; //Grand total                
        void setTable(); //Mutator Calculate all the sums
        int tValues[100] = { //rows=5. cols=6
                            101,101,102,103,104,105,
                            106,107,108,109,110,111,
                            112,113,114,115,116,117,
                            118,119,120,121,122,123,
                            124,125,126,127,128,129};
    public:  
        Table(); // Default constructor  
        Table(int, int);//Constructor #2       
        ~Table(){ // Destructor
            delete [] table; delete [] rowSum; delete [] colSum;
            table=nullptr;   rowSum=nullptr;   colSum=nullptr;          
        }

        //Accessor Functions
        const T *getTable() {return table;}
        const T *getRowSum() {return rowSum;}
        const T *getColSum() {return colSum;}
        T getGrandTotal()    {return grandTotal;}
        int getTValues(int i) const { return tValues[i];}
};

//******************************************
//   Default Constructor
//******************************************
template<class T>
Table<T>::Table(){
    rows = 5;
    cols =6;
    grandTotal=0;            
    rowSum = new T[rows+1]; //allocating memory for pointer array
    colSum = new T[cols+1]; //allocating memory for pointer array
    table  = new T[rows*cols]; //allocating memory for pointer array
     // Initialize 1D array like it's a 2D array   
    int indx;
    for(int i=0;i<rows;i++){
        rowSum[i] = -99;          //initializing pointer arrays
        for(int j=0;j<cols;j++){    
            indx = (i*cols+j); //numbers between [0,(rows*cols)].      
            colSum[j] = -88;    //initializing pointer array
            table[indx] = 0;           
        }       
    }
}


//******************************************
//   Constructor #2
//******************************************
template<class T>
Table<T>::Table(int r, int c){  
   //cout<< "\nInside Table() r="<<r << " c=" << c <<endl;
    rows = r<2 ? 2 : r;
    cols = c<2 ? 2 : c;
    grandTotal=0;            
    rowSum = new T[rows+1]; //allocating memory for pointer array
    colSum = new T[cols+1]; //allocating memory for pointer array
    table  = new T[rows*cols]; //allocating memory for pointer array
    
    // Initialize 1D array like it's a 2D array   
    int indx;
    for(int i=0;i<rows;i++){
        rowSum[i] = -99;          //initializing pointer arrays
        for(int j=0;j<cols;j++){    
            indx = (i*cols+j); //numbers between [0,(rows*cols)].      
            colSum[j] = -88;    //initializing pointer array
            table[indx] = 0;            
        }    
    }
    setTable();
}

//******************************************
//      Set table
// Prints 1D pointer array like its a 2D array
// arguments passing rows=rows+1  cols=cols+1
//******************************************
template<class T>
void Table<T>::setTable(){
    
    //cout << "\nSetting table with " << rows*cols << " numbers...\n";
    
    int indx;    
    int count=0;
    float sumRow;
    
    // fill 1D array like it's a 2D array   
    for(int i=0;i<rows;i++){ 
        int sumRow = 0;
        for(int j=0;j<cols;j++){           
            
           //numbers between [0,(rows*cols)].
           indx = (i*cols+j);        
                
            if(!(indx%cols==cols)) {    
               table[indx] = tValues[count]; 
               sumRow += table[indx];
               count++;
             
                //on last col of each row save its sum to array                
                if(indx%cols==cols-1) {  //end of row
                   rowSum[i] = sumRow;
                   grandTotal += rowSum[i];
                   //cout<<"rowSum["<< i << "]=" << rowSum[i] << "  ";
                } 
           }
           //cout<<table[indx]<<" ";
        }
        //cout<<endl;
    }  


    //*******************************************
    //        calculates each column's sum         
    //   outer loop is columns instead of rows
    //******************************************* 
    float sum;
    count=0;
    for(int c=0;c<cols;c++){        
        sum=0;        
        for(int i=0;i<rows;i++){ 
            
            indx = (i * cols + c);  //numbers between [0,(row*col)]                       
            sum+=table[indx];         
            //cout<< "sum="<<sum<<" ";           
                      
            //if last row
            if(i==rows-1 ) {
                colSum[count]=sum;                 
                //cout<<"-->colSum["<<count<<"]="<<colSum[count]<<endl;
                count++;
            }
        }        
    } 
}

#endif /* TABLE_H */

