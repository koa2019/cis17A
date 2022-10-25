/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on October 17, 2022, 7:24 PM
 * Purpose: midterm_prb4_Encrpt_decrypt_v1:
 *      Only has code for Case 1: 
 *      Case 1: Accepts 4 digit integer, encrypts, and decrypts it. *      
 *      4 digit integer must be between [0,7]
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cctype>
#include <fstream>
using namespace std;

const int SIZE = 4;

//function prototypes
bool getInput(string &);
int *setEncrypt(string, int &, const int, const int);
void prntArry(int *);
int *setDecrypt(int *, int, int);
void swap(int &, int &);

int main(int argc, char** argv) {

    //declare variables
    const int ADD6 = 6;
    const int MODBY8 = 8;

    bool isValid;
    char   ch,
           choice;
    string input;
    int sum;   
    int *encryptd,
        *decrypt;

    // validate user input
    do {
        cout << "Enter 1 to encrypt\n"
             << "Enter 2 to decrypt\n";
        cin >> choice;
        
    } while( !(choice-48==1 || choice-48==2)); 

    // menu
    switch (choice) {
        
        // Encrypt 4 digits in it
        case '1': {  
             
            // validate user input is 4 digits between [0,7]
            do {  
                
                isValid = getInput(input);
                
            } while (isValid == false || input.length() != 4);

            // encrypt 4 digits
            encryptd = setEncrypt(input, sum, ADD6, MODBY8);

            // display outputs
            cout << "\nOriginal Digits:  ";
            cout << input;
           
            cout << "\nEncrypted Digits: ";
            prntArry(encryptd);

            decrypt = setDecrypt(encryptd, ADD6, MODBY8);
            cout << "\nDecrypted Digits: ";
            prntArry(decrypt);
            
            break;
            
        } 
        // Encrypt 4 digits in it
        case '2': {
            
            // validate user input is 4 digits between [0,7]                                   
            break;       
        } default: {
            cout << "Error. Invalid Menu choice.\n";
            return 0;
        }
    }

    // De-allocate dynamic memory
    //delete []array;
    delete []encryptd;
    delete []decrypt;   
    encryptd = nullptr;
    decrypt = nullptr;

    return 0;
}

int *setDecrypt(int *encryptd, int ADD6, int MODBY8) {

    int digit,  //holds one integer at a time
        *decrpt = nullptr;  //create null pointer

    // dynamically allocate memory for a new integer array
    decrpt = new int[SIZE];

    // holds a single digit from encrypted array
    int eDigit;

    // 
    for (int i = 0; i < SIZE; i++) {

        eDigit = encryptd[i];

        if (!(eDigit == ADD6 || eDigit == MODBY8 - 1)) {

            digit = (eDigit + MODBY8) - ADD6;
            
        } else {

            digit = eDigit - ADD6;

        }
        decrpt[i] = digit;

    }
    
    // swap index 0 with index 2 AND
    // swap index 1 with index 2    
    swap(decrpt[0],decrpt[2]);       
    swap(decrpt[1],decrpt[3]);
    
    return decrpt;
}

// sets encrypted array elements
int *setEncrypt(string input, int &sum, const int ADD6, const int MODBY8) {
    
    // creates new pointer reference and sets it to null
    int *array = nullptr;

    // Dynamically allocate memory for an integer array
    array = new int[SIZE];

    // loop through each array element
    for (int j = 0; j < SIZE; j++) {
        
        // convert each character in string to integer
        array[j] = input[j] - 48;  
        
        // Add a number to element value, then modulus sum by 8
        sum = (array[j] + ADD6) % MODBY8;
        
        //set array to the value of sum
        array[j] = sum;
       
    }
    
    // swap index 0 with index 2 AND
    // swap index 1 with index 2   
    swap(array[0],array[2]);       
    swap(array[1],array[3]);
       
    // return pointer 
    return array;
}

void swap(int &a, int &b){
    
    int temp = a;
    a = b;
    b = temp;
}


// reads in string and validates user input with a flag
bool getInput(string &input) {
    
    cout << "Enter 4 digits between 0 and 7\n";
    cin >> input;

    for (int i = 0; i < SIZE; i++) {

        if (!(input[i] - 48 >= 0 && input[i] - 48 <= 7)) {
            
            cout << "Invalid digit. ";
            
            return false;       
        } 
    }
    return true;
}

void prntArry(int *array) {
    for (int i = 0; i < SIZE; i++) {
        cout << array[i];
    }
}
