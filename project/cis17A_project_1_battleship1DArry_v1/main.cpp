/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created: 10-26-2022 @ 6 PM
 * Purpose: CIS 17A Project 1. Covers chapters 9-12 in Gaddis. Battleship v1
 * Version 1: 
 *          changed P1 & P2 strings to pointers.
 *          created Player structure and set number of wins as a structure member
 * 
 */

// System Libraries: 
#include <iostream> // cin, cout
#include <iomanip>  // fixed, setprecision()
#include <cmath>    // round()
#include <cstdlib>  // rand()
#include <fstream>  // ofstream 
#include <cstring>  // char [] library
#include <string>   // string library
#include <ctime>    // time library for rand()

using namespace std;

// User libraries
struct Player{
    int numWins;
};
struct Scores{
    int ttlRnds;
    Player *player;
};
// Global Constants
// Physics/Chemistry/Math/Conversions

// Function prototypes

// Program execution begins here

int main(int argc, char** argv) {

    // set random number seed
    srand(static_cast<unsigned int> (time(0)));

    // declare variables
    ifstream     inFile; // for reading an existing file
    ofstream     outFile; // for outputting to a file

    const int    MIN = 1, // minimum number for rand()
                 MAX = 14, // maximum number for rand()
                 SIZE7=7;
   
    bool         p1_crrt, // player 1 correct
                 p2_crrt; // player 2 correct
    char         ans; // answer  
    int          maxGmes = 0, // number of games
                 nGmsLft,     // number of games left       
                 round = 1, // round
                 p1Guess, // player 1 guess
                 p2Guess, // player 2 guess
                 p1Ship1, // player 1 ship number 1
                 p2Ship1, // player 2 ship number 1
                 p1Win = 0, // counter for player 1 wins
                 p2Win = 0, // counter for player 2 wins
                 ttlGmes = 0,   // sum of both players number of wins
                 ttlRnds = 0;   // sum of total rounds played
    float        avg1, // average number of wins for player 1
                 avg2, // average number of wins for player 2
                 avgRnds;   // average rounds it takes to win
    int nPlayrs=2;
    string p2Names[SIZE7]={"MOM", "BART", "JANIS", "STEPHANIE", "TING", "VICTOR", "JILLIAN"};   
    string *namePtr=nullptr;
    namePtr=p2Names;
    
    //
    Player *player = new Player[nPlayrs];
    
    
    // open an existing file that holds max number of games a user can play
    inFile.open("maxNGms.txt");

    // create a file to output to
    outFile.open("scores.txt");
    
    // read in maximum number of games that can be played from file
    inFile >> maxGmes;
    nGmsLft = maxGmes;  // set numberOfGamesLeft to equal maxGames
    
    do { // game starts here
        
        // initial variables to represent the location of each player's ship
        p1Ship1 = rand()%(MAX-MIN)+MIN;
        p2Ship1 = rand()%(MAX-MIN)+MIN;

        // sets variables to default starting values
        p1_crrt = p2_crrt = false;

        // display 3 line game banner
        for(int i=0;i<=2;i++){
            switch(i){  // print a border or string depending on i
                case 0:
                case 2:
                {
                    for (int j=0; j<32; j++) {
                        cout << "*";
                    }
                    cout << endl;
                    break;
                }
                case 1:
                {
                    cout << setw(21) << "BATTLESHIP" << endl;
                    break;
                }
                default: cout << "Error in game banner.\n";
            }
        }

        // display games introduction message
        cout << setw(2) << " " << "Try to guess the location of \n"
             << setw(6) << " " << "the computer\'s ship." << endl;
        
        // loops until a player correctly guesses opponents ship location
        while((!p1_crrt) && (!p2_crrt)){

            cout << endl << setw(26) << "********************" << endl;
            cout << setw(18) << "Round " << round << endl;
            cout << setw(26) << "********************" << endl;

            //*************** Player 1's Guess ************* 
            //**********************************************
            // display instructions to player 1
            cout << endl << setw(21) << *(namePtr+1) << "\nGuess a number between 1 and " << MAX << endl;
            
            // program generates random number guess
            p1Guess = rand()%(MAX-MIN)+MIN;

            // checks if player1 guess is correct
            if(p1Guess == p2Ship1){

                // increment player 1 number of wins
                p1Win++;
                player[0].numWins = p1Win;
                nGmsLft--;  // decrease number of total games

                // reassign player 1's value for a correct guess
                p1_crrt = true;                             

                // display HIT message for correct guess
                cout << setw(13) << p1Guess << " == " << p2Ship1 << endl;
                cout << setw(23) << "IT\'S A HIT!\n" << endl;
              
            } else {  // if player1 guess is wrong 
                
                // display MISS message for wrong guess
                cout << p1Guess << endl;
                cout << setw(23) << "IT\'S A MISS!\n";
            }

            // conditional only runs if player 1 misses player 2's ship
            if(!p1_crrt){

                //*************** Player 2's Guess *************
                //**********************************************
                // display instructions to player 2
                cout << endl << setw(21) << *(namePtr+0) << "\nGuess a number between 1 and " << MAX << endl;

                // program automatically generates a guess for player 2
                p2Guess = rand()%(MAX-MIN)+MIN;

                // conditional checks if guess is correct
                if(p2Guess == p1Ship1){

                    // increment player 2 number of wins
                    p2Win++;
                    player[1].numWins = p2Win; 
                    nGmsLft--;  // decrease number of total games
                    
                    // reassign player 2's value for a correct guess
                    p2_crrt = true;

                    // display HIT message for correct guess                  
                    cout << setw(13) << p2Guess << " == " << p1Ship1 << endl;
                    cout << setw(23) << "IT\'S A HIT!\n" << endl;
                   
                } else { // display message for wrong guess                    
                    cout << p2Guess << endl;
                    cout << setw(23) << "IT\'S A MISS!\n";
                }
            }

            round++;
            // if both players guess wrong, then increment round by 1
            // and display message to tell them to continue guessing 
            if((!p1_crrt) && (!p2_crrt)){
                cout << endl << "You Both Missed. Try Again...\n\n";
            }
        }// ends while()

        // Display scoreboard banner       
        cout << "********************************\n" << setw(21) << "SCOREBOARD\n";  
                   
        
        cout << setw(4) << " " << *(namePtr+1) << setw(4) << "vs" << setw(3) << " " 
             << right << *(namePtr+0)<< endl;
        cout << setw(8) << player[0].numWins << setw(16) << player[1].numWins << endl;

        // calculate total number of games won & number rounds played
        ttlGmes = player[0].numWins + player[1].numWins;
        ttlRnds += round; // sums the total number of rounds from all games

        // calculates each players percentage of winning
        avg1 = player[0].numWins/static_cast<float>(ttlGmes)*100;
        avg2 = player[1].numWins/static_cast<float>(ttlGmes)*100;
        avgRnds = static_cast<float>(ttlRnds)/ttlGmes;
        
        // checks maximum number of games has NOT been played
        if(ttlGmes<maxGmes){

            cout << "\nTotal # Games Played = " << ttlGmes << endl;
            cout << nGmsLft << " of " << maxGmes << " max games left.\n";
            cout << "Play again? ";
            cin >> ans;

            // conditional validates user's input
            if(ans=='y'){                
                round = 1;
                cout << endl << endl;
            } else if(ans=='Y'){                
                round = 1;
                cout << endl << endl;
            } else {
                cout << "\nThanks for playing!\n";               
                cout << fixed << showpoint << setprecision(2); 
                cout << "\nAverages for " << ttlGmes << " games \n"
                     << "Total # of rounds played: " << ttlRnds << endl
                     << "Player 1 won ceil(" << avg1 << ")% = " 
                     << ceil(avg1) << endl
                     << "Player 2 won ceil(" << avg2 << ")% = " 
                     << ceil(avg2) << endl;
                cout << "Avg # of rounds to win: ceil(" << avgRnds << ") = "
                     << ceil(avgRnds) << endl;
            }           
        } else { // display end of game results
           
            cout << "Max number of games has been reached." << endl;
            cout << fixed << showpoint << setprecision(2);           
            cout << "\nAverages for " << ttlGmes << " games \n"
                 << "Total # of rounds played: " << ttlRnds << endl
                 << "Player 1 won ceil(" << avg1 << ")% = " 
                 << ceil(avg1) << endl
                 << "Player 2 won ceil(" << avg2 << ")% = " 
                 << ceil(avg2) << endl;
            cout << "Avg # of rounds to win: ceil(" << avgRnds << ") = "
                 << ceil(avgRnds) << endl;      

            // reassign ans so it will end the do..while()
            ans = 'n';
        }        
        
      // continue doing all the statements above until 
      // ans does not equal y or Y
    } while((ans=='y')||(ans=='Y'));   

    // write scores and averages to file
    outFile << fixed << showpoint << setprecision(2);
    outFile << "Player 1 wins: " << player[0].numWins  << endl
            << "Player 2 wins: " << player[1].numWins << endl
            << ttlGmes << " of " << maxGmes << " max games were played.\n"    
            << "Total # of rounds played: " << ttlRnds << endl 
            << "\nAverages for " << ttlGmes << " games" << endl
            << "Player 1 won ceil(" << avg1 << ")% = " 
            << ceil(avg1) << endl
            << "Player 2 won ceil(" << avg2 << ")% = " 
            << ceil(avg2) << endl
            << "Avg # of rounds to win: ceil(" << avgRnds << ") = "
            << ceil(avgRnds) << endl; 
        
    // close file being read in
    inFile.close();

    // close scores.txt file
    outFile.close();

    //de-allocate dynamic memory
    namePtr=nullptr;
    // exit code
    return 0;
}