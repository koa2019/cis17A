/* 
 * File:    main.cpp
 * Author:  Danielle Fernandez
 * Created: 11-11-2022 @ 2:36 PM
 * Purpose:  Gaddis_9thEd_ch13_prb6_inventoryClass_1
 */

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
    private:
        int itemNum;
        int quant;      // quantity of an item
        float cost;     // cost of item
        float ttlCost;   // total inventory cost for the item (quantity times cost) 
    public:
        Inventory();    // default constructor
        Inventory(int,int,float,float t=0); // constructor #2
        void setItemNum(int);  // mutators
        void setQuant(int);    // mutators
        void setCost(float);     // mutators
        void setTtlCost();  // mutators
        int getItemNum() const {return itemNum;}   // accessors
        int getQuant() const {return quant;}     // accessors
        float getCost() const {return cost;}    // accessors
        float getTtlCost() const {return ttlCost;} // accessors        
};

#endif /* INVENTORY_H */

