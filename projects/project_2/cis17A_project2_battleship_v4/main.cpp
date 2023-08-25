/* File:    main.cpp
 * Author:  Danielle F
 * Created: 12-16-2022 @ 10:13 PM
 * Purpose:  cis17A_project2_battleship_v4
 * 
 * v4: 
 Added a try/catch to Score.cpp in setTtlGmes().
 Created an array of objects utilizing the Score class.
 Score inherits Player class.
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
//#include "Choices.h"
#include "Score.h"
//#include "Player.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
enum nums {
    ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN
};

//Function Prototypes
bool play(Score *,Player **,int,int,int &);  //returns if player's guess was correct or not
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
   
    //Array of objects
    cout<<"Array of objects\n";
    Score topScores[3]{Score(),Score(),Score()};
    for(int i=0;i<3;i++){
        cout<<topScores[i].getName()<<endl;
    }
    
    // create new instances of Score class 
    Score score; 
    //Score *score = new Score;
    
    
    // create a pointer to Player's structure and create array size of 2
    //score->player = new Player[score->nPlayrs];
    //Player *player = new Player[numPlay]; 
    Player **player;     
    
    player = new Player*[numPlay];
    
    int *indx = new int[numPlay];
    
    // loop through number of players when player's is an array
    for (int i=0; i<numPlay; i++) {
        player[i] = new Player(); //creating each individual player by calling Player constructor
        indx[i]=i;
    }
  
    // pointer for rounds
    int *rndPtr = nullptr;
   
    // read in maximum number of games that can be played from file
    nGmsLft = score.getMaxGmes(); // set numberOfGamesLeft to equal maxGames
    
    while (nGmsLft>0) {
       
        // sets variables to default starting values
        p1_crrt = p2_crrt = false;

        // display game's introduction message 
        score.getBanner("BATTLESHIP");        
        cout<<"\n\t"<<player[indx[0]]->getName()<<" vs "<<player[indx[1]]->getName()<<endl;
        
        // loops until a player correctly guesses opponents ship location
        while ((!p1_crrt) && (!p2_crrt)) {

            // display round number banner
            rndPtr = rBanner(round);

            // Player 1's Guess                       
            p1_crrt = play(&score,player,indx[0],indx[1],round);
            
            if(!p1_crrt){ 
                // Player 2's Guess  
                p2_crrt = play(&score,player,indx[1],indx[0],round);                            
            }

            // if both players guess wrong, then display message 
            if ((!p1_crrt) && (!p2_crrt)) {
                cout << endl << "  You Both Missed. Try Again...\n\n";
            }
            
        } // ends while((!p1_crrt) && (!p2_crrt))
        
        nGmsLft--;
        
        try {           
            score.setTtlGmes(nGmsLft);
            
        } catch(Score::NegativeGames){
            cout<<"Error. Negative games.\n";
        }
        
        score.prntScore();
         
        // checks maximum number of games has NOT been played
        if(nGmsLft>0) {pause();}          
           
        // reset variables for next game
        *rndPtr=0;          
        p1_crrt = p2_crrt = false; 
        
    } // ends while(nGmsLft> ZERO)
    
   
    cout<<"\n\n\tPlayer 1's Game Board\n";
    player[indx[0]]->printGBoard();       
    cout<<"\tPlayer 2's Game Board\n";
    player[indx[1]]->printGBoard();
    
  
    //de-allocate dynamic memory
    for (int p=0; p<numPlay; p++) {       
        delete player[p]; //Deletes the Data row by row
    } 
    delete [] player;
    delete [] indx;    
    player=nullptr;
    indx=nullptr;
    //delete score;   
    //score = nullptr;
    
    return 0;
}


//****************************************************************
//     Returns if player's guess is correct or not     
//****************************************************************

//bool play(Score *score,int a, int b, int &round){
bool play(Score *score, Player **player,int a,int b, int &round){
   
    cout<<setw(12)<<" \n\n"<<"Guess a number between 0-19\n\n";
           
    int num = rand()%19;
    
    player[a]->setGuess(num);
    
    int guessIndx = player[a]->getGuess(); 
    
    char oppntPos = player[b]->get1gBrdElmnt(guessIndx);
    
    //cout<<player[a]->getName()<<" guesses "<< guessIndx<<"\n";   
    //cout<<player[b]->getName()<<"   ["<<guessIndx<<"] "<<oppntPos<<endl<<endl;

    // checks if player guess is correct
    //if (pGuess == score->player[b].shipLoc) {
    if(oppntPos=='S' || oppntPos=='s') { 
        player[a]->setWins();                             
        player[a]->setIsRight(true);
        score->setTtlRnds(round); // sums the total number of rounds from all games        
        score->hitMiss(guessIndx,oppntPos,true);//(pGuess,i,isHit) 
        return true;      
    } 
    else{
        // if player guess is wrong display MISS message 
        player[a]->setIsRight(false);   
        score->hitMiss(guessIndx,oppntPos,false);//(pGuess,i,isHit)    
        return false;    
    }                
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