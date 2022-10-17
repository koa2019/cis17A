/* 
*Danielle Fernandez
* 9/14/22
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
   v1 passes tc 0
 * v2 passes tc 1
 * v3 gets rid of strings and compares as char [][]
 * v4 works & still passes tc 0,1
   v5: not working
   v6:notworking
   v7: passes tc 0,1. added getAscii() and printAscii(). call getAscii() in main()
       sort() compares the last column of each array's row to the new ASCII and sort them in order from small to big
       added a colSize counter for the find() in sort().
       added conditional for when colDet is less than colIn
       changed ascii range to 32-122
    v8: passes all test cases! by cleaning up repeated code and un-necessary code.
        tc 1 & 2 were related to if(ii<i2){}
        tc 2 test input: 
            123 
            abc
            3 
            3 
            355
            132
            23b
        expected output:
            132
            23b
            355
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
#include <cctype>
#include <string>
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=100;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[],char []);
void print(const char [][COLMAX],int,int);
void prntAsci(char []); //mine
void getAscii(char [],char [],const char [],const char []);
int strcmp(char [][COLMAX],char [],char [],const char [],const char [],string &);//Replace sort order


//Program Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX]={},with[COLMAX]={},//New sort order
         asci[COLMAX]={}, augA[COLMAX]={},
         ch[COLMAX]={};
    string str=" ";     
         
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    // cout<<endl<<replace<<endl<<endl;
    cout<<"With the following characters"<<endl;
    cin>>with;
    //   cout<<endl<<with<<endl<<endl;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    //cout<<replace<<endl<<with<<endl<<rowIn<<endl<<colIn<<endl;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
   
    // cout<<"   rowIn= "<<rowIn <<"  rowDet="<<rowDet<<endl;
    // cout<<"   colIn= "<<colIn <<"  colDet="<<colDet<<endl;
    // print(array,rowIn,colIn);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        getAscii(asci,augA,replace,with);
        sort(array,rowIn,colIn,replace,with,augA);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }
    else if(rowIn!=rowDet || rowIn<rowDet ||rowIn>rowDet) cout <<"rowIn does NOT equal rowDet"<<endl;
    else if(colIn!=colDet || colIn>colDet || colIn<colDet) cout <<"colIn does NOT equal colDet"<<endl;
    else cout<<"Column or row input did not match"<<endl;
    
    //Exit
    return 0;
}

// compare and then sort 2D[][] from small to big based on augmented ascii table
void sort(char array[][COLMAX],int rowIn,int colIn,const char replace[],const char with[],
          char augA[]){
    
   
    int maxEle,row,num=0,ii,i2,last=rowIn-1,cSize=0;
    char ch[0]={},ch2[0]={};
    string newA;
    bool swp=false;
    
    newA=augA;  // initialize string to char[] value
    
    //  print(array,rowIn,colIn);
    
    // start at the last indx in array to the 2nd indx. starts at[last,1]
    for(maxEle=last; maxEle>0;maxEle--){
        //cout<<"max "<<maxEle<<endl;
        
        for(row=0;row<maxEle;row++){ // starts at [0,maxEle]
           
            
            // cout<<array[row]<<" vs "<<array[row+1]<<endl;
            
            cSize=0;// set column counter
            while(cSize<colIn){// loop through every index within the row
                
                ii=newA.find(array[row][cSize]);// find its index in augmented Ascii
                ch[0]=       array[row][cSize]; // c-string reference 
                i2=newA.find(array[row+1][cSize]);// find its index in augmented Ascii
                ch2[0]=      array[row+1][cSize]; // c-string reference 
                // cout<<"ch="<<ch[0]<<"  "<<ii <<" vs "<<i2<<"  "<<ch2[0]<<" ???"<< endl;
                
                // replaces strcmp() because we're basing it off the augmented ascii indices 
                if(ii>i2) num=1;// if ii is after i2 in augmented Ascii[], then return positive
                else if(ii<i2) num=-1;// if ii is before i2 in augmented Ascii[], then return negative
                else num=0; // ii==i2
                
                // if compare if/else if/else conditional returned positive, then swap neighboring array rows
                if(num==1){
                    // cout<<"swapping "<<ii<<" & "<< i2<<endl;
                    swap(array[row],array[row+1]);
                    //print(array,rowIn,colIn);
                    //cout<<endl;
                    cSize=colIn;    // reset column size value to max, so it stops while() 
                } 
                
                // related to test case 1 & 2. Noticed a pattern when cout at this point
                // cout<<ii << " "<<i2<<endl;
                if(ii<i2){
                     // cout<<"hit\n";
                    cSize=colIn;    // reset column size value to max, so it stops while() 
                }
                else cSize++;  // keeps looping through arrays row's columns
                //cout<<"colsize "<<cSize<<endl;
            }// end of while()
        }
    }
}//end of Function

// create ascii table and then create a new augmented ascii table based on user input
void getAscii(char asci[],char augA[],const char replace[],const char with[]){    
    
    char   temp[COLMAX]={};
    int    start=33, // 33 represents ! point in ascii
           z=127, // 127==DEL in ascii
           range,  // range of 1st character I'm starting at and last char in ascii
           rplIndx=0,  // replace[] index 
           wthIndx=0;  //with[] index 
    string aStr,    // will hold ascii table values
           newA;    // will hold new augmented ascii table
    
    range=(z-start)+1;// augmented Ascii range= [!,DEL]
    //cout<<"range"<<range<<endl;
    
    // initialize char [] with ascii values from '!'==33 to DEL==127
    for(int i=0,cnt=start;i<range;i++,cnt++){
        asci[i]=cnt;    
        //cout<<asci[i];
    }
    //prntAsci(asci);
    
    //initialize aug array with asci array values
    strcpy(augA,asci);    
    //cout<<endl<<"OG ";
    //prntAsci(augA,range);
    
    // initialize strings with char[] 
    aStr=asci;
    newA=augA;
    
    //loop [33,127]. find and replace indx
    for(int indx=0;indx<strlen(with);indx++){
        
        // reassign string value each time, so rplInx references the latest updated version of augA[]
        newA=augA;
        
        // find index location in newA for each array's index
        rplIndx=newA.find(replace[indx]);   // return index of search value
        wthIndx=newA.find(with[indx]);        
        
        // cout<<"\nnew acsii starting\nrplIndx  "<<rplIndx<<endl;
        // cout<<"wthIndx  "<<wthIndx<<" swapping....."<<endl;  
        
        swap(augA[rplIndx],augA[wthIndx]);  // swap array indices within the same array using values from replace[] & with[]
        // prntAsci(augA);   //print char[]   
    }      
    //cout<<endl<<"New ";
    //prntAsci(augA);//print char[]    
}//end of function

// print ascii runs from values [33,127]
void prntAsci(char arr[]){
    
    int size=strlen(arr); 
    //cout<<"size"<<size<<endl;
    
    for(int r=0;r<size;r++){
        cout<<arr[r];
    }
    cout<<endl;
}

//Print the sorted 2-D array
void print(const char arr[][COLMAX],int row,int col){
   
    for(int r=0;r<row;r++){
        cout<<arr[r]<<endl;
    }
}

//Outputs row and columns detected from input
int read(char arr[][COLMAX],int &rowDet){
    
   //cout<<"rowDet "<<row<<endl;
   int colDet=0,rMax=0, colMax=0,rCount=0,size;//declare & initialize variables 
   
   
    while(cin>>arr[rCount]){ // read in from code-e until reads null determinor from file
      
       size=strlen(arr[rCount]);
       //cout << arr[rCount]<<" strlen["<<rCount<<"] "<<size<<endl;
       
       colMax = size>colMax ? size : colMax; //set maximum column by comaring each rows length as you read in
       
       rCount++;    // increment row count
       rMax=rCount>rMax? rCount : rMax; // set row max to largest row count
   } 
   rowDet=rMax; // reasign rowDetected value to row max 
   colDet=colMax; // set column detected value to column max
   //cout<<"() rowDet "<<rowDet<<" colDet "<<colDet<<endl;
   return colDet;
}

//couldn't get this darn thing to work
int strcmp1(char array[][COLMAX], char ch[],char augA[],char replace[],char with[],string &str){
    cout<<"hit strcmp";
}// end of Function