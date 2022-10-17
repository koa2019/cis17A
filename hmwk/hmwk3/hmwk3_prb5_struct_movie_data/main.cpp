/*
Danielle Fernandez
10-5-22 @8:330 _Pragmam
hmwwk3_struct_weatherStats
*/

#include <iostream>
#include <string> //string
#include <iomanip> //setprecision()
using namespace std;

struct Weather {
    
    string month;
    float totRain,  //total rain in inches
          hiTemp,   // high temperature in Fahrenheit
          loTemp,   // low temperature in Fahrenheit
          avgTemp;  //averaage temperature in Fahrenheit
};

int main(){
	
	//declare variables
	int size = 12;  //number of months
	float sum = 0.0f;   //total rainfall accumlator
	
	//declare & initialize new array of structures
	Weather arr[size]={};
	
	//read in user inputs
	for(int i=0;i<size;i++){
	    
	    cin>>arr[i].month >> arr[i].totRain;
	    
	    do {    //user validation for Fahrenheit. range is [-110,140]
	        cin >> arr[i].loTemp;
	    } while(arr[i].loTemp<= -110 && arr[i].loTemp <= 140);
	    
	    do {//user validation for Fahrenheit. range is [-110,140]
	        cin >> arr[i].hiTemp;
	    } while(arr[i].hiTemp<= -110 && arr[i].hiTemp <= 140);
	}
	
	//declare &initialize variables to hold a starting point for comparinng lowest and highest temperature months
	string minMon, maxMon;
	minMon=maxMon=arr[0].month;
	
	//set mixn and max temps to the first element in array struct
	int min, max;
	min=arr[0].loTemp;
	max=arr[0].hiTemp;
    
    float avgTemp=0; //avg temperature accummulator
    
	//process array contents 
	for(int i=0;i<size;i++){
	    
	    sum += arr[i].totRain;  // adds each months total Rainfall
	    
	    avgTemp += (arr[i].loTemp + arr[i].hiTemp)/2;   //sums the months lowest & highest temp, divides by 2 and adds it to the avgTemp accummulator
	    
	    //condition checks for the lowest Temperature month
	    if(arr[i].loTemp < min) {
	        min = arr[i].loTemp;
	        minMon = arr[i].month;
	    }
	    
	     //condition checks for the highestest Temperature month
	    if(arr[i].hiTemp > max) {
	        max = arr[i].hiTemp;
	        maxMon = arr[i].month;
	    }
	   
	}
	
	sum /=size;     //calculate average rainfall for the year
	avgTemp /=size;  //calculates average Temperature for the year

    //display results
	cout << fixed << setprecision(1) << "Average Rainfall " << sum << " inches/month"<< endl
	     << "Lowest  Temperature " << minMon << "  " << min << " Degrees Fahrenheit" << endl
	     << "Highest Temperature " << maxMon << "  " << max << " Degrees Fahrenheit" << endl
	     << setprecision(0) << "Average Temperature for the year " << avgTemp << " Degrees Fahrenheit" << endl;
	
	return 0;
}