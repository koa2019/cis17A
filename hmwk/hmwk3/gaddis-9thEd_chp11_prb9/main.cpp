/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on 10/6/22 @10:20 PM
 * Purpose:  gaddis-9thEd_chp11_prb9_speakersBureau
*/

//System Libraries
#include <iostream>
#include <iomanip>
#include <string> // string
using namespace std;

//User Libraries
struct Bureau {    
    string name, //division's name: west north east south
           topic;  //speaking topic
    int    phNum;  // phone number
    float  fee;     //fee required 
};

//Function Prototypes
void getData(Bureau [], int &);
void dsplyData(const Bureau [],int);
void updateData(Bureau [],int);
void change1Struct(Bureau [],int);
void show1Struct(const Bureau [],int );


//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    char ch; //user input
    int size = 12,
        count = 0,
        find = 0;
    
    Bureau spk[size]={};    //declare an array with 12 structures
    
    //run menu
    do {
        cout << "\nMenu: \n"
             << "Enter 1 to add a new speaker to the database.\n"
             << "Enter 2 to view speaker's info\n"
             << "Enter 3 to change speaker's info in database\n"
             << "Q to Quit\n";
    
        cin >> ch;   
    
        switch(ch) {
            case '1': {
                //get user input to add new speaker to database
                getData(spk,count);   
                break;
            }
            case '2': {
                cout<<"\nSpeaker's Bureau Database\n";
                dsplyData(spk,count);
                break;
            } case '3': {            
                updateData(spk,find);
                break;
            } case 'Q':
              case 'q': {
                cout << "Goodbye";
                exit(0);
                break;
            } default: {
                cout << "Enter a valid number between 1-3.\n"; 
                ch='1';
            }
        }
     } while (ch<='3' && ch>='1');

    //Exit stage right!
    return 0;
}

void updateData(Bureau spk[],int find){
    
    cout << "Enter ID Number to update a Speaker's info\n";
    cin >> find;
    
    show1Struct(spk,find);      
    change1Struct(spk,find);        
}

//change 1 struct in array
void change1Struct(Bureau spk[],int find){
    cout << "Enter speaker's name\n";
        cin >> spk[find].name;
        
        cout << "Enter speaker's phone number\n";
        cin>>spk[find].phNum;
        
        cout << "Enter speaker's topic\n";
        cin >> spk[find].topic;
        
        cout << "Enter fee required\n";
        cin >> spk[find].fee;     
}

//show only struct in array
void show1Struct(const Bureau spk[],int find){
    cout<< "\nLocated Speaker #" << find << endl;
    cout << setw(4)<< "ID #" 
         <<setw(10) <<setfill(' ') << "Name"
         <<setw(9)<<"Phone"
         <<setw(10) << "Topic" 
         << setw(15) << "Required Fee" << endl;
    
    cout << spk[find].name << " "
         << spk[find].phNum << " "
         << spk[find].topic << " "
         << spk[find].fee << endl<<endl;
}

//display data
void dsplyData(const Bureau spk[],int count){
    
    cout<<endl;
    cout << setw(4)<< "ID #" 
                <<setw(8) <<setfill(' ') << "Name"
                <<setw(9)<<"Phone"
                <<setw(8) << "Topic" 
                << setw(15) << "Required Fee" << endl;
    
    for(int i=0;i<count;i++){       
        
        cout << setw(4) << i << " "
             << setw(8) << spk[i].name << " "
             << setw(9) << spk[i].phNum << " "
             << setw(8) << spk[i].topic << " "
             << setw(5) << spk[i].fee << endl;
    }  
    cout << endl;
}

//get user input to add new speaker to database
void getData(Bureau spk[], int &count){
    
    cout << "How many Speaker's would you like to add to the database?\n";
    cin >> count;
    
    for(int i=0;i<count;i++){
        
        cout << "Enter speaker's name\n";
        cin >> spk[i].name;
        
        cout << "Enter speaker's phone number\n";
        cin>>spk[i].phNum;
        
        cout << "Enter speaker's topic\n";
        cin >> spk[i].topic;
        
        cout << "Enter fee required\n";
        cin >> spk[i].fee;       
        
    }
    cout << endl;
}