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
    cout << str << endl;    
}


//convert number into words
string Number::num2Wrd() {

    string str = " ", s1, s2, s3, s4 = "";
    //int temp = num; //mod% doesn't work on floats

    int n1000 = num / 1000;
    //cout << "n1000= " << n1000 << endl;   

    switch (n1000) {
        case 10: s1 = "Ten Thousand";   break;
        case 9: s1 = "Nine Thousand ";  break;
        case 8: s1 = "Eight Thousand "; break;
        case 7: s1 = "Seven Thousand "; break;
        case 6: s1 = "Six Thousand ";   break;
        case 5: s1 = "Five Thousand ";  break;
        case 4: s1 = "Four Thousand ";  break;
        case 3: s1 = "Three Thousand "; break;
        case 2: s1 = "Two Thousand ";   break;
        case 1: s1 = "One Thousand ";   break;
        default: s1 = "";
    }
    
    int n100 = num % 1000 / 100;
    //cout << "n100= " << n100 << endl;

    s2 = n100 == 9 ? "Nine Hundred" :
            n100 == 8 ? "Eight Hundred " :
            n100 == 7 ? "Seven Hundred " :
            n100 == 6 ? "Six Hundred " :
            n100 == 5 ? "Five Hundred " :
            n100 == 4 ? "Four Hundred " :
            n100 == 3 ? "Three Hundred " :
            n100 == 2 ? "Two Hundred " :
            n100 == 1 ? "One Hundred " : "";

    int n10 = (num % 100);
    //cout << "n10= " << n10 << endl;

    int n1 = num % 10;
    //cout << "n1= " << n1 << endl;

    if (n10 >= 20 && n10 <= 90) {
        //cout << "n10-n1= " << n10 - n1 << endl;
        switch (n10 - n1) {
            case 90: s3 = "Ninety ";  break;
            case 80: s3 = "Eighty ";  break;
            case 70: s3 = "Seventy "; break;
            case 60: s3 = "Sixty ";   break;
            case 50: s3 = "Fifty ";   break;
            case 40: s3 = "Forty ";   break;
            case 30: s3 = "Thirty ";  break;
            case 20: s3 = "Twenty ";  break;
            default: s3 = "";
        }

        //only print one's if n10 is not a teen number
        s4 =    n1 == 9 ? "Nine " :
                n1 == 8 ? "Eight " :
                n1 == 7 ? "Seven " :
                n1 == 6 ? "Six " :
                n1 == 5 ? "Five " :
                n1 == 4 ? "Four " :
                n1 == 3 ? "Three " :
                n1 == 2 ? "Two " :
                n1 == 1 ? "One " : "";

    } else {
        s3 = n10 == 19 ? "Nineteen" :
                n10 == 18 ? "Eighteen" :
                n10 == 17 ? "Seventeen" :
                n10 == 16 ? "Sixteen" :
                n10 == 15 ? "Fifteen" :
                n10 == 14 ? "Fourteen" :
                n10 == 13 ? "Thirteen" :
                n10 == 12 ? "Twelve" :
                n10 == 11 ? "Eleven" :
                n10 == 10 ? "Ten " : "";
    }

    str = s1 + s2 + s3 + s4;

    return str;
}
