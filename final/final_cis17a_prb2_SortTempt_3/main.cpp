/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 12-07-2022 @ 7:36 PM
 * Purpose:  final_cis16a_prb2_sortTemplate_2
 * 
 * Driver program for the above class. Create your own file to read.
 * v1:  solves it with a class.
 * v2:  Converts class to a template. Moves class functions to Prb2Sort.h file.
 * v3: From the Prb2Sort.h file Try to move 
 * lines 71-80 and 107-135 to inside of sort1() 
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <fstream> //ifstream for reading file
using namespace std; //STD Name-space where Library is compiled

//User Libraries
#include "Prb2Sort.h"


//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {

    cout << "The start of Problem 2, the sorting problem" << endl;
 
    
    //Create new object
    Prb2Sort<char> rc;
    //Prb2Sort rc;
  
    bool ascending = true;    
    ifstream infile;
    
    infile.open("Problem2b.txt", ios::in);
    if(!infile) cout<<"Error reading infile\n";
    
    // creating pointer and allocating memory for a char array[160]
    char *ch2 = new char[10*16];
   
    //creating new pointer and initializing it to previous pointer
    char *ch2p = ch2;
    
    int count = 0;
    
    //read in text file
    cout << "\n*ch2 contents:\n";
    while (infile.get(*ch2) ) {
       
        //cout<<"i="<<count<<"->"<<*ch2<<endl;
        cout << *ch2;
        ch2++;               
        count++;
        if(count%16==0)cout<<endl;
    }   
    infile.close();      
    
    cout << "\n\nWhich column would you like to sort on?" << endl;
    int column=15;
    //cin>>column;
  
    
    //Call function that Sorts a 2D array represented as a 1 dim array            
    char *zc = rc.sortArray(ch2p, 10, 16, column, ascending);
    
    cout<<"\nSorted array on column " << column << endl;
   
    //Print a 1D array like a 2D array. Prints every 16 elements, 10 times
    for(int i=0;i<10;i++){
        for(int j=0;j<16;j++){
            cout<<zc[i*16+j];
            //if(j==15)cout<<endl;
        }    
        cout<<endl;
    }
    
    delete []zc;
  
    cout << endl;

    return 0;
}