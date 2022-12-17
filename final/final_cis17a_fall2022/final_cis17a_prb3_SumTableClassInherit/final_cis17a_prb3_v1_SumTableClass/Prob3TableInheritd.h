/* 
 * File:   Prob3TableInheritd.h
 * Author: DanYell
 * Created on December 10, 2022, 2:47 PM
 * 
 * Prob3TableInheritd class inherits Table class.
 * Prob3TableInheritd is derived/child class.
 * Table class is base/parent class
 */

#ifndef PROB3TABLEINHERITD_H
#define PROB3TABLEINHERITD_H
#include "Table.h"  // base class
using namespace std;


//template<class T>
//class Prob3TableInheritd:public Table<T> {
class Prob3TableInheritd : public Table {
    
protected:
    int *augTable;    
public:
    Prob3TableInheritd(int,int); //Default Constructor
    ~Prob3TableInheritd() {delete [] augTable;}; //Destructor
    const int *getAugTable(void){return augTable;};
};

//*********************************
//    Default Constructor
//*********************************
Prob3TableInheritd(int row,int col){
    
    augTable = Table(row,col);
    
}
#endif /* PROB3TABLEINHERITD_H */

