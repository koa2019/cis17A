/* 
 * File:   MilTime.h
 * Author:  Danielle Fernandez
 * Created: 12-06-2022 @ 11:24 PM
 */


// MilTime is derived class. Time class is the base classes
#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"
using namespace std; //STD Name-space where Library is compiled


class MilTime : public Time {
    private:
        const int MIN = 0;
        const int MAXHR = 2359;
        const int MAXSEC = 59;
        int milHrs;
        int milSecs;  
        
    public:        
        //Exception classes
        class BadHr{};
        class BadSec{};
        
        //Default constructor
        MilTime() : Time() 
            { milHrs=0; milSecs=0; }
        
        //Constructor #2     
        MilTime(int mTime,int mSec) : Time() 
        {   setMilTime(mTime,mSec);
            setStandTime();
        }
        
        // Mutator functions
        void setMilTime(int mTime,int mSec);
        void setStandTime();      //access Time class members
        void setMilHrs(int mTime);
        void setMilSecs(int mSec);        
        
        //Accessor functions
        int getMilHrs() const {return milHrs;}
        int getMilSecs() const {return milSecs;}
        void showMilTime() const;
        void showStandTime() const; //access Time class member functions
            
};


#endif /* MILTIME_H */

