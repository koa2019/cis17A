/* 
 * File:   
 * Author: 
 * Created on 9/28/22 8:10 PM
 * Purpose:  gaddis_9thEd_ch11_prb11_monthBudget_v1
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
struct Budgt {
    
    float rent;     //monthly rent
    float utl;      //utilities
    float hExp;   //house expenses
    float trans;   //transportation
    float food;     //food
    float medic;    //medical
    float insur;    //insurance
    float entmnt;   //entertainment
    float cloths;   //clothes
    float misc;     //miscellaneious
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Budgt bdgt = {500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00};  //declare a new struct to hold how much is alotted for each category
    Budgt spent;  //declare new struct for how much was spent that month  
    int count=0;    // counter for Number of Inputs
    float sum=0,
          bSum=0;
    
    //Initialize Variables
    
        
        bSum+=bdgt.rent;
        bSum+=bdgt.utl;
        bSum+=bdgt.hExp;
        bSum+=bdgt.trans;
        bSum+=bdgt.food; 
        bSum+=bdgt.medic;
        bSum+=bdgt.insur;
        bSum+=bdgt.entmnt;
        bSum+=bdgt.cloths; 
        bSum+=bdgt.misc; 
        cout << "Total budget allotted = " << bSum << endl;
        
        
        cin >> spent.rent;
        sum+=spent.rent;
        
        cin >> spent.utl;
        sum+=spent.utl;
         
         
        cin >> spent.hExp;
        sum+=spent.hExp;
       
         
        cin >> spent.trans;
        sum+=spent.trans;
        
         
        cin >> spent.food;
        sum+=spent.food;
       
        
        cin >> spent.medic;
        sum+=spent.medic;
        
         
        cin >> spent.insur;
        sum+=spent.insur;
        
         
        cin >> spent.entmnt;
        sum+=spent.entmnt;
        
         
        cin >> spent.cloths; 
        sum+=spent.cloths;
         
         
        cin >> spent.misc;
        sum+=spent.misc;
        
         
        cout <<"total spent this month = " << sum << endl;
        cout << "bSUm - sum = "<< bSum-sum << endl;
        
    for(int i=0;i<10; i++){
        
        //cout << spent.rent<<endl;
    }
    
    //Process or map Inputs to Outputs
    
    //Display Outputs

    //Exit stage right!
    return 0;
}