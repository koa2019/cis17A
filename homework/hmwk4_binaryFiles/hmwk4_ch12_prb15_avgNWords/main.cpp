/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created: 10-16-22 @10:30PM
 * gaddis-9thEd-ch12-prb15_avgNumWOrds
 */
#include <iostream>
#include <sstream> //isstringstream
#include <cstdlib>
#include <cstring>  //char[] functions
#include <string>   //string
#include <fstream>  //files
#include <cctype>   //tolower()
using namespace std;

//function prototypes
int avgNumWords( const string &);

int main(int argc, char** argv) {

    fstream inFile;
    string  file1;
    string strArr[6]={};
    int nWords=0,
        nSent=0;
        
    file1 = "out.txt";   
    inFile.open(file1.c_str(), ios::in);

    cout <<"This program finds the average number of words\n"
         << "a sentence has that's stored in the out.txt file.\n"
         << "File's content: \n\n";

    //reads in each word from file and saves it as a string in string array
    string sentnce;

    while (getline(inFile,sentnce)){ //read a char from input file
        
        cout << sentnce << endl;
        nSent++;
        
        nWords += avgNumWords(sentnce);

    } 
    cout << "\nTotal sentences = " << nSent << endl
         << "Total words = " << nWords << endl
         << "Average words per sentence = " <<
            nWords/nSent << endl;
   
    //close files
    inFile.close();    

    return 0;
}

int avgNumWords(const string &sent){
    
    istringstream input(sent);
    string temp;
    int count =0;
        while(input >> temp){
            count++;
        }
    return count;
}