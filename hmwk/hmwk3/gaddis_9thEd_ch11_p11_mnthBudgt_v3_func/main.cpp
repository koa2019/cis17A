/* 
* File: main.cpp
* Author: Danielle Fernandez
* Created on 9/28/22 8:10 PM
* Purpose:  gaddis_9thEd_ch11_prb11_monthBudget_v3
* passes tc 0 1 2
*/

//System Libraries
#include <iostream>
#include <string>   //string data type
#include <iomanip>  //fixed, setprecision()
using namespace std;

//User Libraries
struct Budgt {
    float rent; //monthly rent
    float utl; //utilities
    float hExp; //house expenses
    float trans; //transportation
    float food; //food
    float medic; //medical
    float insur; //insurance
    float entmnt; //entertainment
    float cloths; //clothes
    float misc; //miscellaneious
};

//Function Prototypes
void getData(Budgt&);
void sumBudgt(Budgt&, float&);
void dsplyRes(const Budgt,const Budgt,float,float);

//Execution Begins Here
int main(int argc, char** argv) {

    //Declare Variable Data Types and Constants
    float sum = 0,  //total user spent that month 
          bSum = 0; //total amount allotted for all monthly expenses
    
    //declare new structures
    Budgt bdgt = {500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00}; //holds how much is alotted for each category in a month
    Budgt spent; //declare new struct for how much was spent that month  
   
    //Initialize Variables
    getData(spent);
    
    //Process inputs
    sumBudgt(bdgt, bSum);
    sumBudgt(spent,sum);
    
    //outputs
    dsplyRes(bdgt,spent,bSum,sum);
  
    //Exit stage right!
    return 0;
}

/************FUNCTION DEFINITIONS**************/

//compare budget categories to what was actually spent and display results
void dsplyRes(const Budgt bud, const Budgt spnt, float bSum, float sum){
    
    string str = spnt.rent==bud.rent ? "Even" : 
                 spnt.rent>bud.rent ? "Over" : "Under";
    cout << "Housing " << str << endl;
   
    str = spnt.utl==bud.utl ? "Even" : 
          spnt.utl>bud.utl ? "Over" : "Under";
    cout << "Utilities " << str << endl;
    
    str = spnt.hExp==bud.hExp ? "Even" : 
          spnt.hExp>bud.hExp ? "Over" : "Under";
    cout << "Household Expenses " << str << endl;
    
    
    str = spnt.trans==bud.trans ? "Even" : 
          spnt.trans>bud.trans ? "Over" : "Under";
    cout << "Transportation " << str << endl;
    
    
    str = spnt.food==bud.food ? "Even" : 
          spnt.food>bud.food ? "Over" : "Under";
    cout << "Food " << str << endl;
    
    
    str = spnt.medic==bud.medic ? "Even" : 
          spnt.medic>bud.medic ? "Over" : "Under";
    cout << "Medical " << str << endl;
    
    
    str = spnt.insur==bud.insur ? "Even" : 
          spnt.insur>bud.insur ? "Over" : "Under";
    cout << "Insurance " << str << endl;
    
    
    str = spnt.entmnt==bud.entmnt ? "Even" : 
          spnt.entmnt>bud.entmnt ? "Over" : "Under";
    cout << "Entertainment " << str << endl;
    
    str = spnt.cloths==bud.cloths ? "Even" : 
          spnt.cloths>bud.cloths ? "Over" : "Under";
    cout << "Clothing " << str << endl;
    
    
    str = spnt.misc==bud.misc ? "Even" : 
          spnt.misc>bud.misc ? "Over" : "Under";
    cout << "Miscellaneous " << str << endl;
    
    float diff = bSum-sum;
    //cout << "diff= "<<diff<<endl;
    
    cout <<fixed<<setprecision(2);
    
    if(diff>=0 && diff<bSum) cout << "You were $" << diff << " under budget";
    
    else if(diff<0) cout << "You were $" << sum-bSum << " over budget";//tc2
    
    else cout << "You were $" << diff << " even budget";
}


//calculate sum of the total allotted budget
void sumBudgt(Budgt &bdgt, float &sum) {
    sum += bdgt.rent;
    sum += bdgt.utl;
    sum += bdgt.hExp;
    sum += bdgt.trans;
    sum += bdgt.food;
    sum += bdgt.medic;
    sum += bdgt.insur;
    sum += bdgt.entmnt;
    sum += bdgt.cloths;
    sum += bdgt.misc;
}

//read user inputs. Return struct & sum
void getData(Budgt &spent) {
    
    cout<<"Enter housing cost for the month:$"<<endl;
    cin >> spent.rent;
    cout<<"Enter utilities cost for the month:$"<<endl;
    cin >> spent.utl;
    cout<<"Enter household expenses cost for the month:$"<<endl;
    cin >> spent.hExp;
    cout<<"Enter transportation cost for the month:$"<<endl;
    cin >> spent.trans;
    cout<<"Enter food cost for the month:$"<<endl;
    cin >> spent.food;
    cout<<"Enter medical cost for the month:$"<<endl;
    cin >> spent.medic;
    cout<<"Enter insurance cost for the month:$"<<endl;
    cin >> spent.insur;
    cout<<"Enter entertainment cost for the month:$"<<endl;
    cin >> spent.entmnt;
    cout<<"Enter clothing cost for the month:$"<<endl;
    cin >> spent.cloths;
    cout<<"Enter miscellaneous cost for the month:$"<<endl;
    cin >> spent.misc;
}