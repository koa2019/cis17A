/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created: 10-16-22 @7:25PM
 * gaddis-9thEd-ch12-prb8_arryFileFunc
 */
#include <iostream>
#include <fstream>  //files
#include <string>   //string
using namespace std;

//function prototypes
void arr2File(string,int*,int);
void file2Arr(string,int*,int);

int main(int argc, char** argv) {

    int size = 8;   
    int arr1[]={11,13,15,67,88,953,2,101};
    int arr2[size];
    
    //open text and binary files
    string inputFile = "test.dat";    
   
    //write an array to a file
    arr2File(inputFile,arr1,size);
    
    //read data from a file
    file2Arr(inputFile,arr2,size);   

    return 0;
}

// function definitions

//write data to file
void arr2File(string file, int *ptr2Arr, int size){
    
    cout<<"Arr1 read from main()\n";
    for(int i=0;i<size;i++){
        cout << *(ptr2Arr + i) << " ";
    }
    cout << endl;
    
    //declare file
    ofstream outFile;
    outFile.open(file.c_str(), ios::out | ios::binary);//c_str()converts contents f string to a c-string and returns pointer to c-string

    //read array and write to file
    for(int i=0;i<size;i++){
        outFile << *(ptr2Arr+i) << " ";
    }
    outFile.close();
}

//read data from file
void file2Arr(string file,int *ptr2Arr, int size){
    
    //declare file
    ifstream inFile;
    inFile.open(file.c_str(), ios::in | ios::binary);//c_str()converts contents f string to a c-string and returns pointer to c-string

    //read contents from file and write into an array
    for(int i=0;i<size;i++){
        inFile >>*(ptr2Arr+i);
    }
    //display values in arr2
    cout<<"Arr2 Numbers read from file\n";
    for(int i=0;i<size;i++){
        cout << *(ptr2Arr+i) << " ";
    }

    inFile.close();
}