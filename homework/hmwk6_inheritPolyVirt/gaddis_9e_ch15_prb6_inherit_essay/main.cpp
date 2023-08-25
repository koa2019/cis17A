/* 
 * File:    main.cpp
 * Author:  Danielle Fernandez
 * Created: 11-11-2022 @ 2:36 PM
 * Purpose:  Gaddis_9thEd_ch15_prb6_inherit_essayClass
 * 
 *          Essay class is derived from GradedActivity class.
 *          Essay determines grade a student receives on an essay.
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Essay.h"


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
   
    
    //Declare & initialize Essay objects
    Essay essay1;
    Essay essay2(29,19,19,29);
    Essay essay3(19,18,12,17);
    
    //Display the results
    cout<<"\tStudent 1\n";
    essay1.showEssay();
    cout<<"\n\tStudent 2\n";
    essay2.showEssay();
    cout<<"\n\tStudent 3\n";
    essay3.showEssay();
    
    return 0;
}