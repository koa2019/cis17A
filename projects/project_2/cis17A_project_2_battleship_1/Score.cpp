#include "Score.h"
//#include "Player.h"

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

//// play game
//Score *Score::fillScore(string names[],char **bordPtr) {
//
//    int     MAX = TEN*2; // maximum number for rand()          
//                      
//    bool    p1_crrt,     // player 1 correct
//            p2_crrt;    // player 2 correct       
//    int     indx1,       // index for player 1's name
//            indx2,       // index for player 2's name
//            maxGmes = THREE, // number of games
//            nGmsLft,      // number of games left       
//            round = ZERO, // round
//            numPlay = TWO;
//
//    // create new pointer to Score structure
//    Score *score = new Score;
//
//    score->nPlayrs = numPlay;      
//    score->maxGmes = maxGmes;
//    score->ttlGams = ZERO;
//    
//    // create a pointer to Player's structure and create array size of 2
//    score->player = new Player[score->nPlayrs];
//
//    // loop through number of players
//    for (int i = ZERO; i < score->nPlayrs; i++) {
//
//        // generate new random name for each player
//        if (i == ZERO) {
//
//            indx1 = rand()%SEVEN;            
//
//        } else { //makes sure the same 2 names are NOT picked from the names array
//
//            do {
//                indx2 = rand() % SEVEN;
//            } while (indx2 == indx1);
//
//            indx1 = indx2;
//        }
//
//        // creating new char[] the size of string +1
//        score->player[i].name = new char[names[indx1].length() + 1];
//
//        // loop through the length of name string
//        for (int c = ZERO; c < names[indx1].length() + 1; c++) {
//
//            // convert string to c-string and to uppercase. static_cast as char           
//            score->player[i].name[c] = (char) toupper(names[indx1].c_str()[c]);           
//        }
//        
//        // set each player's number of wins to zero
//        score->player[i].numWins = 0;
//    }
//
//   // pointer for rounds
//    int *rndPtr = nullptr;
//
//    // read in maximum number of games that can be played from file
//    nGmsLft = score->maxGmes; // set numberOfGamesLeft to equal maxGames
//    
//    while (nGmsLft>ZERO) {
//       
//        // initial variables to represent the location of each player's ship
//        score->player[0].shipLoc = rand() % (ZERO+MAX); // random number between [1,14]
//        score->player[1].shipLoc = rand() % (ZERO+MAX);
//
//        // sets variables to default starting values
//        p1_crrt = p2_crrt = false;
//
//        // display game's introduction message     
//        banner(score,"BATTLESHIP");
//
//        // loops until a player correctly guesses opponents ship location
//        while ((!p1_crrt) && (!p2_crrt)) {
//
//            // display round number banner
//            rndPtr = rBanner(round);
//
//            // Player 1's Guess   
//            p1_crrt = play(score,0,1,round);
//          
//            // conditional only runs if player 1 misses player 2's ship
//            // Player 2's Guess 
//            if(!p1_crrt) {   
//                p2_crrt = play(score,1,0,round); 
//            }
//
//            // if both players guess wrong, then display message 
//            if ((!p1_crrt) && (!p2_crrt)) cout << endl << "  You Both Missed. Try Again...\n\n";
//            
//        } // ends while((!p1_crrt) && (!p2_crrt))
//        
//        nGmsLft--;
//        score->ttlGams = nGmsLft;
//        prntScore(score);
//        
//        // checks maximum number of games has NOT been played
//        if(nGmsLft>ZERO) pause();            
//           
//        // reset variables for next game
//        *rndPtr = 0;          
//        p1_crrt = p2_crrt = false; 
//        
//    } // ends while(nGmsLft> ZERO)
//    
//    return score;
//}

// returns if player's guess is correct or not
bool Score::play(Score *score,int a, int b, int &round){
   
    int     MAX = 20, // maximum number for rand()          
            SIZE17 = 17; //size of choices array     
    int     maxGmes = 3, // number of games           
            pGuess,      // player 1 guess                          
            numWins,      // counter for player 1 wins
            ttlGmes,    // sum of both players number of wins
            ttlRnds = ZERO; // sum of total rounds played                         
           
            // display instructions 
            cout << endl << setw(12) << " " << score->player[a].name << "\n Guess a number between "<<ZERO<<" and " << MAX-1 << endl;

            // Generates random number guess between [1,14]
            pGuess = rand()%(ZERO+MAX);

            // checks if player guess is correct
            if (pGuess == score->player[b].shipLoc) {
                
                numWins = score->player[a].numWins+1;    // increment player 1 number of wins                
                
                // set structure's member value for player 
                score->player[a].numWins = numWins;                
                score->player[a].isRight = true;                             
     
                // calculate total number of games won & number rounds played
                ttlGmes = score->player[a].numWins + score->player[b].numWins;
                score->ttlGams = ttlGmes;
                score->ttlRnds = ttlRnds + round; // sums the total number of rounds from all games        
                
                // display HIT message for player's correct guess 
                hitMiss(score, pGuess, b, true); // display MISS message for player 2's wrong guess                             
                return true;      
            } 
            
            // if player1 guess is wrong display MISS message 
            score->player[a].isRight = false;           
            hitMiss(score, pGuess,b, false);                           
            return false;                
}


//void Score::prntScore(Score *score) { 
//
//    // Display scoreboard banner  
//    banner(score, "SCOREBOARD");
// 
//    cout <<"\n         "<< score->ttlGams << " games left.\n";
//    cout << "   Total rounds in this game: " << score->ttlRnds << endl << endl;
//
//    cout << " Player 1's Ship Location:   " << score->player[0].shipLoc << endl
//            << " Player 2's Ship Location:   " << score->player[1].shipLoc << endl << endl;
//
//    for (int p=ZERO; p < score->player[p].rows; p++) {
//        
//        cout << "         Player "<<p+1<<"'s Game board \n";
//        
//        for (int row = 0; row < score->player[p].rows; row++) {
//            
//            for (int col = 0; col < score->player[p].cols; col++) {             
//           
//                cout<< "&" << score->player[p].board[row][col];
//                if(col%TEN==NINE) cout<<endl;
//            }           
//        }
//    }       
//    cout << endl << endl;
//}


//// displays game's name and instructions in a banner
//void Score::banner(Score *score, string title) {
//
//    cout << "********************************\n" << setw(21) << title << endl;
//    cout << "********************************\n";
//    cout << setw(10) << setfill(' ') << score->player[0].name
//         << setw(6) << setfill(' ') << right << "vs"
//         << setw(12) << score->player[1].name << endl;
//
//    if (title == "SCOREBOARD") {
//        cout << setw(8) << score->player[0].numWins
//             << setw(14) << score->player[1].numWins << endl;
//    } else {
//        cout << setw(2) << " " << "\n   Try to guess the location of \n"
//             << setw(6) << " " << "your opponent\'s ship." << endl;
//    }
//}

//// display hit message when player guesses correctly
//void hitMiss(Score *score, int pGuess, int b, bool isHit) {
//
//    if (isHit) {
//        cout << setw(12) << pGuess << " == " << score->player[b].shipLoc << endl;
//        cout << setw(22) << "It\'s a HIT!\n" << endl;
//    } else {
//        cout << setw(15) << pGuess << endl << setw(22) << "It\'s a MISS!\n";
//    }
//}