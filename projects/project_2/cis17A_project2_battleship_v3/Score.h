/* File:   Score.h
 * Author: DanYell
 *
 * Created on December 16, 2022, 10:41 PM
 */

#ifndef SCORE_H
#define SCORE_H
#include <string> //string
using namespace std;

//class Score: public Player {
class Score {
private:
   
    int maxGmes;
    int ttlGmes;
    int ttlRnds;
    //Player *player;
    //Choices *choices;
public:
    const int SIZE17 = 17; //size of choices array 
    Score(){  //Default constructor  
       
        maxGmes=3;
        ttlGmes=0;
        ttlRnds=0;
    }
    
    //Mutators    
    void setMaxGmes(int num){maxGmes=num;}
    void setTtlGmes(int num){ttlGmes=num;}
    void setTtlRnds(int num){ttlRnds=num;}
    void setScore(int nPly,int gmes,int tGmes,int tRnds){        
        setMaxGmes(gmes);
        setTtlGmes(tGmes);
        setTtlRnds(tRnds);                
    }
    
    //Accessors   
    int getMaxGmes()const{return maxGmes;}
    int getTtlGmes()const{return ttlGmes;}
    int getTtlRnds()const{return ttlRnds;}
    void prntScore() const;    // prints Score structure 
    //Score *fillScore(string [],char **);    // fill Score structure by playing game
    //bool play(Score *,int,int,int &);       // run's each player's guess
    //void setBoard(Score *score,char **ptr2D);   // sets 2D pointer with Score structure
                     
    void banner(string);    // print banner
    void hitMiss(int guess=0, char i='-', bool isHit=true);     // print message after each player guesses

};


#endif /* SCORE_H */

