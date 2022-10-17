/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created:10-16-22 @8:23PM
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
    int qtr[SIZE];
    float sales[SIZE];
};

//function prototypes

int main(int argc, char** argv) {

    Company c;
    fstream binOut,//to write to binary file
            txtOut;//to write to txt file

    binOut.open("sales.bin", ios::out | ios::binary);
    txtOut.open("sales.txt", ios::out | ios::binary);
    
    //check for error opening file
    if (!binOut) cout << "Error opening binOut file\n";
    if (!txtOut) cout << "Error opening txtOut file\n";
    
    //set each divisions sales data for the year
    for (int i = 0; i<SIZE; i++) {

        cout << "Enter division's name\n";
        cin >> c.divName;
        txtOut << c.divName << endl;
        
        //loop to set all 4 quarters for each division
        for (int j = 0; j < SIZE; j++) {

            do {
                cout << "Enter Quarter\n";
                cin >> c.qtr[i];
                txtOut <<"Quarter "<< c.qtr[i] << endl;
                
                cout << "Enter sales for the Quarter\n";
                cin >> c.sales[i];
                txtOut << "Sales $" << c.sales[i];
                
            } while (c.sales[i] < 0);//user validation   
            
            txtOut << endl;
        }
        txtOut << endl;
        
        //write to outFile
        binOut.write(reinterpret_cast<char *>(&c),sizeof(c));        
    }
   
    //close files
    binOut.close();
    txtOut.close();
    return 0;
}

// function definitions
