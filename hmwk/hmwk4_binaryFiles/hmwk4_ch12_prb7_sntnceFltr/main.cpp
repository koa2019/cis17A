/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on October 15, 2022, 11:25 PM
 * gaddis-9thEd-ch12-prb7_sentFilter v2
 */
#include <iostream>
#include <cstdlib>
#include <cstring>  //char[] functions
#include <string>   //string
#include <fstream>  //files
#include <cctype>   //tolower()
using namespace std;

int main(int argc, char** argv) {

    fstream inFile,
            outFile;
    string  file1,
            file2;


    cout << "Enter file you'd like to read data from include its file extension .txt\n";
    //cin >> file1;
    file1 = "readme.txt";
    cout << file1 << endl;
    inFile.open(file1, ios::in);

    cout << "Enter file you'd like to write data to. Include its file extension. out.txt\n";
    cin >> file2;
    cin.ignore();

    //file2 = "out.txt";
    outFile.open(file2,ios::out);

    //reads in each word from file and saves it as a string in string array
    char ch;

    while (!inFile.eof()) {

        inFile.get(ch); //read a char from input file

        outFile.put(toupper(ch));//change to uppercase & write to outFile

        inFile.get(ch);//read next char from input file

        //check if char is a period
        while (ch != '.') { //while char is NOT a period

            outFile.put(tolower(ch));//change to lowercase & write to outFile
            inFile.get(ch);//read next char from input file
        }
        
        inFile.get(ch);//read next char from input file

        //go to next line of output file
        outFile << "."<< endl;           

    } 

    //close files
    inFile.close();
    outFile.close();

    return 0;
}