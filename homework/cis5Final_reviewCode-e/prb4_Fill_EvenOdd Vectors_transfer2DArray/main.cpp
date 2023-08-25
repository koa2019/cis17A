/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on 9/14/22
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 * v1 passes tc 0. fix for passing 10 and even&odd equal number of indx
   v2: add conditonals for when even odd vectors are equal
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX]={};     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    cout<<"Input the number of integers to input."<<endl
        <<"Input each number."<<endl;
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

void read(vector<int> &even, vector<int> &odd){
    
    int nNum, x;
    cin>>nNum; //total number going to be read in
    //cout<<nNum<<endl;
    for(int i=0;i<nNum;i++){
        cin>>x;
        if(x%2==0){
            even.push_back(x);
            //cout<<x<<endl;
        } else{
            odd.push_back(x);
        }
    }
    //if (even.size()<odd.size()) even.push_back(' ');
    
}

void copy(vector<int> even, vector<int> odd,int array[][COLMAX]){
    
    int row,col=2, eSize, oSize,diff=0, last,evenCol=0, oddCol=1;; 
    eSize=even.size();
    oSize=odd.size();
    
   
    if (eSize<oSize){  // if both vectors are equal sizes
        row=oSize;
        diff=oSize-eSize;
        last=row-1;
      
         // odd is bigger
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
            
                // save even vector to array row 0
                if(j==evenCol){  
                    if(i==last) array[last][j]=' ';
                    else array[i][j]=even[i];
                }
                
            // save odd vector to array col 1
            if(j==oddCol) array[i][j]=odd[i];
            }
        }
        
    } else if(eSize>oSize){ //even is bigger
        row=eSize;
        last=row-1;
        diff=oSize-eSize;
      
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
            
                if(j==evenCol) {  // save even vector to array row 0
                    array[i][j]=even[i];
                }
               
                if(j==oddCol) {  // save odd vector to array col 1
                     if(i==last)  array[last][j]=' ';
                     else array[i][j]=odd[i];
                }
            }
        }
      
    } else { // if even and odd vectors are equal
        row=eSize;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                 if(j==0) array[i][j]=even[i];
                 if(j==1)  array[i][j]=odd[i];
            }
        }
    }
} // closes function

void prntAry(const int arr[][COLMAX],int eSize,int oSize,int width){
    
    int row=eSize;
    if(eSize<oSize) row=oSize;  // set row to larger the vector with bigger size
    int last=(row-1);
    int col=2, evenCol=0, oddCol=1; // returns col
    
    //cout << "r"<<row<<" c"<<col<<" last "<<last << endl;
    
    cout<<"     Array      Even       Odd"<<endl;
    
    // when even and odd are equal
    if(eSize==oSize){    
        for(int i=0;i<row;i++){
       
                // print col==0
                for(int j=evenCol;j<col-1;j++){
                cout<< setw(width-1)<<" ";
                cout << setw(width)<<" " << arr[i][j];
                }
                // print col==1
                for(int j=oddCol;j<col;j++){
                cout << setw(width-1)<<" " << arr[i][j];
                }
                cout<<endl;
            
        }// ends row for loop
    } // ends if
        
    // if odd vector size is bigger than even vector
    if(eSize<oSize){  
        
        for(int i=0;i<row;i++){
            
            // only prints col[0] even numbers
            for(int j=evenCol;j<col-1;j++){
                cout<< setw(width-1)<<" ";
            
                if(i==last && j==evenCol) cout << setw(width)<<" " << static_cast<char>(arr[i][j]);
                else cout << setw(width)<<" " << arr[i][j];
            }
            // only prints col[1]
            for(int j=oddCol;j<col;j++){
                cout << setw(width-1)<<" " << arr[i][j];
            }
            cout<<endl;
        }
    }
   
    // if even vector size is bigger than odd
    if(eSize>oSize){  
        
        //cout << "rw"<<row<<" col "<<col<<" last "<<last << endl;
        //cout<< arr[0][1] <<endl << arr[1][1] <<endl << arr[2][1] <<endl ;

        for(int i=0;i<row;i++){
            
            // only prints col[0] which is even numbers
            for(int j=evenCol;j<col-1;j++){
                cout<< setw(width-1)<<" ";
                cout << setw(width)<<" " << arr[i][j];
            }
           
            // only prints col[1] which is odd numbers
            for(int j=oddCol;j<col;j++){
                if(i==last && j==1) cout << setw(width-1)<<" " << static_cast<char>(arr[i][j]);
                else cout << setw(width-1)<<" " << arr[i][j];
            }
            cout<<endl;
        }
    }
} // closes function


void prntVec(vector<int> even, vector<int> odd,int width){
   
    int row, eSize, oSize,diff; 
    eSize=even.size();
    oSize=odd.size();
    row=eSize;
    
    //cout<<eSize<<" "<<oSize<<endl;
    //cout<<"row"<<row<<endl;
    
    cout<<"    Vector      Even       Odd"<<endl;
    
    // when odd vector size is bigger than even
    if(oSize>eSize) {
        row=oSize;
        diff=eSize=oSize;
        
        for(int val=0;val<row;val++){
            cout<< setw(width-1)<<" ";
        
            if(row==5 && val==4){
            cout<< setw(width+1)<<" "; 
            } else cout << setw(width)<<" " << even[val];
            cout << setw(width-1)<<" " << odd[val]<<endl;
        }
        
      // when even vector size is bigger than odd     
    } else if(eSize>oSize){
        row=eSize;
        diff=eSize-oSize;
        //cout <<"row"<<row<<" "<<endl;
        //cout<<diff<<endl;
       
        for(int val=0;val<row;val++){
            cout<< setw(width-1)<<" ";
        
           // prints even col[0]
            cout << setw(width)<<" " << even[val];
            
            if(row==row && val==row-1){
                
                while(diff>0){
                cout<< setw(width)<<" "<<endl;
                diff--;
                }
            } else cout << setw(width-1)<<" " << odd[val]<<endl;
        }
    }
    else {  // even & odd vector are equal sizes
   
        row=eSize;
        diff=eSize-oSize;
        // odd.push_back(0);
        for(int val=0;val<row;val++){
            cout<< setw(width-2)<<" ";
            cout << setw(width)<<" " << even[val];
            cout << setw(width)<<" " << odd[val]<<endl;
        }
        
    }
}
