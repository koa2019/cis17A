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
void wrtBinary(fstream &,int *,int);
void wrtTxt(fstream &,int *, int);
void readBinary(fstream &,int *,int);
void prntTxt(int *);


int main(int argc, char** argv) {

    fstream txtFile,
            binFile;
    int size = 8;
    int *ptr2Arr = nullptr;
    int arr[size]={11,13,15,67,88,953,2,101};
    
    ptr2Arr = arr;  //set address of arr to pointer
    
    //open text and binary files
    string file2 = "data.bin";
    txtFile.open("data.txt", ios::in | ios::out);
    binFile.open(file2.c_str(), ios::in | ios::out |ios::binary);//c_str()converts contents f string to a c-string and returns pointer to c-string

    wrtTxt(txtFile,ptr2Arr,size);
    wrtBinary(binFile,ptr2Arr,size);
    readBinary(binFile,ptr2Arr,size);
    prntTxt(ptr2Arr);
    //close files
    txtFile.close();
    binFile.close();

    return 0;
}

// function definitions

//write to txt file
void wrtTxt(fstream &outFile, int *ptr2Arr, int size){    
    
    for(int i=0;i<size;i++){
        outFile << "Record #" << i << endl;
        outFile << *(ptr2Arr + i) << endl;
    }
}
//write data to file
void wrtBinary(fstream &outFile, int *ptr2Arr, int size){
    outFile.write(reinterpret_cast<char *>(ptr2Arr),sizeof(ptr2Arr));
}

//read data from file
void readBinary(fstream &outFile,int *ptr2Arr, int size){
    outFile.read(reinterpret_cast<char *>(ptr2Arr),sizeof(ptr2Arr));
}

void prntTxt(int *ptr2Arr){
    
    cout << "Array\n";
    for(int i=0;i<sizeof(ptr2Arr);i++){
        cout << "Record #" << i << endl;
        cout << *(ptr2Arr + i) << endl;
    }    
}