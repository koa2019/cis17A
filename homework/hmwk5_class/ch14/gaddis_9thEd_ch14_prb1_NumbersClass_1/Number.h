/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Number.h
 * Author: DanYell
 *
 * Created on November 22, 2022, 12:47 PM
 */
#include <string>
using namespace std;  //STD Name-space where Library is compiled


#ifndef NUMBER_H
#define NUMBER_H

class Number {
private:
    int num;
    string lessThan20[20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve", "thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    string tens[8]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    string hundred = "hundred";
    string thousand = "thousand";
public:
    Number(int n=0);   // Constructor
    void print();   
    void print(string);
    string num2Wrd();
    
};


#endif /* NUMBER_H */

