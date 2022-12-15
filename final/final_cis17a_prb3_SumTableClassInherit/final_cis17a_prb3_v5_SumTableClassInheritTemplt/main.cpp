/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 12-10-2022 @ 11:45 AM
 * Purpose:  final_cis17a_prb3_v3_sumTableClassInherit
 * 
 * v1: 
 * Converted 2D array to a pointer in Table class.
 * Created Table class functions 
 * v2:
 * Found sums for rows and cols in the Table class
 * Created a bigger table in the Prob3TableInheritd class's constructor
 * Couldn't figure out how to inherit table class and save it to *augTable in
 * child class.
 * Need to change change everything to template 
 * v3:
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here
#include "Prob3TableInheritd.h" //inherits Table class


//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here
void read(int &,int &);//Prompt for size then table
void sum(const int *,int,int,int*);//Calculates Sum of rows,cols,grand total & adds them to new bigger array


//Program Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables       
    int rows, cols;                
   
//    cout  << "\n\n\tCIS17A Final Problem 3.\n" 
//          << "Program Input a table and output the Augment row, col and total sums.\n\n"; 
         
    
    //Input the original table
    read(rows,cols);  
    
    Prob3TableInheritd<int> table(rows,cols);
    //Prob3TableInheritd table(rows,cols); 
    
    //Output the original array
    cout<<endl<<"The Original Table\n";
   
    //Create new object and print it
    const int *naugT = table.getTable();
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){            
           cout << "[" << setw(2) << i*cols+j << "]=";
           cout << setw(3) << naugT[i*cols+j] <<"  ";                                      
        }
        cout<<endl;
    }   
    cout << endl;
    
    //***************************************
    //       Output the augmented array
    //***************************************
    
    
    //Create new object and print it
    //Prob3TableInheritd table2(rows,cols); 
    const int *augT = table.getAugTable();

    cout<<"\n\nThe Augmented Table\n";
    
    for(int i=0;i<=rows;i++){     //changed condition to <=
        for(int j=0;j<=cols;j++){ //changed condition to <=        
      
           cout << "["  << setw(2) << (i*(cols+1)+j) << "]=";
           cout << setw(3) << augT[i*(cols+1)+j] <<"  ";                                       
        }
        cout<<endl;
    }   
    cout << endl;
    
    return 0;
}

void read(int &rows,int &cols){

    cout << "Input the number of rows and cols. num<20 for each\n"; 
    //cin >> rows >> cols;
    rows = 5; // for testing purposes. when u dont want to cin everytime
    cols = 6; 
    cout << "Read in rows=" << rows << ",  Number cols=" << cols << endl;
}

// augAry is col+1 and row+1 bigger for the sums
void sum(const int *array,int rows,int cols,int *augAry){
    
//   // cout<<"\n rows"<<rows <<"\n c"<<cols<<endl;
//    int sumCol, sumRow, ttl=0;
//    
//    // loop through 
//     for(int i=0;i<rows+1;i++){
//         
//         sumRow=0;
//         
//        for(int c=0;c<cols+1;c++){
//           
//            //copy original array to new array
//            augAry[i][c]=array[i][c];
//           // cout <<  augAry[i][c] <<endl;            
//            
//            sumRow+=array[i][c];
//            //cout <<endl << "sumR["<<i<<"]["<<c<<"] " << sumRow <<endl;
//            
//            ttl+=augAry[i][c];
//            //cout <<endl << "ttl["<<i<<"]["<<c<<"] " << ttl <<endl;
//            
//            // saves the row's sum to the last index in array
//            if(c==cols){ augAry[i][c]=sumRow;}
//           
//            // saves the last row's sum 
//            if(i==rows && c==cols)augAry[i][c]=ttl;
//            
//        }
//        //cout << "\n sumR=" << sumRow <<endl;
//     }
//     
//    //calculate each column's sum       
//    ttl=0;
//    
//    // outer loop is columns instead of rows
//    for(int c=0;c<cols;c++){
//        
//        sumCol=0;
//        
//        for(int i=0;i<rows;i++){
//           
//            sumCol+=array[i][c];
//            //cout<< "sumCol= "<<sumCol<<endl;            
//           
//            //            //if(i==2 && c==1){
                //augAry[i][c]=sumCol;
//           //  cout <<" r= "<<i <<" c= "<< c;
    //}
//        }
//        //cout<< "\n sumCol= " << sumCol<<endl;
//    }               
}

