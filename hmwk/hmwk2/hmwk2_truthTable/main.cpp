/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on 9/14/2022, 11:30 AM
 * Purpose:  Truth Table
 */

//System Level Libraries
#include <iostream>  //Input-Output Library
#include <iomanip>  //setw()
using namespace std;

//Execution begins here!
int main(int argc, char** argv) {
    
    //Declare Variables
    bool x,y;
    
  
    //Heading
    // cout<<"1 2  3  4   5    6   7    8    9      10 " << "     11      12      13"<<endl;
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y  !(X||Y) !X&&!Y"<<endl;
    
    while(cin >> x >> y ){
    
        cout<<(x?'T':'F')<<" ";
        cout<<(y?'T':'F')<<"  ";
        cout<<(!x?'T':'F')<<"  ";
        cout<<(!y?'T':'F')<<"   ";
        cout<<(x&&y?'T':'F')<<"    ";
        cout<<(x||y?'T':'F')<<"   ";
        cout<<(x^y?'T':'F')<<"    ";
        cout<<((x^y)^x?'T':'F')<<"     ";
        cout<<((x^y)^y?'T':'F')<<"       ";
        cout<<(!(x&&y)?'T':'F')<<"      ";
        cout<<(!x || !y?'T':'F')<<"        ";
        cout<<(!(x||y)?'T':'F')<<"      ";
        cout<<(!x&&!y?'T':'F');
        cout<<endl;
        
    }
    cout << endl;
  
    //Exit the program
    return 0;
}