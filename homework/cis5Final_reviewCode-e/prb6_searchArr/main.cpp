/* 
 * Danielle Fernandez
 * 9/14/22
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 *  Tc 0 & 3 coutput: None 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int [],int &);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int [],int); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE],indx=0;                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match,indx);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match,indx);
    
    //Exit
    return 0;
}

int  srch1(const char [],const char [],int){
    
}
void srchAll(const char snt[],const char pat[],int match[],int &indx){
        
    int pLen=strlen(pat);
    int sLen=strlen(snt);
 
    for(int i=0;i<sLen;i++){
        
       if(snt[i]==pat[0]){
           //cout<<"found it!\n";
           match[indx]=i;
           indx++;
        }
        else match[indx]=-1;
    }
}

void print(const char chArr[]){
    cout << chArr <<endl;
}

void print(const int match[],int indx){
    
    int size= sizeof(match)/ sizeof(match[0]);
   
    if(match[0]==-1) cout << "None"<<endl;
    else {
        for(int i=0;i<indx;i++)
        cout << match[i]<<endl;
    }
}