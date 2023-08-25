/*
 * Danielle Fernandez
 * 11-11-22 @11PM
 * Purpose: Gaddis_9thEd_ch13_prb4_retailItem_1
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <valarray>
using namespace std;

class Patient {
    private: 
        string name;    // full name
        string addy;    // address
        string phne;    // phone number
        string eC;      //emergency contact
    public:
        Patient(string,string,string,string);   // constructor
        string getName() const {return name;}   // accessor 
        string getAddy() const {return addy;}
        string getPhne() const {return phne;}
        string getEC() const {return eC;}
};

Patient::Patient(string n, string a, string p, string e){
    name=n;
    addy=a;
    phne=p;
    eC=e;
}

class Proced {
    private:
        string pName;   // procedure name
        string date;    // date of proceducure
        string drName;  // doctor's name
        float fee;      // charge for procedure
    public:
        Proced(string,string,string,float);     // constructor
        string getPName() const {return pName;}
        string getDate() const {return date;}
        string getDrName() const {return drName;}
        float  getFee() const {return fee;}
        float  getSum();
    
};

Proced::Proced(string p, string d, string dr, float f){
    pName=p;
    date=d;
    drName=dr;
    fee=f;
}

float Proced::getSum(){
    
}

int main() {    
  
    // Variables for Patient class
    string n = "Jane Doe";
    string a = "456 Willow Rd., Orange, CA 90011";
    string ph = "1-323-555-9999";
    string eC = "Jim Doe 1-555-123-4567";
  
    // Variables for Procedure class
    int size=3;
    string pName[size]={"Exam", "X-ray", "Blood test"};
    string date[size]={"11-11-2022", "11-12-2022","11-13-2022"};
    string dName[size]={"Dr. Irvine","Dr. Jameson", "Dr. Smith"};
    float charge[size]={250.00, 500.01, 200.02}; 
    float sum = 0;
   
    // create new object from Patient class
    Patient patient1(n,a,ph,eC);
    
    // create 3 new objects from Procedure class
    Proced proced1(pName[0],date[0],dName[0],charge[0]);
    Proced proced2(pName[1],date[1],dName[1],charge[1]);
    Proced proced3(pName[2],date[2],dName[2],charge[2]);
    
    // calculate total sum of all procedure fees
    sum = proced1.getFee() + proced2.getFee() + proced3.getFee();
    
    // Outputs
    // Patient info
    cout << "\n___________________________________________________\n";
    cout << "\t\t Patient Information\n";
    cout << "___________________________________________________\n";    
    cout << "Patient Name:      " << patient1.getName() << endl;
    cout << "Address:           " << patient1.getAddy() << endl;
    cout << "Phone:             " << patient1.getPhne() << endl;
    cout << "Emergency Contact: " << patient1.getEC() << endl;
    
    // Patient's procedure's
    cout << "\n______________________________________________________________________________________________________\n";
    cout << "Procedure #1 \t\t\t\t" << " Procedure #2 \t\t\t\t" << " Procedure #3" << endl;
    cout << "______________________________________________________________________________________________________\n";   
    cout << "Procedure Name: " << proced1.getPName() << "\t\t\t Procedure Name: " << proced2.getPName() << "\t\t\t Procedure Name: " << proced3.getPName() << endl;
    cout << "Date:           " << proced1.getDate() << "\t\t Date:           " << proced2.getDate() << "\t\t Date:           " << proced3.getDate() << endl;
    cout << "Practitioner:   " << proced1.getDrName() << "\t\t Practitioner:   " << proced2.getDrName() << "\t\t Practitioner:   " << proced3.getDrName() << endl;
    cout << fixed << setprecision(2) << "Charge:         " << proced1.getFee() << "\t\t\t Charge:         " << proced2.getFee() << "\t\t\t Charge:         " << proced3.getFee() << endl;
    cout << "Total charges:  " << sum << endl;
  
    return 0;
}