/* 
 * File:   main.cpp
 * Author: Danielle Fernandez 
 * Created on 09/07/2022, 6:58 PM
 * Purpose: gaddis_9thEd_ch5_prb11_population
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    
    // declare variables
    int   nDays;      // number days to multiply by
    float strtPop,   // starting population size
          newPop,   // estimated size of population
          avg;     // average daily population increase as percentage 
  
    // validate user inputs
    while(strtPop < 2){
        cout << "Enter the size of organism's population. (Must be greater than 2).  ";
        cin >> strtPop;            
    }
    
    do{
        cout << "Enter population's average daily increase as percentage.  ";        
        cin >> avg;       
    }while(avg < 0);
        
    while(nDays < 1){
        cout << "Enter the number of days the population will increase.  ";
        cin >> nDays;
    }
       
    // calculate how much the population size will increase
    if(avg>=1) avg/=100;   // if avg is greater than zero, then convert average to a decimal
    newPop=strtPop;        // initiate newPop to the starting population size
    newPop += strtPop*avg*nDays;    // calculate how much the population will grow and add to the starting population size
    
    // display output
    cout << "Starting population size: " << strtPop << endl
         << "# of days population will grow: " << nDays << endl
         << fixed << setprecision(2)
         << "Daily Average increase: " << avg << endl         
         << "Predicted population size: " << newPop << endl;
    
    return 0;
}

