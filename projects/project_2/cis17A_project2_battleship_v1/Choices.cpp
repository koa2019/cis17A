#include "Choices.h"
// System Libraries: 
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cmath>    // round()
#include <cstdlib>  // rand()
#include <fstream>  // fstream 
#include <cstring>  // char [] library
#include <string>   // length() library
#include <ctime>    // time library for rand()
#include <cctype>   // toupper()
using namespace std;


//Default constructor
Choices::Choices() {
    size = s20;
    board = new char[size];
    indx = new int[size];

    //Initialize both arrays 
    for (int i = 0; i < size; i++) {
        board[i] = bChoice[rand() % SIZE17]; // fills with S=ship or B=blank
        //board[i] = rand()%26+65; // rand() letters from alphabet            
        indx[i] = i;
    }

}

//Constructor #2
Choices::Choices(int s) {

    size = (s < 2 && s > 100) ? 20 : s;
    board = new char[size];
    indx = new int[size];

    //Initialize both arrays 
    for (int i = 0; i < size; i++) {
        board[i] = bChoice[rand() % SIZE17]; // fills with S=ship or B=blank
        //board[i]=rand() % 26 + 65; // rand() letters from alphabet            
        indx[i] = i;
    }
}

// Prints game board
void Choices::getBoard() const {

    cout << "\tGame Board.  S==Ship.\n";
    for (int i = 0; i < size; i++) {
        cout << setw(3) << i;
    }
    cout << endl;
    for (int i = 0; i < size; i++) {

        cout << setw(3) << board[i];
        //if(i%10==(10-1)) cout<<endl;
    }
    cout << endl << endl;
}

//write Choices object to text file
void Choices::wrtTxt1(fstream&, Choices *, int){ 
//    int perLine=TEN;
//    
//    outFile << "Record " << setw(2) << right << recInd << " \n";
//    
//    for(int i=0;i<20;i++){
//        
//        //outFile << setw(2) << choice->arr[choice->indx[i]];
//        
//        if(i%perLine==(perLine-1))outFile<<endl;
//    }
//    outFile<<endl;
}
