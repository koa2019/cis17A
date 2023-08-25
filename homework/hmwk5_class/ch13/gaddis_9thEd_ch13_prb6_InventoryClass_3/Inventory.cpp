#include "Inventory.h"

Inventory::Inventory(){ // default constructor
    itemNum=0;
    quant=0;
    cost=0.0f;
    ttlCost=0.0f;
}

// constructor #2
Inventory::Inventory(int i, int q, float c, float t){
    setItemNum(i);   
    setQuant(q);
    setCost(c);
    setTtlCost();
}

// Calculates total inventory cost for the item (quantity times cost) 
// and stores the result in ttlCost
void Inventory::setTtlCost(){
     ttlCost = cost*quant;
}

// copy to itemNum member
void Inventory::setItemNum(int i){
    itemNum = i;
}

// copy to quant member
void Inventory::setQuant(int q){
    quant = q;
}

// copy to cost member
void Inventory::setCost(float c){
    cost = c;
}
