/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created:10-16-22 @11:10PM
 * gaddis-9thEd-ch12-prb11_sales_data_output
 */
#include <iostream>
#include <cstdlib>
#include <cstring>  //char[] functions
#include <string>   //string
#include <fstream>  //files
#include <cctype>   //tolower()
using namespace std;

const int SIZE = 4; //4 Quarters in a year

struct Company {
    string divName;
    float sales[SIZE];
};


//function prototypes

int main(int argc, char** argv) {

    //declare variables
    fstream binOut, //to write to binary file
            txtOut, //to write to txt file
            binIn, //to read binary file
            txtIn; //to read txt file

    int hghIndx, //index for highest sale's quarter 
            lowIndex; //index for lowest sale's quarter

    float ttlSale, //total sales

            ttlDSal, //total yearly sales for each division            
            hghQtrC, //highest sale's quarter for company
            lwQtrC; //lowest sale's quarter for company   

    string div[] = {"North", "South", "East", "West"};
    float s[] = {1000, 2000, 3000, 4000};
    float ttlQSal[SIZE] = {0}; //total company sales for each quarter
    Company c; //declare new structure


    //open output files or create file if it doesn't exist
    binOut.open("sales.bin", ios::out | ios::binary);
    txtOut.open("sales.txt", ios::out | ios::binary);

    //check for error opening file
    if (!binOut) cout << "Error opening binOut file\n";
    if (!txtOut) cout << "Error opening txtOut file\n";

    //initialize variables
    ttlSale = ttlDSal = 0;

    //write to binary and text output files
    //set each divisions sales data for the year
    for (int i = 0; i < SIZE; i++) {

        c.divName = div[i]; //set user input as structure member's value
        txtOut << c.divName << endl; //write structure's member value to txt file

        //loop to set each divisions 4 sale's quarters 
        for (int j = 0; j < SIZE; j++) {
            //          
            c.sales[j] = s[j]; //set user input as structure member's value                                     
            txtOut << "sales[" << j << "]= " << c.sales[j] << endl; //write structure's member value to txt file                         
        }
        txtOut << endl;

        //write entire structure to binary output file
        binOut.write(reinterpret_cast<char *> (&c), sizeof (c));
    }

    //close files
    binOut.close();
    txtOut.close();

    //open read in files 
    binIn.open("sales.bin", ios::in | ios::binary);
    txtIn.open("sales.txt", ios::in | ios::binary);

    //check for error opening file
    if (!binIn) {
        cout << "Error opening binIn file\n";
        return 0;
    }
    if (!txtIn) {
        cout << "Error opening txtIn file\n";
        return 0;
    }

    float t0 = 0, t1 = 0, t2 = 0, t3 = 0;
    //read first record from binary file
    binIn.read(reinterpret_cast<char *> (&c), sizeof (c));

    while (!binIn.eof()) { //while NOT end of file

        //display record      
        cout << "Division: " << c.divName << endl;

        for (int j = 0; j < SIZE; j++) {
            cout << "Quarter " << j + 1 << " = " << c.sales[j] << endl;
            switch (j) {
                case 0:
                {
                    t0 += c.sales[j];
                    ttlQSal[j] = t0;
                    break;
                }
                case 1:
                {
                    t1 += c.sales[j];
                    ttlQSal[j] = t1;
                    break;
                }
                case 2:
                {
                    t2 += c.sales[j];
                    ttlQSal[j] = t2;
                    break;
                }
                case 3:
                {
                    t3 += c.sales[j];
                    ttlQSal[j] = t3;
                    break;
                }
                default: cout << "hit switch() default.\n";
            }
        }

        //read next record from binary file
        binIn.read(reinterpret_cast<char *> (&c), sizeof (c));
    }
    for (int i = 0; i<SIZE; i++) {
        cout << "total quarter" <<i<<" sales = " << ttlQSal[i] << endl;
    }
    //close files   
    binIn.close();
    txtIn.close();

    return 0;
}

// function definitions
