/* File:   Choices.h
 * Author: DanYell
 * Created on December 16, 2022, 10:15 PM
*/

#ifndef CHOICES_H
#define CHOICES_H
using namespace std;  //STD Name-space where Library is compiled

class Choices {
private:
    int size;
    char *board; // pointer to char array
    int *indx; //Index used in sorting the array
    char bChoice[18] = "S-Ss-Ss--S-S--Ss-"; // S=ship  B=blank

public:
    const int SIZE17 = 17; // # of characters in choices array   

    //Default constructor
    Choices();

    //Constructor #2
    Choices(int s);

    //Destructor
    ~Choices() {
        if (size > 0) {
            delete [] board;
            delete [] indx;
        }
    }
    
    //Mutator function
    void setBoard();
    
    // Accessor function
    const char get1BrdElmnt(int i)const {return board[i];}
    const char *getBoard() const {return board;}
    const int *getIndx() const {return indx;}
    void printBoard() const;
        
};
#endif /* CHOICES_H */

