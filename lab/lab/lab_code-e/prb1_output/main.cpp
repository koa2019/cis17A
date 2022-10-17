/* 
 * File:
 * Author: Danielle Fernandez
 * Date: 3-2-22
 * Purpose: format number outputs
 * Version: 4
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>  // setw(), fixed, setprecision
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    float n1, n2, n3, n4;
    //Initialize or input data here
    
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    cin >> n1;
    cin >> n2;
    cin >> n3;
    cin >> n4;
   
    
    //Format and display outputs here
    cout << setw(9) <<                n1 << setw(10) << setprecision(2) << showpoint << n1 << setw(10) << setprecision(3) << n1 << endl;
    cout << setw(9) << noshowpoint << n2 << setw(10) << setprecision(2) << showpoint << n2 << setw(10) << setprecision(3) << n2 << endl;
    cout << setw(9) << noshowpoint << n3 << setw(10) << setprecision(2) << showpoint << n3 << setw(10) << setprecision(3) << n3 << endl;
    cout << setw(9) << noshowpoint << n4 << setw(10) << setprecision(2) << showpoint << n4 << setw(10) << setprecision(3) << n4;
    
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}