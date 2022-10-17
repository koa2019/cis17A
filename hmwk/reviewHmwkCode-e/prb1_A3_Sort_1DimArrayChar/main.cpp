/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on 9/14/22 @8am
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
#include <string.h> //.length()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
int read1(char arr[]);
void bubbleSort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    string str;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size
    //cout << "sizeDet = " << sizeDet << endl;

    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        bubbleSort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}


int read(char arr[]){ 
   
    char ch;
    int i=0;
    
    while(cin >> ch) {
            arr[i]=ch;
            i++;
    }
    
    return strlen(arr);
}

int read1(char arr[]){ 
   
    string str;
    cin >> str;
    
    for(int i=0;i<str.length();i++){
        arr[i]=str[i];
    }
    return str.length();
}

void bubbleSort(char a[], int sizeIn){
    
    bool isMin;
    int last=sizeIn-1;
    do{
        isMin=false;
        for(int i=0;i<last;i++){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                isMin=true;
            }
        } 
        last--;
    }while(isMin);
}

void print(const char arr[],int sizeIn){

  for(int i=0;i<sizeIn;i++){
        cout << arr[i];
    }
    cout << endl;
}
    
    