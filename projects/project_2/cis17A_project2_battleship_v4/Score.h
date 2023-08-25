/* File:   Score.h
 * Author: DanYell
 *
 * Created on December 16, 2022, 10:41 PM
 */

#ifndef SCORE_H
#define SCORE_H
#include <iostream>
//#include <string> //string
using namespace std;
#include "Player.h"

class Score: public Player {

protected:   
    int maxGmes;
    int ttlGmes;
    int ttlRnds;    
   
public:
    //Exception class
    class NegativeGames {};  //empty class declaration 
    const int SIZE17 = 17; //size of choices array 
    Score() : Player(){  //Default constructor
        //cout<<"Hit Score() Constructor\n";  
        Player **player = new Player*[getNumPlayrs()];
        
        // loop through number of players when player's is an array
        for (int i=0; i<getNumPlayrs(); i++) {
            player[i] = new Player(); //creating each individual player by calling Player constructor
            //indx[i]=i;
        }
        maxGmes=3;
        ttlGmes=0;
        ttlRnds=0;
    }
    ~Score(){
        for (int i=0; i<getNumPlayrs(); i++) {
            //delete player[i];
        }
        //delete [] player;
    }
    //Mutators    
    void setMaxGmes(int num){maxGmes=num;}
    void setTtlGmes(int);
    void setTtlRnds(int num){ttlRnds+=num;}
    void setScore(int nPly,int gmes,int tGmes,int tRnds){        
        setMaxGmes(gmes);
        setTtlGmes(tGmes);
        setTtlRnds(tRnds);                
    }
    
    //Accessors   
    int getMaxGmes()const{return maxGmes;}
    int getTtlGmes()const{return ttlGmes;}
    int getTtlRnds()const{return ttlRnds;}
    void prntScore()const;    // prints Score structure 
    void getBanner(string);    // print banner
    void hitMiss(int &guess, char &i, bool isHit);     // print message after each player guesses
    //Score *fillScore(string [],char **);    // fill Score structure by playing game  
    //void setBoard(Score *score,char **ptr2D);   // sets 2D pointer with Score structure   
};


#endif /* SCORE_H */

