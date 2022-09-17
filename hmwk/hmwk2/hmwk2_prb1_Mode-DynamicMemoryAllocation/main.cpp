/*  
 * File:   main.cpp 
 * Author: Danielle Fernandez
 * 9/16/22 @7pm
 * Purpose: hmwk2_prb1_mode-dynamicMemoryAllocation
 */

//Libraries 
#include <cstdlib>//Random number seed 
#include <iostream>//I/O Library 
#include <cmath>   //Math Library 

using namespace std;

//No Global Constants 

//Function Prototypes 
int *fillAry(int, int); //Fill the Array 
void prntAry(int *, int, int); //Print the Array 
void prntMod(int *); //Print the mode set 
void swap(int *, int *); //Swap 
void minPos(int *, int, int); //Find min Position 
void mrkSort(int *, int); //Mark Sort 
int *copy(const int *, int); //Copy the Array 
void shuffle(int *, int, int); //Shuffle the Array 
unsigned int GRB(); //Generate Random Bit 
void GR(unsigned int&); //Generate Random Number 
int *mode(const int *, int); //Find the mode set 

//Execution begins here 
int main(int argc, char*argv[]) {

    //Declare variables and fill 
    int arySize, //The array/set size 
        modNum, //Unique numbers in the array 
        *ary; //Pointer to the array 

    //Input the number of unique numbers 
    //and size of the array 
    cout << "The program finds the mode of a set" << endl;
    cout << "Input the size of the array and ";
    cout << "quantity of unique numbers" << endl;

    cin >> arySize>>modNum;

    ary = fillAry(arySize, modNum); // initialize pointer with array of numbers

    //Print the initial array 
    cout << "The Array before shuffling" << endl;
    prntAry(ary, arySize, modNum);

    //Shuffle the Array 7 times 
    shuffle(ary, arySize, 7);

    //Calculate the mode array 
    int *modeAry = mode(ary, arySize);  // create & initialize pointer

    //Print the initial array 
    cout << "The Array after shuffling" << endl;
    prntAry(ary, arySize, modNum);

    //Print the modal information of the array 
    cout << "The Modal Information" << endl;
    prntMod(modeAry);

    //Delete allocated memory 
    delete []ary;
    delete []modeAry;

    //Exit stage right 
    return 0;
}

/*********  FUNCTION DEFINITIONS   **********/

int *copy(const int *a, int n) {

    //Declare and allocate an array 
    int *b = new int[n];

    //Fill with passed array 
    for (int i = 0; i < n; i++) {

        b[i] = a[i];

    }
    
    //Return the copy 
    return b;
}


void prntMod(int *ary) {

    cout << "The number of modes = "
         << ary[0] << endl;

    cout << "The max Frequency = "
         << ary[1] << endl;

    if (ary[0] == 0) {

        cout << "The mode set = {null}" << endl;

        return;
    }

    cout << "The mode set = {";

    for (int i = 2; i < ary[0] + 1; i++) { // loop stops @numModes+1

        cout << ary[i] << ",";  // displays 1st nummber in the mode set
    }

    cout << ary[ary[0] + 1] << "}" << endl;
    //cout<< ary[6]<<endl;
}


void mrkSort(int *array, int n) {

    for (int i = 0; i < n - 1; i++) {

        minPos(array, n, i);
    }
}


void minPos(int *array, int n, int pos) {

    for (int i = pos + 1; i < n; i++) {

        if (*(array + pos)>*(array + i))

            swap(array + pos, array + i);
    }
}

void swap(int *a, int *b) {

    //Swap in place 
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

void prntAry(int *array, int n, int perLine) {

    //Output the array 
    for (int i = 0; i < n; i++) {

        cout << *(array + i) << " ";

        if (i % perLine == (perLine - 1))cout << endl;

    }
    cout << endl;
}

int *fillAry(int n, int modNum) {

    //Allocate memory 
    int *array = new int[n];

    //Fill the array with 2 digit numbers 
    for (int i = 0; i < n; i++) {

        *(array + i) = i % modNum;
        //*(array+i)=rand()%modNum; 
    }
    
    //Exit function 
    return array;
}


void shuffle(int *a, int n, int nShuf) {

    unsigned int temp;

    for (int shuf = 1; shuf <= nShuf; shuf++) {

        for (int i = 0; i < n; i++) {

            GR(temp);

            temp %= n;

            if (i != temp)swap(a[i], a[temp]);
        }
    }
}


unsigned int GRB() {

    static unsigned int seed = 0;

    seed += (seed * seed) | 5;

    return seed & 0x80000000;
}


void GR(unsigned int& value) {

    value = 0;

    const unsigned int numBits = sizeof (int) * 8;

    unsigned int* dataPointer = (unsigned int *) &value;

    for (unsigned int index = 0; index < numBits; ++index){
        
        if (GRB()) {

            unsigned int pointerIndex = index / 32;

            unsigned int mask = 1 << index % 32;

            dataPointer[pointerIndex] |= mask;
        }
    }
}


//This just a stub.  You are to fill in the correct solution 
int *mode(const int *array, int arySize) {

    //Copy the array 
    int *ary = copy(array, arySize);

    //Sort the copy 
    mrkSort(ary, arySize);

    //cout<<"ary after mrkSort\n"; 
    //prntAry(ary,arySize,10); 

    int j=2, 
        count = 0, //number times an elemnt was alike 
        freq = 0, //number of times an elemnt was found 
        maxFreq = 0, // max number of times an elemnt was found 
        numMods = 0; // number of total modes around in array 

    int elemnt = ary[0]; // declare variable and set to the first value in the array 
    //cout << "elemnt = " << elemnt<<endl;
    
    //Allocate the mode array 
    //Again this is just a stub. 
    int nmodes = 0;
    int *modeAry = new int[nmodes + 2]; // declare pointer array where its memory is dynamic 
    
    // initialize pointer to zero
    *modeAry=0;
    //modeAry[0] = 0; //Stub returns no modes 
    //modeAry[1] = 1; //Stub returns Frequency 1   
    //modeAry[2] = 0; // stub returns values of the modes that freq==maxFreq

    //Find the max Frequency 
    for (int i = 0; i < arySize; i++) {

        //cout << "elemnt = " << elemnt << "   ary[i]= " << ary[i] << endl; 

        if (elemnt == ary[i]) { // check if elemnts are the same 

            //cout << "count= "<<count; 
            count++; // increment count by 1 
            //cout << "  count++ = " << count << endl; 

            if (count >= 2 && count > freq) { // check for the most times an alike elemnt was found 

                //cout << "count>freq = " << count << ">" << freq << endl; 
                freq = count; //set max freq to count 

                if (freq > maxFreq) maxFreq = freq;
            }
        } else {
           
            if (count == maxFreq) { // check how many mode sets equal the maxFreq
                
                numMods++; // keeps count of total number of mode sets found in array 
                //cout << "count="<<count << "   maxFreq= "<< maxFreq << "   numMods = " << numMods << endl; 

               //j=2;
                modeAry[j++] = elemnt;               
                //cout << "j=  "<< j << "   elemnt=  " << elemnt << endl;                           
            }
            
            elemnt = ary[i]; //reset value of element to current array index 
            count = 1;  //reset count to zero 
        }
    }

    if(maxFreq==0) maxFreq=1;   // if no modes were found in array, then set maxFreq to 1;
    
    //Fill the mode array 
    modeAry[0] = numMods; //sets arrays first index to number of nodes with max freq

    modeAry[1] = maxFreq; //sets array's 2nd index to the max number of freq found in array

    //Delete the allocated copy and return 
    delete []ary;

    return modeAry; // return reference to an array of integers
} 