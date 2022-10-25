/* 
 * File:   Customer.h
* Author: Danielle Fernandez
 * Created on October 24, 2022, 8:14 PM
 */

#include <string>

#ifndef CUSTOMER_H
#define CUSTOMER_H

struct Customer { //prb1
    
    string acct,
    name,
    addy;
    float begBal,
    *chks,
    *deps;
};

#endif /* CUSTOMER_H */

