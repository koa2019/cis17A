/* 
 * File:   Choices.h
 * Author: Danielle 
 * Created: 12-07-2022 @ 7:18 PM
 */

#ifndef CHOICES_H
#define CHOICES_H
// System Libraries: 
//#include <iostream> // cin, cout
//#include <iomanip>  // fixed, setprecision()
//#include <cmath>    // round()
//#include <cstdlib>  // rand()
#include <fstream>  // fstream 
//#include <cstring>  // char [] library
//#include <string>   // length() library
//#include <ctime>    // time library for rand()
//#include <cctype>   // toupper()
using namespace std;


class Choices {
private: 
    int s20 = 20;
    int SIZE17 = 17;
    int  size;
    char *board; // pointer to char array
    int  *indx;//Index used in sorting the array
    char bChoice[18] = "S-Ss-Ss--S-S--Ss-"; // S=ship  B=blank
    
public:
    //Default constructor
    Choices();
    
    //Constructor #2
    Choices(int s);
    
    //Destructor
    ~Choices(){
        if(size>0) { 
            delete [] board;
        }
    }

    // Accessor function
    void getBoard() const;
    void wrtTxt1(fstream&,Choices *,int);     //write Choices object to text file
};

#endif /* CHOICES_H */

