/* File:   Player.h
 * Author: DanYell
 * Created on December 16, 2022, 10:37 PM
 * Player Class specifications
*/

#ifndef PLAYER_H
#define PLAYER_H
#include <string>   //string
#include <cstring>  //char [] library
using namespace std;

class Player {     // structure represents a single player
protected:
    int nPlayrs;
    string fNames[7] = {"mom", "bart", "homer", "jillian", "ting", "victor", "cora"};
    //string name;
    char *name;
    bool isRight;   //player's guess is correct or not
    int numWins;    // a player's number of wins
    int shipLoc;    // ship's location on game board
    int brdIndx;    // row index for board[][]
    int brdCol;     // column index for board[][]
    int pSize;
    int rows;       // number of rows in board[][]
    int cols;       // number of cols in board[][]
    char *board; // player's game board  --> replaced static array board1[ROWS][COLS]={};    //look at github how to fill class>randomDyn2DArr
    //char **guessArr; // player's guesses  --> guessP1[ROWS][COLS]={};   
 
public:
    //Default constructor
    Player();
    //Destructor
//    ~Player(){
//        if(size>0){
//            delete [] board;
//        }
//    }
    //Mutators
    void setNumPlayrs(int num){nPlayrs=num;}
    void setName();
    void setIsRight(bool);
    void setNumWins(int);
    void setShipLoc(int);
    void setBrdIndx(int);
    void setBrdCol(int);
    void setRows(int);
    void setCols(int);
    void setPlayer();
    bool play(int a, int b, int &round);
    //bool play(Score *score,int a, int b, int &round);
    
    //Accessors
    int getNumPlayrs() const{return nPlayrs;}
    string getName() const {return name;}
    int getIsRight(bool) const {return isRight;}
    int getNumWins(int) const {return numWins;}
    int getShipLoc(int) const {return shipLoc;}
    int getBrdIndx(int)const {return brdIndx;}
    int getBrdCol(int) const {return brdCol;}
    int getRows(int) const {return rows;}
    int getCols(int) const {return cols;}
};


#endif /* PLAYER_H */

