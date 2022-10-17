/* 
 * File:   main.cpp
 * Author: Danielle Fernandez
 * Created on 9/27/22 @ PM
 * Purpose:  gaddis-9thEd_ch11_prb5_weatherStats
*/

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
enum Year { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

//Function Prototypes
struct Weather {
    
    float rain;     //total rainfall
    float hgTemp;    //high temperature
    float lwTemp;    //low temperature
    float avgTemp;  //average temperature
};

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variable Data Types and Constants
    int count=0;
    float sumAvgR,   //total rain accumulator
          sumAvgT,  // sum average temperature of each month
          maxTemp,  //maximum temperature
          minTemp;  //lowest temperature
    
    Year month; //loop counter for months with enum data type
    Weather wStat[DECEMBER+1]={};  //structure for each months weather statistics 
    
    //initialize Variables
    sumAvgR=sumAvgT=maxTemp=0.0f;
    minTemp=1000.0f;
   
    while(cin >> wStat[count].rain && count<11) {
        
        cout << "Enter the total rainfall for the month:" << endl;
        
        cout << "Enter the high temp:" << endl;
        cin >> wStat[count].hgTemp;
        
        cout << "Enter the low temp:" << endl;
        cin >> wStat[count].lwTemp;
       
        count++;
    }
    
    for(int i=JANUARY; i<count; i++){
        
        //checks for highest temperture in the year
        if(wStat[i].hgTemp>maxTemp) maxTemp=wStat[i].hgTemp;
        
        //checks for lowest temperature in the year
        if(wStat[i].lwTemp<minTemp) minTemp=wStat[i].lwTemp;
        
        //sums the rain from each month
        sumAvgR += wStat[i].rain;  //TC0==43.5
        
        //calculates average temp by adding the month's high & low temp and then dividing by 2
        wStat[i].avgTemp = (wStat[i].hgTemp + wStat[i].lwTemp)/2;
        
        //sums the average temp for all of the months
        sumAvgT += wStat[i].avgTemp;
    }
    
    //calculate average rainfall for the year
    sumAvgR /=count;   //TC0==43.5/6=7.25
    
    //calculate & set average temperature for the year
    sumAvgT /= count;
    
    //Display Outputs
    cout << fixed << setprecision(2)<<"Average monthly rainfall:" << sumAvgR << endl    //tc1
         << "High Temp:" << setprecision(0) << maxTemp << endl
         << "Low Temp:" << setprecision(0) << minTemp << endl
         << fixed << setprecision(1) << "Average Temp:" << sumAvgT; //tc2 
         
    //Exit stage right!
    return 0;
}