/* 
 * File:   Array.h
 * Author: DanYell
 *
 * Created on November 11, 2022, 8:28 PM
 */

#ifndef ARRAY_H
#define ARRAY_H

class Array {
    private:
        float *arrPtr;  // pointer to array of floats
        int    size;    // size of array
    public:
        Array(int);             // constructor
        void setElements();     // reset all values in array
        void reset1Element();   // reset value of 1 element in array
        void printArr() const;  // print array
        float getElement(int i) {return arrPtr[i];} // print 1 element in array
        float getHigh() const;
        float getLow() const;
        float getAvg() const;
        ~Array();             // de-constructor   
};


#endif /* ARRAY_H */

