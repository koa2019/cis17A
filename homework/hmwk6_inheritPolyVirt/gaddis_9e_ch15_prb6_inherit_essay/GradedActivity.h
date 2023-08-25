/* 
 * File:   GradedActivity.h
 * Author:  Danielle Fernandez
 * Created on December 3, 2022, 11:27 PM
 */

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

// GradedActivity class declaration

class GradedActivity {
    
    private:
       float score;   // To hold the numeric score
    public:
       // Default constructor
       GradedActivity()
          { score = 0.0; }

       // Constructor
       GradedActivity(float s)
          { score = s; }

       // Mutator function
       void setScore(float s) 
          { score = s; }

       // Accessor functions
       float getScore() const
          { return score; }

       char getLetterGrade() const;
    };

#endif /* GRADEDACTIVITY_H */

