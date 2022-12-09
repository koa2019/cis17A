/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Essay.h
 * Author: DanYell
 *
 * Created on December 3, 2022, 11:29 PM
 */

#ifndef ESSAY_H
#define ESSAY_H
#include "GradedActivity.h"
using namespace std;  //STD Name-space where Library is compiled


class Essay : public GradedActivity {
    
    private:
        float grammar;
        float spellng;
        float length;
        float content;
        float maxPts;
    public:
        Essay() : GradedActivity(){   //Default constructor
            setEssay(0,0,0,0);
        }
        Essay(float gmmr, float spell, float len, float cntnt) : GradedActivity() 
        { setEssay(gmmr,spell,len,cntnt); }
        
        //Mutators
        void setEssay(float,float,float,float);
        void setGrammr(float g) { grammar=g; }
        void setSpell(float s)  { spellng=s; }
        void setLeng(float l)   { length=l;}
        void setCntnt(float c)  { content=c;}
        void setMaxPts(float m) { maxPts=m; }
        
        // Accessors
        float getGrammr() const{ return grammar; }
        float getSpell() const { return spellng; }
        float getLeng() const  { return length;}
        float getCntnt() const { return content;}
        float getMaxPts() const{ return maxPts; }
        void showEssay() const;
};



#endif /* ESSAY_H */

