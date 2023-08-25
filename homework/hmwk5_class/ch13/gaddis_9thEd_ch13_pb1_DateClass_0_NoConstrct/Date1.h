/* 
 * File:   Date1.h
 * Author: Danielle Fernandez*
 * Created: November 9, 2022, 11:28 PM
*/

#ifndef DATE1_H
#define DATE1_H

class Date1 {
public:
    
    //void setString1(string str="");
    void setMonth1(int m = 0);
    void setDay1(int d = 0);
    void setYear1(int y = 0);
    //string getStr1() {return monStr1;}
    int getMonth1() const {return month1;}
    int getDay1() const { return day1;}
    int getYear1() const { return year1;}
    void formatUS1(int, int, int);
    void formatEU1(int, int, int);
private:
    //string monStr1;
    int month1;
    int day1;
    int year1;

};

#endif /* DATE1_H */

