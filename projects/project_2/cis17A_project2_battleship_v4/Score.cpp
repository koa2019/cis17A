#include "Score.h"
#include <iostream>   //Input/Output Library
#include <iomanip>  // fixed, setprecision()
#include <cstring>  // char [] library
#include <string>   // length() library
#include <cctype>  //toupper()
using namespace std;

void Score::setTtlGmes(int num){
    if(num>=0) {
        ttlGmes = num;
    }else {
        throw NegativeGames();
    }
}


void Score::prntScore()const{ 

    // Display scoreboard banner  
    string str="SCOREBOARD";
    //getBanner(str);
    
    cout<<"\tMax Games: "<<getMaxGmes()<<endl;
    cout <<"\n         "<< getTtlGmes() << " games left.\n";
    cout << "   Total rounds in this game: " << getTtlRnds() << endl << endl;
    //cout<<"name= "<<player.getName();
//    cout <<" Player 1's Ship Location:   " << score->player[0].shipLoc << endl
//         <<" Player 2's Ship Location:   " << score->player[1].shipLoc << endl << endl;

//    for (int p=0; p< score->player[p].rows; p++) {
//        
//        cout << "         Player "<<p+1<<"'s Game board \n";
//        
//        for (int row = 0; row < score->player[p].rows; row++) {
//            
//            for (int col = 0; col < score->player[p].cols; col++) {             
//           
//                cout<< "&" << score->player[p].board[row][col];
//                if(col%10==9) cout<<endl;
//            }           
//        }
//    }       
    cout << endl << endl;
}
//******************************************************************************
//      Displays game's name and instructions in a banner
//******************************************************************************
void Score::getBanner(string title) {

    cout << "\n********************************\n" << setw(21) << title << endl;
    cout << "********************************\n";
//    cout << setw(10) << setfill(' ') << score->player[0].name
//         << setw(6) << setfill(' ') << right << "vs"
//         << setw(12) << score->player[1].name << endl;

    if (title=="SCOREBOARD") {
//        cout << setw(8) << player[0].numWins
//             << setw(14) << score->player[1].numWins << endl;
    } else {
        cout << setw(2) << " " << "\n   Try to guess the location of \n"
             << setw(6) << " " << "your opponent\'s ship." << endl;
    }
}



//******************************************************************************
//  Display hit message when player guesses correctly
//******************************************************************************
void Score::hitMiss(int &pGuess, char &i, bool isHit) {

    if (isHit) {
        cout << setw(12) << pGuess << " == " << i << endl;
        //cout << setw(12) << pGuess << " == " << score->player[b].shipLoc << endl;
        cout << setw(22) << "It\'s a HIT!\n" << endl;
        
    } else {
        cout << setw(15) << pGuess << endl << setw(22) << "It\'s a MISS!\n";
    }
}





