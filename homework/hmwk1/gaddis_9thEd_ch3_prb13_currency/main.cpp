/* 
 * File:   main.cpp
 * Author: Danielle Fernandez *
 * Created on September 6, 2022, 7:15 PM
 * Purpose: gaddis_9thEd_ch3_prb13_currency
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

const float YENPERDLLR=98.93f; // 1 US dollar to Yen conversion
const float EUROPERDLLR=0.74f; // 1 US dollar to euro conversion

int main(int argc, char** argv) {
    
    // declare variables
    float dollar,
          yen,
          euro;
    
    // set variables
    dollar=yen=euro=0.0f;
    
    //display instructions and read in dollar amount
    cout << "This program converts US dollars to Yen or Euros.\n"
         << "Enter a dollar amount. (1.00) ";
    cin >> dollar;
    
    // convert dollar to yen and euro values
    yen=dollar*YENPERDLLR;
    euro=dollar*EUROPERDLLR;
    
    // display output
    cout << fixed << setprecision(2) << endl
         << setw(8) << "US dollar" << setw(9) << "Yen" << setw(10) << "Euro" <<  endl
         << setw(8) << right << dollar << " "
         << setw(9) << yen << " "
         << setw(10) << euro;
    
    return 0;
}

