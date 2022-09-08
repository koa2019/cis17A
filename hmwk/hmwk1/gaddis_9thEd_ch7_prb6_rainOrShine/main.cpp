/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on 9/7/2022, 9:00 PM
 * Purpose: gaddis_9thEd_ch7_prb6_rainOrShine
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// function prototypes
void showMonth(int);

int main(int argc, char** argv) {

    // declare and initialize variables
    ifstream inFile;

    const int ROW = 3;
    const int COL = 30;
    const int SUMROW = 4;
    const int SUMCOL = 3;

    int row = 0,
        perLine = 30,
        nMonths = 3,
        nDays = 30;
    
    char weather[ROW][COL] = {}; //weather R=rainy, C=cloudy, S=Sunshine
    int sums[SUMROW][SUMCOL] = {0};

    // open file that already exists
    inFile.open("weather.txt");

    cout << endl << endl;
    // read in file data and display values
    for (int month = 0; month < nMonths; month++) {

        // call function to display row names
        showMonth(month);

        for (int day = 0; day < nDays; day++) {

            // read and store char into 2D array
            inFile >> weather[month][day];

            // display each arrays index value
            cout << weather[month][day] << " ";

            // format 2D array output
            if (day % perLine == (perLine - 1)) cout << endl;
        }
    }

    // sum the number of rainy, cloudy, sunny days in each month
    // loop through each month and its number of days and count
    for (int nRow = 0; nRow < nMonths; nRow++) {
        for (int nCol = 0; nCol < nDays; nCol++) {

            if      (weather[nRow][nCol] == 'S') sums[nRow][0]++;
            else if (weather[nRow][nCol] == 'R') sums[nRow][1]++;
            else if (weather[nRow][nCol] == 'C') sums[nRow][2]++;
        }
    }
    // calculate total number of rainy, cloudy, sunny days in the last 3 months
    for (int month = 0; month < SUMROW - 1; month++) {
        for (int col = 0; col < SUMCOL; col++) {
            sums[3][col] += sums[month][col];
        }
    }

    // display sums 2D array values
    cout << endl << endl << setw(7) << " "
         << setw(6) << "S "
         << setw(5) << "R "
         << setw(5) << "C " << endl
         << "-----------------------" << endl;

    for (int month = 0; month < SUMROW; month++) {

        // call function to display row names
        showMonth(month);
        
        // display each columns value
        for (int col = 0; col < SUMCOL; col++) {
            cout << setw(5) << sums[month][col];
        }
        cout << endl;
    }

    // close file
    inFile.close();
    return 0;
}

// function definitions

void showMonth(int month) {
    string m;
    switch (month) {
        case 0: m = "June ";
            break;
        case 1: m = "July ";
            break;
        case 2: m = "August ";
            break;
        default: m = "Totals ";
    }
    cout << setw(7) << m;
}
