//User Libraries
#include "Prb5Employee.h"
//#include "Employee.h"
//System Libraries
#include <cstring>  //strcat
#include <string>
#include <iostream>   //Input/Output Library

using namespace std;  //STD Name-space where Library is compiled


// function sets this class's member variables and it's parent class member variables
void Prb5Employee::setWrkr(char nme[],char jTitle[],float hrRate){
    for(int i=0;i<20;i++){
        name[i] = nme[i];
    }
    for(int i=0;i<20;i++){
        jobTitle[i] = jTitle[i];
    }
    hourlyRate=setHourlyRate(hrRate);
    hrsWrkd=0;
    grossPay=0;
    netPay=0;    
}

 // CalculatePay(Mark.setHourlyRate(20.0),Mark.setHrsWrkd(25));
float Prb5Employee::CalculatePay(float x,int y){
    hourlyRate = setHourlyRate(x);
    hrsWrkd = setHrsWrkd(y);
    grossPay = getGrossPay(hourlyRate,hrsWrkd);
    netPay = getNetPay(grossPay);
    return netPay;
}

float Prb5Employee::getGrossPay(float hrRate, int hrWrkd){
    
    float regPay = 0, ovrTme=0, dblTime=0;
    
    if(hrWrkd<=40) {
        return hrRate*hrWrkd;
    }
    else if(hrWrkd>40 && hrWrkd<=50) {
        regPay = hrRate*40;
        ovrTme = (hrRate*1.5)*(hrWrkd-40);
        return regPay+ovrTme;
    }
    else if(hrWrkd>50) {
        regPay = hrRate*40;
        ovrTme = (hrRate*1.5)*(10);
        dblTime = (hrRate*2.0)*(hrWrkd-50);    
        return regPay+ovrTme+dblTime;
    }
    else { return 0;}
}

float Prb5Employee::getNetPay(float gPay){ 
    double tx = Tax(gPay);
    float net = gPay-tx;
    return net;
}

double Prb5Employee::Tax(float gPay){
    double tax1 = 0,tax2=0,tax3=0;
    
    if(gPay<=500){
        tax1 = gPay*.1f; 
        return tax1;
    }    
    else if(gPay<=1000 && gPay>500){
        tax1 = (500)*.1f;
        tax2 = (gPay-500)*.2f; 
        return tax1+tax2;
    }
    else if(gPay>1000){
        tax1 = (500)*.1f;
        tax2 = (500)*.2f;
        tax3 = (gPay-1000)*.3f; 
        return tax1+tax2+tax3;
    } 
    else {return 0;}
}


float Prb5Employee::setHourlyRate(float pay){
    if(pay>0 && pay<200.00){
         return pay;
    } else {
         cout<<"Unacceptable Hourly Rate\n";
         return 0.0f;         
    }     
}

int Prb5Employee::setHrsWrkd(int hr){
     if(hr>0 && hr<84)
         { return hr; } 
     else {    
      cout<<"Unacceptable Hours Worked\n";
      return 0;
     }
}

char *Prb5Employee::toString(){ 
    string str="\nEmployee:        ";   
    str.append(name)
       .append("\nJob Title:       ").append(jobTitle)
       .append("\nHourly Pay Rate: ").append(to_string(hourlyRate))
       .append("\nHours Worked:    ").append(to_string(hrsWrkd))
       .append("\nGross Pay:       ").append(to_string(grossPay))
       .append("\nNet Pay:         ").append(to_string(netPay));
    
    //cout<<str<<" length="<<str.length()<<endl<<endl;
    
    char *chArry = new char[str.length()+1];
    for(int i=0; i<(str.length()+1); i++){
        chArry[i]=str[i];
    }    
    return chArry;  
}