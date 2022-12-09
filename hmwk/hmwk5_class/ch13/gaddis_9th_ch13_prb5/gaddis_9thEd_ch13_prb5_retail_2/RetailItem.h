/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RetailItem.h
 * Author: DanYell
 *
 * Created on November 11, 2022, 2:16 PM
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H

// class definition
class RetailItem {
    private: 
        string name;      // description of item
        int    numUnits; // number of units
        float  price;    // price of item
    public:
        RetailItem(string n="",int u=0,float p=0);   // constructor
        string getName() const {return name;}       // accessor 
        int getUnits() const {return numUnits;}
        float getPrice() const {return price;}
};

#endif /* RETAILITEM_H */

