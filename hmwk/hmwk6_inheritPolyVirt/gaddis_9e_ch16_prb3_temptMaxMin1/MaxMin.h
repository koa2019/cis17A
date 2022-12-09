/* 
 * File:   MaxMin.h
 * Author: DanYell
 *
 * Created on December 6, 2022, 2:42 PM
 */

#ifndef MAXMIN_H
#define MAXMIN_H

template <class T> 
T setMin(T a, T b)
{
    T min = (a<=b) ? a : b;
    return min;
}
template <class T> 
T setMax(T a, T b){
    
    T max = (a>=b) ? a : b;    
    return max;
}

#endif /* MAXMIN_H */

