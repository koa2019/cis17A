/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//User Libraries
#include "Number.h"

//System Libraries
#include <iostream>
//#include <string>
//#include <valarray>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled



// constructor
Number::Number(int n){
    num=n;
}

// print number as digits
void Number::print(){
    cout << num << endl;    
}

// print number as English words
void Number::print(string str){
    cout << num << " == " << str << endl;    
}


//convert number into words
string Number::num2Wrd() {
    
    string str = " ", s1, s2, s3, s4 = "";   

    int n1000 = num / 1000;
    s1 = n1000 > 0 ? lessThan20[n1000] : "";  
    if(!s1.empty()) s1.append(thousand);
          
    
    int n100 = num % 1000 / 100;  
    s2 = n100 > 0 ? lessThan20[n100] : "";   
    if(!s2.empty()) s2.append(hundred);
    
    int n10 = (num % 100);
    int n1 = num % 10; 

    if (n10 >= 20 && n10 <= 90) {
    
        int temp;
        
        switch (n10 - n1) {
            case 90: temp = 7;  break;
            case 80: temp = 6;  break;
            case 70: temp = 5;  break;
            case 60: temp = 4;  break;
            case 50: temp = 3;  break;
            case 40: temp = 2;  break;
            case 30: temp = 1;  break;           
            default: temp = 0;
        }
        s3 = tens[temp];   
        
        //only print one's if n10 is not a teen number
        s4 = n1>0 ? lessThan20[n1] : "";

    } else { s3 = lessThan20[n10]; }

    str = s1 + s2 + s3 + s4;

    return str;
}
