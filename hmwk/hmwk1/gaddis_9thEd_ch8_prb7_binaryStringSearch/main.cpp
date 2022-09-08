/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on 9/7/2022, 11:20 PM
 * Purpose: gaddis_9thEd_ch8_prb7_binaryStringSearch
 */


#include <iostream>
#include <iomanip>

using namespace std;

// function prototypes
int binarySearch(const string[], int, string);
void sort(string[], int);
void sort(const string[], string[], int);

// program starts here
int main(int argc, char** argv) {

    // declare and initialize variables
    const int SIZE = 20;
    
    // array
    string name[SIZE] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                          "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                          "Taylor, Terri", "Johnson, Jill",
                          "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                          "James, Jean", "Weaver, Jim", "Pore, Bob",
                          "Rutherford, Greg", "Javens, Renee",
                          "Harrison, Rose", "Setzer, Cathy",
                          "Pike, Gordon", "Holland, Beth"};
    string srtName[] = {};
    int    results; // hold search results
    string search = ""; // string looking for
    
    // display list of names
    cout << "List of names: \n-------------\n";
    for(int i=0;i<SIZE;i++){        
        cout << name[i] << endl;       
    }
    
    // get name user is searching for
    cout << "\n\nEnter the person's last name you want to find.\n";
    getline(cin,search);
    cout << "You are looking for " << search << endl;
    
    // sort names alphabetically
    //sort(name,srtName,SIZE);
    sort(name,SIZE);
    
    // display sorted name array
    cout << "\n\nSorted names: \n-------------\n";
    for(int i=0;i<SIZE;i++){        
        cout << name[i] << endl;       
    }
    cout << endl << endl;
    
    // call function that will return the search values index in names array
    results = binarySearch(name,SIZE,search);
    
    // if results contains -1 the last name was not found
    if(results == -1){
        cout << "\n\nSorry " << search << " was not found in the array.\n";
    } else {
        // results returns the array's index of where the search word was located
        cout << "\n\nThat name is found at element " << results 
             << " in the name array.\n";
    }
    
    return 0;
}

/*******   FUNCTION DEFINITIONS *********/

// binary search
int binarySearch(const string name[], int size, string search){
    
    int  first = 0,      // first array element
         last = size-1,  // last array element
         middle,         // midpoint of search
         position = -1;  // position of search value
    bool isFound = false;   // flag
    
    while(!isFound && first <= last){
        
        middle = (first+last)/2;    // calculate midpoint
        
        cout << "middle " << middle << " = " << name[middle]<<endl;
        
        if(name[middle] == search){  // if search is found at midpoint
            
            isFound = true;
            position = middle;
        } else if(name[middle] > search){    // if search is in lower half
            last = middle-1;           
        } else first = middle+1;    // if search is in upper half        
    }
    return position;
}
// sort names alphabetically
void sort(string name[], int size){
    
    int maxElmt, // size-1 == (20-1)=19
        index;
    
    // start outer loop at last index in array
    for(maxElmt=size-1;maxElmt>0;maxElmt--){
        
        // inner loop starts at zero to last index
        for(index=0;index<maxElmt;index++){
            
            // compares index to the index next to it
            if(name[index]>name[index+1]){
                
                // if true, then swaps their values
                swap(name[index],name[index+1]);
            }
        }        
    }
}


void sort(const string[], string[], int){
    
}
