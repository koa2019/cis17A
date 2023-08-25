//System Libraries
#include <iostream>   //Input/Output Library
#include "Essay.h" 
using namespace std;  //STD Name-space where Library is compiled


void Essay::setEssay(float g, float s ,float l, float c){
    setGrammr(g);
    setSpell(s);
    setLeng(l);
    setCntnt(c);
    maxPts=100.0f;
    float sc = grammar+spellng+length+content;
    setScore(sc);
}

void Essay::showEssay() const {
    
    cout << "Grammar:         " << getGrammr() << endl
         << "Spelling:        " << getSpell() << endl
         << "Correct Length:  " << getLeng() << endl
         << "Content:         " << getCntnt() << endl
         << "Score:           " << getScore() << endl
         << "Grade:           " << getLetterGrade() << endl;
                    
}