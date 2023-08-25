/* File:    main.cpp
 * Author:  Danielle F
 * Created: 12-16-2022 @ 10:13 PM
 * Purpose:  cis17A_project2_battleship_v2
 * 
 * v2: 
 * Scratched v1 because it was to complicated to convert
 * double pointer structures to inherited classes all at once and
 * not being able to test certain parts to see which section of the 
 * game works and doesn't work.
 *     
 * This version is taking each structure individually and making
 * it a class that's independent of one another. 
 * Converted Choices to class first. Created 2 game board objects, and
 * called them in main().
 * 
 * Converted Score to a class. Created its class member functions,
 * called it main().
 * 
 * Started converting player.h to a class & called it in main().
 * Moved the contents of fillScore() into main() and I'm able to create
 * objects for all 3 classes.
 * Moved play() into Player.h
 * 
 * To do:
 *   *watch ** zoom video again
 *   *Read read about aggregate, polymorphism,virtual()
 *   *Make Player *player point to an array of player pointers
 *    because we need 2 independent players objects
 *   *Have player inherit choices or score inherit player
 * 
 * 
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>  // fixed, setprecision()
#include <cmath>    // round()
#include <cstdlib>  // rand()
#include <fstream>  // fstream 
#include <cstring>  // char [] library
#include <string>   // length() library
#include <ctime>    // time library for rand()
#include <cctype>   // toupper()
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Choices.h"
#include "Score.h"
#include "Player.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
enum nums {
    ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN
};

//Function Prototypes
int *rBanner(int &);            // print round banner
void pause();// pauses game to allow user to view results before proceeding

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int> (time(0)));
    
    //Declare variables here
    const int SIZE17 = 17;  // # of characters in choices array
                   
    bool    p1_crrt,     // player 1 correct
            p2_crrt;    // player 2 correct 
    
    int     MAX=20, // maximum number for rand()       
            indx1,       // index for player 1's name
            indx2,       // index for player 2's name
            maxGmes=3, // number of games
            nGmsLft,      // number of games left       
            round = 0, // round
            numPlay = 2;
    
    // create new instances of Score class 
    Score score; //Score *score = new Score;
    
    
    // create a pointer to Player's structure and create array size of 2
    //score->player = new Player[score->nPlayrs];
    //Player *player = new Player[numPlay];
     Player player;
     
    // loop through number of players when player's is an array
    //for (int i=0; i<nPlayrs; i++) {
    
    //}
   
    Choices p1Board;
    Choices p2Board;
    
    
    // pointer for rounds
    int *rndPtr = nullptr;
   
    // read in maximum number of games that can be played from file
    nGmsLft = score.getMaxGmes(); // set numberOfGamesLeft to equal maxGames
    
    while (nGmsLft>0) {
       
        // initial variables to represent the location of each player's ship
        //player.setShipLoc(rand()%(0+MAX));
        //score->player[0].shipLoc = rand()%(ZERO+MAX); // random number between [1,14]
        //score->player[1].shipLoc = rand()%(ZERO+MAX);
        
        
        // sets variables to default starting values
        p1_crrt = p2_crrt = false;

        // display game's introduction message 
        score.banner("BATTLESHIP");
        //banner(score,"BATTLESHIP");

        // loops until a player correctly guesses opponents ship location
        while ((!p1_crrt) && (!p2_crrt)) {

            // display round number banner
            rndPtr = rBanner(round);

            // Player 1's Guess   
            //p1_crrt = play(score,0,1,round);
            p1_crrt =true;
            
            // conditional only runs if player 1 misses player 2's ship
            // Player 2's Guess 
            if(!p1_crrt) {   
                //p2_crrt = play(score,1,0,round); 
            }

            // if both players guess wrong, then display message 
            if ((!p1_crrt) && (!p2_crrt)) cout << endl << "  You Both Missed. Try Again...\n\n";
            
        } // ends while((!p1_crrt) && (!p2_crrt))
        
        nGmsLft--;
        //score->ttlGams = nGmsLft;
        score.setTtlGmes(nGmsLft);
        //prntScore(score);
         score.prntScore();
         
        // checks maximum number of games has NOT been played
        if(nGmsLft>0) pause();            
           
        // reset variables for next game
        *rndPtr=0;          
        p1_crrt = p2_crrt = false; 
        
    } // ends while(nGmsLft> ZERO)
    
    
    // display game's introduction message
    cout<<"Number of players: "<< player.getNumPlayrs()<<endl;
    cout<<"Player 1: "<<player.getName()<<endl;
    
    score.hitMiss(12,3,false);//(pGuess,i,isHit)   
   
   
    cout<<"\nPlayer 1 board[0]=  "<<p1Board.get1BrdElmnt(0)<<endl;
    cout<<"Player 2 board[19]=  "<<p2Board.get1BrdElmnt(19)<<endl;
    cout<<"\tPlayer 1's Game Board\n";
    p1Board.printBoard();    
    cout<<"\tPlayer 2's Game Board\n";
    p2Board.printBoard();
    
    //de-allocate dynamic memory
//    for (int p = 0; p < score->nPlayrs; p++) {
//        for (int row = 0; row < score->player[p].rows; row++) {
//            delete []score->player[p].board[row]; //Deletes the Data row by row
//        }
//    }
//    //delete []choice->a;
//    delete []score->player;
//    delete score;   
//    score = nullptr;
//    bordPtr = nullptr;
    
    return 0;
}

//******************************************
//      banner displays round number
//******************************************
int *rBanner(int &round) {    
    int *rndPtr = nullptr;
    round += 1;
    rndPtr = &round;
    cout << endl << setw(26) << "********************************" << endl;
    cout << setw(18) << "Round " << *rndPtr << endl;
    cout << setw(26) << "********************************" << endl;
    return rndPtr;
}

//******************************************
// pause screen before game starts
//******************************************
void pause() {
    cout << "\nPress enter to continue. \n\n";   
    cin.get();
}