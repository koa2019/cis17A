/*
   Danielle Fernandez
   10/02/22 @11 PM
   structure_movie_data
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct MovieData {
    
    string title,
           dir,
           yr,
           mins;
};

//function protoypes
void getData(MovieData [],int);
void displayArr(MovieData [],int);

int main(){
	
	int numMov;
	
	cout << "This program reviews structures" << endl
         << "Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)." << endl << endl;
         
	
	cin >> numMov;
	
	//create new array of struct
	MovieData movies[numMov];
	
	//initialize array with movie info
	getData(movies, numMov);
	
	//display array of struct
	displayArr(movies,numMov);
	
	return 0;
}

/**********FUNCTION DEFINITIONS**************/

//get user input and save to stuct in array
void getData(MovieData movies[], int numMov){
    
    cin.ignore();
    
    for(int i=0;i<numMov;i++){
        
        getline(cin,movies[i].title);
        getline(cin,movies[i].dir);
        cin>>movies[i].yr;
        cin.ignore();
        cin>>movies[i].mins;
        cin.ignore();
    }
}
	
//display array of struct
void displayArr(MovieData movies[],int numMov){
    
	for(int i=0;i<numMov;i++){
        cout << left 
        << setw(11) << "Title:"    << movies[i].title << endl
        << setw(11) << "Director:" << movies[i].dir << endl
        << setw(11) << "Year:"     << movies[i].yr << endl
        << setw(11) << "Length:"   << movies[i].mins << endl;
        
        if(i!=numMov-1) cout << endl;
        
    } 
}