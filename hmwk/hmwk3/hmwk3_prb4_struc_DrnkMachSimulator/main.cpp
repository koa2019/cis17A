/*
   Danielle Fernandez
   10/02/22 @8 PM
   structure_Drink_Machine_Simulator
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Machine {
    string name;
    float price;
    int numDrk;
};

//function protoypes
void showMenu(Machine [],int);
void getMoney(int&);

int main(){

    bool   quit=false;    //set flag
    int    size=5,     // number of drinks in the vending machine struct
           num,        // user input to represent how much money they're putting in the machine
           change=0,   //change due to user
           profit=0;   // accumulae profit
    string str;     //user drink choice
   
    //declare & initialize a new array with 5 structs 
    Machine mach[size] =     
                    {   {"Cola", 75, 20},
                        {"Root Beer", 75, 20},
                        {"Lemon-Lime", 75, 20},
                        {"Grape Soda", 80, 20},
                        {"Cream Soda", 80, 20}
                    };
                    
    
    do { 
        
        //show vending machine menu of drinks
        showMenu(mach,size);
        
        //read in user inputs
        getline(cin,str);   
        
        //user validation. Input Can not be negative or more than a dollar
        getMoney(num);
        
        //cout << "str=" << str << " num=" << num << endl;
        
        //loop through mach array
        for(int i=0;i<size;i++){
            
            //check if user wants to quit
            if(str[0]=='Q') quit=true;
            
            else if(str==mach[i].name){
                
                //if choosen drink is out of stock, then display message & reset flag
                if(mach[i].numDrk<=0){
                    cout << mach[i].name << " is sold out.\n";
                    quit=true;  //reset flag
                }
                
                profit += mach[i].price;    //calculate profit by adding the price of each drink that is bought
                
                mach[i].numDrk--;           //decreament number of drinks each time it is bought
                
                change = num-mach[i].price; //calculate change due to user
                
                cout << change << endl;     //display change due
                
                cin.ignore();   //cleaar\0 for the next getline() cin in
            } 
            else cout<<"";
        }
        
    } while(!quit); //keep looping until quit==true
    
    //display profit after user input's "Quit"
    cout << profit << endl;
   
	return 0;
}

/**********FUNCTION DEFINITIONS************/

//user validation. Input Can not be negative or more than a dollar
void getMoney(int &num){
    
    do{
        cin >> num;
    } while (num<0 || num>100);
}

//show vending machine menu
void showMenu(Machine mach[],int size){
    
    for(int i=0;i<size;i++){
       
        cout << setw(11) << left << mach[i].name << setfill(' ')
             << setw(4)  <<  mach[i].price  
             << setw(2)  << mach[i].numDrk << endl;
                      
        if(i==size-1) cout << "Quit" << endl;
    }
}