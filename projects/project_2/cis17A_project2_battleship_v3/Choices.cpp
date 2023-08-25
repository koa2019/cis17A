#include "Choices.h"
// System Libraries: 
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cmath>    // round()
#include <cstdlib>  // rand()
#include <ctime>    // time library for rand()
#include <cstring>  // char [] library
#include <string>   // length() library

#include <cctype>   // toupper()
using namespace std; 


//Default constructor

Choices::Choices() {
    // set random number seed
    //srand(static_cast<unsigned int> (time(0)));
   
    size = 20;
    board = new char[size];
    indx = new int[size];

    //Initialize both arrays 
    for(int shuffle=0;shuffle<2;shuffle++){ //randomized values 2xs
    for (int i = 0; i < size; i++) {
        //board[i] = bChoice[rand()%SIZE17]; // fills with S=ship or B=blank
        board[i] = rand()%26+65; // rand() uppercase letters from alphabet            
        indx[i] = i;
    }
    }
    setBoard();
}

//Constructor #2
Choices::Choices(int s) {

    size = (s<2 && s>100) ? 20 : s;
    board = new char[size];
    indx = new int[size];

    //Initialize both arrays 
    for (int i=0; i<size; i++) {        
        board[i]=rand()%26+96; // rand() lowercase letters from alphabet            
        indx[i] = i;
    }
    setBoard();
}
void Choices::setBoard(){
    //reinitialize both pointer arrays 
    for(int shuffle=0;shuffle<2;shuffle++){ //randomized values 2xs
    for (int i=0; i<size; i++) {
        board[i] = bChoice[rand()%SIZE17]; // fills with S=ship or B=blank
        indx[i] = i;
    }
    }
}
// Prints game board
void Choices::printBoard() const {

    cout << "\tGame Board.  S==Ship.\n";
    for (int i = 0; i<size; i++) {
        cout << setw(3) << i;
    }
    cout << endl;
    for (int i=0; i<size; i++) {

        cout << setw(3) << board[i];
        //if(i%10==(10-1)) cout<<endl;
    }
    cout << endl << endl;
}