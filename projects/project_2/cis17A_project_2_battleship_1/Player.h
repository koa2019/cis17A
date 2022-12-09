/* 
 * File:   Player.h
 * Author: Danielle 
 * Created on Dec 07, 2022, 2:15 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
using namespace std;

struct Player {     // structure represents a single player
//class Player {     // structure represents a single player
//private:
    char *name;
    bool isRight;
    int numWins;    // a player's number of wins
    int shipLoc;    // ship's location on game board
    int brdIndx;    // row index for board[][]
    int brdCol;     // column index for board[][]
    int rows;       // number of rows in board[][]
    int cols;       // number of cols in board[][]
    char **board; // player's game board  --> replaced static array board1[ROWS][COLS]={};    //look at github how to fill class>randomDyn2DArr
    //char **guessArr; // player's guesses  --> guessP1[ROWS][COLS]={};   
 
//public:
    
};

#endif /* PLAYER_H */

