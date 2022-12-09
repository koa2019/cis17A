/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Total.h
 * Author: DanYell
 *
 * Created on December 6, 2022, 3:56 PM
 */

#ifndef TOTAL_H
#define TOTAL_H
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

template <class T1>
T1 setTotal(T1 cnt){
     
    T1 ttl=0;
    T1 num=0;    
   
    for(int i=0;i<cnt; i++){
        
        cout << "Enter a number\n";
        cin >> num;
        
        ttl = ttl+num;          
    }
    cout << "Total = ";
    return ttl;
}


template <class T1, class T2>
T2 setTotal(T1 count){
  
    T2 ttl=0;
    T2 num=0;    
   
    for(int i=0;i<count; i++){
        
        cout << "Enter a number\n";
        cin >> num;
        
        ttl = ttl+num;        
    }
    return ttl;
}


template <class T1, class T2>
T2 setTotal(T1 cnt, T2 &ttl){
  
    T2 num=0;    
   
    for(int i=0;i<cnt; i++){
        
        cout << "Enter a number\n";
        cin >> num;
        
        ttl = ttl+num; 
    }
    return ttl;
}



#endif /* TOTAL_H */

