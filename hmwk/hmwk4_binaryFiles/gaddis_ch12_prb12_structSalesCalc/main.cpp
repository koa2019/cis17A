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
    int qtr[SIZE];
    float sales[SIZE];
};
struct Report{
    float cQtrTot;
};
//function prototypes

int main(int argc, char** argv) {

    float totQtrC,  //total company sales for each quarter
            totYrDiv, //total yearly sales for each division
            totYrC, //total yearly company sales
            avgQtrDiv, //average quarterly sales for divisions
            hghQtrC, //highest quarters for company
            lwQtrC; //lowest quarters for company
    
    Company c;
    Report *rep=nullptr;
    fstream binIn,//to read binary file
            txtIn;//to read txt file

    binIn.open("sales.bin", ios::in | ios::binary);
    txtIn.open("sales.txt", ios::in | ios::binary);
    
    //check for error opening file
    if (!binIn) cout << "Error opening binIn file\n";
    if (!txtIn) cout << "Error opening txtIn file\n";
    
    totQtrC=totYrDiv=totYrC=avgQtrDiv=0;
    
    //set each divisions sales data for the year
    for (int i = 0; i<SIZE; i++) {

        
        
        //loop to calculate yearly sums all 4 quarters for each division in company
        for (int j = 0; j < SIZE; j++) {

        
                //cout << "Enter Quarter\n";
                //cin >> c.qtr[i];
                //txtIn >> c.qtr[i];
                
                //cout << "Sales for the Quarter\n";
                
                //txtIn >> c.sales[i];
                //totQtrC +=c.sales[i];
                //rep->cQtrTot = totQtrC;
                
           
            
            
        }
        
        
        //write to outFile
        //binIn.read(reinterpret_cast<char *>(&c),sizeof(c));        
    }
   
    //cout << rep->cQtrTot << endl;
    //close files
    binIn.close();
    txtIn.close();
    return 0;
}

// function definitions
