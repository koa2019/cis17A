/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created:10-16-22 @11:10PM
 * gaddis-9thEd-ch12-prb11_sales_data_output
 */
#include <iostream>
#include <iomanip>
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

    int count,
        hgIndx, //index for highest sale's quarter 
        lwIndx; //index for lowest sale's quarter

    float hgQtrC, //highest sale's quarter for company
          lwQtrC, //lowest sale's quarter for company  
          tDiv,
          ttlYrSal,
          t0,t1,t2,t3;

    string div[] = {"North", "South", "East", "West"};
    float s[] = {1000, 2000, 3000, 4000};
    float ttlQSal[SIZE] = {0}; //total company sales for each quarter
    float ttlDSal[SIZE] = {0}; //divisions total sales for yr
    
    Company c; //declare new structure

    //open output files or create file if it doesn't exist
    binOut.open("sales.bin", ios::out | ios::binary);
    txtOut.open("sales.txt", ios::out | ios::binary);

    //check for error opening file
    if (!binOut) cout << "Error opening binOut file\n";
    if (!txtOut) cout << "Error opening txtOut file\n";    

    //write to binary and text output files
    //set each divisions sales data for the year
    for (int i = 0; i < SIZE; i++) {

        c.divName = div[i]; //set user input as structure member's value
        txtOut << c.divName << endl; //write structure's member value to txt file

        //loop to set each divisions 4 sale's quarters 
        for (int j = 0; j < SIZE; j++) {
                      
            c.sales[j] = s[j]; //set user input as structure member's value                                     
            txtOut << "sales[" << j << "]= " << c.sales[j] << endl; //write structure's member value to txt file                         
        }
        txtOut << endl;

        //write entire structure to binary output file
        binOut.write(reinterpret_cast<char *> (&c), sizeof (c));
    }

    //close output files
    binOut.close();
    txtOut.close();

    
    //OPEN & READ data from binary file
    binIn.open("sales.bin", ios::in | ios::binary);
    txtIn.open("sales.txt", ios::in | ios::binary);

    //check for error's opening file
    if (!binIn) {
        cout << "Error opening binIn file\n";
        return 0;
    }
    if (!txtIn) {
        cout << "Error opening txtIn file\n";
        return 0;
    }

    t0=t1=t2=t3=ttlYrSal=0;
    count=0;
    
    //read first record from binary file
    binIn.read(reinterpret_cast<char *> (&c), sizeof (c));

    while (!binIn.eof()) { //while NOT end of file
    
        //display record      
        cout << "Division: " << c.divName << endl;
        tDiv=0;
        for (int j = 0; j < SIZE; j++) {
            
            cout << "Quarter " << j + 1 << " = " << c.sales[j] << endl;
            
            //calculate division's total sales 
            tDiv += c.sales[j];
            ttlDSal[count] = tDiv;//set division's total sales for the year
           
            switch (j) {//calculate companies total sales for each quarter
                case 0:{
                    t0 += c.sales[j];
                    ttlQSal[j] = t0;
                    break;
                }case 1:{
                    t1 += c.sales[j];
                    ttlQSal[j] = t1;
                    break;
                }case 2:{
                    t2 += c.sales[j];
                    ttlQSal[j] = t2;
                    break;
                }case 3:{
                    t3 += c.sales[j];
                    ttlQSal[j] = t3;
                    break;
                }default: cout << "hit switch() default.\n";
            }            
        }
        count++;
        //read next record from binary file
        binIn.read(reinterpret_cast<char *> (&c), sizeof (c));
    }
    
    //set starting point for high and low comparisons
    hgQtrC=ttlQSal[0];
    lwQtrC=ttlDSal[0];
    
    cout<<endl;
    for (int i = 0; i<SIZE; i++) {
        
        cout << "Companies Total Qtr" << i+1 <<" sales = " << ttlQSal[i] << endl;        
        
        ttlYrSal += ttlDSal[i]; //companies total sales for the year
        
        if(ttlQSal[i]>hgQtrC){//find companies highest earning quarter in the year
            hgIndx = i;
            hgQtrC=ttlQSal[i];
        }
        if(ttlQSal[i]<lwQtrC){//find companies lowest earning quarter in the year
            lwIndx=i;
            lwQtrC=ttlQSal[i];
        }        
    }
    
    //display companies averagely quarterly sales
    cout<<endl;
    for (int i = 0; i<SIZE; i++) {
        cout << setw(5) << left << div[i] << " Average Qtrly sales = " << ttlQSal[i]/SIZE << endl;
    }
    
    //display each division's total sales for the year
    cout<<endl;
    for (int i = 0; i<SIZE; i++) {
        cout << setw(5) << div[i] << " total sales for the year = " << ttlDSal[i] << endl;
    }
    cout<<endl;
    
    cout<<"Companies Total yearly sales = "<< ttlYrSal <<endl;
    cout <<"Quarter " << hgIndx+1 << " at $" << hgQtrC << " was the highest earning.\n";
    cout <<"Quarter " << lwIndx+1 << " at $" << lwQtrC << " was the lowest earning.\n";
    
    //close files   
    binIn.close();
    txtIn.close();

    return 0;
}

// function definitions
