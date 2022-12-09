/* 
 * File:   MilTime.h
 * Author: DanYell
 *
 * Created on December 3, 2022, 4:06 PM
 */
#include "Time.h"

// MilTime is derived class. Time class is the base classes
#ifndef MILTIME_H
#define MILTIME_H

class MilTime : public Time {
    private:
        int milHrs;
        int milSecs;       
    public:
        MilTime() : Time(){  //Default constructor
            setMilTime(0,0);
        }
        MilTime(int mTime,int mSec) : Time()  //Constructor #2            
            { setMilTime(mTime,mSec); }
        
        // Mutator functions
        void setMilTime(int mTime,int mSec);
        void setMilHrs(int mTime) { milHrs = mTime; }
        void setMilSecs(int mSec){ milSecs = mSec; }
        
        //Accessor functions
        int getMilHrs() const {return milHrs;}
        int getMilSecs() const {return milSecs;}
        void showMilTime() const;
        void showStandTime() const; //access Time functions
            
};


#endif /* MILTIME_H */

