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


//Function Prototypes Here
void read(int &,int &);//Prompt for size then table

//Program Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables       
    int rows, cols;                
   
//    cout  << "\n\n\tCIS17A Final Problem 3.\n" 
//          << "Program Input a table and output the Augment row, col and total sums.\n\n"; 
         
    
    //Input the original table
    read(rows,cols);  
    
    Prob3TableInheritd<int> table(rows,cols);
    
    //Output the original array
    cout<<endl<<"The Original Table\n";
   
    //Create new object and print it
    const int *naugT = table.getTable();
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){                    
           cout << setw(3) << naugT[i*cols+j] <<"  ";                                      
        }
        cout<<endl;
    }   
    cout << endl;
    
    
    //***************************************
    //       Output the augmented array
    //***************************************    
    const int *augT = table.getAugTable();

    cout<<"\n\nThe Augmented Table\n";
    
    for(int i=0;i<=rows;i++){     //changed condition to <=
        for(int j=0;j<=cols;j++){ //changed condition to <=        
      
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
