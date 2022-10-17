/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: DanYell
 *
 * Created on September 27, 2022, 7:08 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
    float cnvtNum;
    int   num,  //starting number
            divNum,
            stBase,   // starting base
            base;   // base that the number should be converted to
    
    num=39;
    stBase=10;
    base=16;
    
    if(stBase==10){
        
        cnvtNum = num % base;
        cout << "Converted Num = " << cnvtNum << endl;
        
        divNum = (num/base);
        num = divNum%base;
        cout << "int(num/base) = " << divNum 
            << "    divNum%base = " << num << endl;
        
        
        
    }
    return 0;
}

