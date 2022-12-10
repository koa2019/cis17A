/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prb2Sort.h
 * Author: DanYell
 *
 * Created on December 8, 2022, 7:34 PM
 */

#ifndef PRB2SORT_H
#define PRB2SORT_H
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled


//This class sorts arrays either ascending or descending
//template<class T>
class Prb2Sort {
    
private:
    int *index; //Index that is utilized in the sort
    
public:

    //Constructor
    Prb2Sort() {
        index = NULL;
    };

    //Destructor
    ~Prb2Sort() { 
        delete []index;
    };
    char *sortArray(const char*, int, bool); //Sorts a single column array
    char *sortArray(const char*, int, int, int, bool); //Sorts a 2D array that's represented as a 1D array
};


#endif /* PRB2SORT_H */

