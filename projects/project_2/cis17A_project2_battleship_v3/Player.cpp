#include "Player.h"
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


//************************************************************
//    Default constructor
//************************************************************
Player::Player(){
  
    nPlayrs=2;
    setName();
    //name=fNames[rand()%6];
    isRight=false;
    numWins=0;
    guess=0;
    brdIndx=0;
    brdCol=0;
    brdSize=20;
    rows=0;
    cols=0;
//    board = new char[20];
//    for(int i=0;i<brdSize;i++){
//        *(board+i)='0';
//    }
}

//****************************************************************
//      sets 1 player's name randomly.
//      converts string to char array
//****************************************************************
void Player::setName(){
   
    int indx1, // index for player 1's name
        indx2; // index for player 2's name
    
    // create new pointer to Score structure
    //Score *score = new Score;

    // create a pointer to Player's structure and create array size of 2
    //score->player = new Player[score->nPlayrs];

    // loop through number of players when player's is an array
    //for (int i=0; i<nPlayrs; i++) {

        // generate new random name for each player
        //if (i==0) {
            indx1 = rand()%6;           
            
//        } else { //makes sure the same 2 names are NOT picked from the names array
//
//            do {
//                indx2 = rand()%6; 
//                
//            } while (indx2 = indx1);
//
//            indx1 = indx2; //? resets something
//        }

        // set player name by creating new char[] the size of string +1
        //player[i].name = new char[fNames[indx1].length() + 1];
        name = new char[fNames[indx1].length() + 1];
        
        // loop through the length of name string
        for (int c=0;c<(fNames[indx1].length()+1); c++) {

            // convert string to c-string and to uppercase. static_cast as char           
            //score->player[i].name[c] = (char) toupper(fNames[indx1].c_str()[c]);           
            name[c] = (char) toupper(fNames[indx1].c_str()[c]);           
        }     
    //}
}

//****************************************************************
// increment player 1 number of wins      
// set structure's member value for player    
//****************************************************************
void Player::setWinner(){             
             
}


//****************************************************************
//          Randomly sets a player's guess to number between [0,19]
//****************************************************************
void Player::setGuess(int guesIndx){      
    guess = guesIndx;
}


//****************************************************************
//           calls Choices Accessor function
//****************************************************************
void Player::printGBoard() const{
    gboard.printBoard();
}



